"""
run_sanitizers.py
=================
Recompile generated C++ with AddressSanitizer + UndefinedBehaviorSanitizer,
re-run all test cases, and record which sanitizer errors are triggered.

This provides dynamic ground-truth for vulnerability characterization:
static-analysis warnings (cppcheck / clang-tidy) can be cross-referenced
against confirmed runtime errors detected by the sanitizers.

Usage:
    python scripts/run_sanitizers.py --mode full --jobs 8 --only all
    python scripts/run_sanitizers.py --mode demo --jobs 4

Output per program:  analysis/sanitizers/{model}/{gen}/{batch}/{file}.json
"""

import os
import re
import json
import argparse
import subprocess
from functools import lru_cache
from concurrent.futures import ProcessPoolExecutor, as_completed

# Sanitizer builds are slower; give more headroom
TIMEOUT = 30

HUMAN_SOLNS = ["soln1", "soln2"]
MODELS = ["gemma", "llama", "qwen"]
GENS = ["gen_1", "gen_2", "gen_3"]

# Compile flags
CXX = "g++"
SANITIZER_COMPILE_FLAGS = [
    "-std=c++17",
    "-O1",                        # -O1 keeps frames readable for ASan
    "-g",                         # debug info for useful stack traces
    "-fsanitize=address,undefined",
    "-fno-sanitize-recover=all",  # abort on first error (clear signal)
    "-fno-omit-frame-pointer",
]

# Runtime environment for sanitized binaries
SANITIZER_ENV = {
    **os.environ,
    "ASAN_OPTIONS": "detect_leaks=0:halt_on_error=1:print_legend=0",
    "UBSAN_OPTIONS": "halt_on_error=1:print_stacktrace=0",
}

# Map sanitizer error strings to CWE IDs
SANITIZER_CWE_MAP = {
    # ASan
    "heap-buffer-overflow":       "CWE-122",
    "stack-buffer-overflow":      "CWE-121",
    "global-buffer-overflow":     "CWE-120",
    "heap-use-after-free":        "CWE-416",
    "stack-use-after-return":     "CWE-562",
    "stack-use-after-scope":      "CWE-562",
    "use-after-poison":           "CWE-416",
    "alloc-dealloc-mismatch":     "CWE-762",
    "double-free":                "CWE-415",
    "attempting free on":         "CWE-761",
    "SEGV":                       "CWE-476",
    # UBSan
    "signed integer overflow":    "CWE-190",
    "unsigned integer overflow":  "CWE-190",
    "negation of":                "CWE-190",
    "shift exponent":             "CWE-190",
    "division by zero":           "CWE-369",
    "null pointer":               "CWE-476",
    "misaligned address":         "CWE-188",
    "load of value":              "CWE-758",   # invalid enum/bool
    "member access within":       "CWE-476",
    "index .* out of bounds":     "CWE-125",
    "implicit conversion":        "CWE-197",
    "object size":                "CWE-120",
}


def normalize(name: str) -> str:
    return name.replace(" ", "_").replace(".", "")


def get_paths(mode):
    if mode == "demo":
        return {
            "CPP_ROOT":      "demo/demo_derived/demo_cpp",
            "ANALYSIS_ROOT": "demo/demo_analysis/demo_sanitizers",
            "BIN_ROOT":      "demo/demo_bin_sanitized",
        }
    return {
        "CPP_ROOT":      "derived/cpp",
        "ANALYSIS_ROOT": "analysis/sanitizers",
        "BIN_ROOT":      "bin_sanitized",
    }


@lru_cache(maxsize=16)
def load_test_map(shard: int):
    testfile = f"data/testcases/testcases-train-{shard:05d}.json"
    if not os.path.exists(testfile):
        return None
    with open(testfile) as f:
        tests = json.load(f)
    return {normalize(p["name"]): p for p in tests}


def parse_sanitizer_stderr(stderr_text: str):
    """Extract sanitizer error types and map to CWEs."""
    errors = []
    cwes = set()

    for pattern, cwe in SANITIZER_CWE_MAP.items():
        if re.search(pattern, stderr_text, re.IGNORECASE):
            errors.append(pattern)
            cwes.add(cwe)

    return errors, sorted(cwes)


def run_sanitized_binary(bin_path, inp: str):
    """Run a sanitizer-instrumented binary and capture results."""
    try:
        p = subprocess.run(
            [bin_path],
            input=inp.encode(),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=TIMEOUT,
            env=SANITIZER_ENV,
        )
        stdout = p.stdout.decode("latin-1").strip()
        stderr = p.stderr.decode("utf-8", errors="replace")
        sanitizer_triggered = p.returncode != 0 and len(stderr) > 0
        errors, cwes = parse_sanitizer_stderr(stderr)

        return {
            "stdout": stdout,
            "returncode": p.returncode,
            "stderr_head": stderr[:2000],
            "sanitizer_triggered": sanitizer_triggered or len(errors) > 0,
            "sanitizer_errors": errors,
            "sanitizer_cwes": cwes,
            "timeout": False,
        }
    except subprocess.TimeoutExpired:
        return {
            "stdout": "",
            "returncode": -1,
            "stderr_head": "",
            "sanitizer_triggered": False,
            "sanitizer_errors": [],
            "sanitizer_cwes": [],
            "timeout": True,
        }


def compile_and_test_sanitized(task):
    """Compile with sanitizers and run all test cases."""
    cpp_path = task["cpp_path"]
    out_json_path = task["out_json_path"]
    bin_path = task["bin_path"]
    prob = task["prob_key"]
    shard = task["shard"]

    os.makedirs(os.path.dirname(bin_path), exist_ok=True)
    os.makedirs(os.path.dirname(out_json_path), exist_ok=True)

    result = {
        "problem_key": prob,
        "shard": shard,
        "compiled": False,
        "compile_error": None,
        "n_tests": 0,
        "n_passed": 0,
        "n_sanitizer_triggered": 0,
        "n_timeout": 0,
        "any_sanitizer_triggered": False,
        "all_sanitizer_errors": [],
        "all_sanitizer_cwes": [],
        "per_test": [],
    }

    # Clean stale binary
    if os.path.exists(bin_path):
        try:
            os.remove(bin_path)
        except OSError:
            pass

    # Compile with sanitizer flags
    compile_cmd = [CXX] + SANITIZER_COMPILE_FLAGS + [cpp_path, "-o", bin_path]
    compile_proc = subprocess.run(
        compile_cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )

    if compile_proc.returncode != 0:
        result["compile_error"] = compile_proc.stderr.decode(
            "utf-8", errors="replace"
        )[:1000]
        json.dump(result, open(out_json_path, "w"), indent=2)
        return task["label"], False, 0, 0, 0

    result["compiled"] = True

    # Load test cases
    test_map = load_test_map(shard)
    if test_map is None:
        json.dump(result, open(out_json_path, "w"), indent=2)
        return task["label"], True, 0, 0, 0

    problem = test_map.get(prob)
    if problem is None:
        json.dump(result, open(out_json_path, "w"), indent=2)
        return task["label"], True, 0, 0, 0

    pub = problem["public_tests"]
    all_errors = set()
    all_cwes = set()

    for i, (inp, exp) in enumerate(zip(pub["input"], pub["output"])):
        run_result = run_sanitized_binary(bin_path, inp)

        correct = (
            not run_result["timeout"]
            and run_result["stdout"].strip() == exp.strip()
        )

        test_record = {
            "test_idx": i,
            "correct": correct,
            "timeout": run_result["timeout"],
            "sanitizer_triggered": run_result["sanitizer_triggered"],
            "sanitizer_errors": run_result["sanitizer_errors"],
            "sanitizer_cwes": run_result["sanitizer_cwes"],
            "returncode": run_result["returncode"],
            "stderr_head": run_result["stderr_head"][:500],
        }

        result["per_test"].append(test_record)
        result["n_tests"] += 1

        if correct:
            result["n_passed"] += 1
        if run_result["timeout"]:
            result["n_timeout"] += 1
        if run_result["sanitizer_triggered"]:
            result["n_sanitizer_triggered"] += 1
            all_errors.update(run_result["sanitizer_errors"])
            all_cwes.update(run_result["sanitizer_cwes"])

    result["any_sanitizer_triggered"] = result["n_sanitizer_triggered"] > 0
    result["all_sanitizer_errors"] = sorted(all_errors)
    result["all_sanitizer_cwes"] = sorted(all_cwes)

    json.dump(result, open(out_json_path, "w"), indent=2)
    return (
        task["label"],
        True,
        result["n_passed"],
        result["n_tests"],
        result["n_sanitizer_triggered"],
    )


def build_llm_tasks(paths):
    tasks = []
    for model in MODELS:
        for gen in GENS:
            base = f"{paths['CPP_ROOT']}/{model}/{gen}"
            if not os.path.isdir(base):
                continue
            for batch in sorted(os.listdir(base)):
                cpp_dir = f"{base}/{batch}"
                if not os.path.isdir(cpp_dir):
                    continue

                batch_id = int(batch.split("_")[0])
                shard = batch_id % 3

                bin_dir = f"{paths['BIN_ROOT']}/{model}/{gen}/{batch}"
                out_dir = f"{paths['ANALYSIS_ROOT']}/{model}/{gen}/{batch}"

                for cpp_file in os.listdir(cpp_dir):
                    if not cpp_file.endswith(".cpp"):
                        continue
                    prob = normalize(
                        "_".join(cpp_file.split("_")[1:]).replace(".cpp", "")
                    )
                    tasks.append({
                        "cpp_path": os.path.join(cpp_dir, cpp_file),
                        "bin_path": os.path.join(bin_dir, cpp_file[:-4]),
                        "out_json_path": os.path.join(out_dir, f"{cpp_file}.json"),
                        "prob_key": prob,
                        "shard": shard,
                        "label": f"{model}/{gen}/{batch}/{cpp_file}",
                    })
    return tasks


def build_human_tasks(paths):
    tasks = []
    for soln in HUMAN_SOLNS:
        base = f"{paths['CPP_ROOT']}/human/{soln}"
        if not os.path.isdir(base):
            continue
        for batch in sorted(os.listdir(base)):
            if not batch.isdigit():
                continue
            cpp_dir = f"{base}/{batch}"
            if not os.path.isdir(cpp_dir):
                continue

            batch_id = int(batch)
            shard = batch_id % 3

            bin_dir = f"{paths['BIN_ROOT']}/human/{soln}/{batch}"
            out_dir = f"{paths['ANALYSIS_ROOT']}/human/{soln}/{batch}"

            for cpp_file in os.listdir(cpp_dir):
                if not cpp_file.endswith(".cpp"):
                    continue
                prob = normalize(
                    "_".join(cpp_file.split("_")[1:]).replace(".cpp", "")
                )
                tasks.append({
                    "cpp_path": os.path.join(cpp_dir, cpp_file),
                    "bin_path": os.path.join(bin_dir, cpp_file[:-4]),
                    "out_json_path": os.path.join(out_dir, f"{cpp_file}.json"),
                    "prob_key": prob,
                    "shard": shard,
                    "label": f"human/{soln}/{batch}/{cpp_file}",
                })
    return tasks


def main():
    parser = argparse.ArgumentParser(
        description="Run sanitizer-instrumented test execution"
    )
    parser.add_argument("--mode", required=True, choices=["demo", "full"])
    parser.add_argument(
        "--jobs", type=int, default=max(1, os.cpu_count() // 2),
        help="Number of parallel workers",
    )
    parser.add_argument(
        "--only", choices=["llm", "human", "all"], default="all",
    )
    args = parser.parse_args()

    paths = get_paths(args.mode)
    tasks = []
    if args.only in ("llm", "all"):
        tasks.extend(build_llm_tasks(paths))
    if args.only in ("human", "all"):
        tasks.extend(build_human_tasks(paths))

    print(f"[sanitizers] {len(tasks)} tasks, {args.jobs} workers")

    compiled = 0
    total = 0
    san_triggered = 0

    with ProcessPoolExecutor(max_workers=args.jobs) as ex:
        futs = [ex.submit(compile_and_test_sanitized, t) for t in tasks]
        for fut in as_completed(futs):
            label, comp_ok, passed, n_tests, n_san = fut.result()
            total += 1
            compiled += int(comp_ok)
            san_triggered += int(n_san > 0)

            if total % 200 == 0:
                print(
                    f"  [{total}/{len(tasks)}] compiled={compiled} "
                    f"sanitizer_triggered={san_triggered}"
                )

    print(f"\nDone. Total={total}  Compiled={compiled}  "
          f"Sanitizer triggered={san_triggered} "
          f"({san_triggered/max(compiled,1)*100:.1f}% of compiled)")


if __name__ == "__main__":
    main()
