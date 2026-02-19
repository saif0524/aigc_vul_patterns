"""
run_esbmc.py
============
Run ESBMC bounded model checker on generated and human C++ programs.

ESBMC checks for array bounds violations, arithmetic overflow,
null pointer dereferences, division by zero, and memory safety
properties via formal verification (SMT-based bounded model checking).

Three possible outcomes per program:
  - VERIFICATION SUCCESSFUL: no property violations found (within bound)
  - VERIFICATION FAILED:     proven reachable bug + counterexample
  - ERROR:                    parse error, timeout, or internal error

Usage:
    # Baseline (matches original run)
    python scripts/run_esbmc.py --mode full --jobs 8 --only all

    # With arithmetic overflow checking enabled
    python scripts/run_esbmc.py --mode full --jobs 8 --only all \
        --overflow-check --tag esbmc_overflow

    # Deeper unwind + longer timeout
    python scripts/run_esbmc.py --mode full --jobs 8 --only all \
        --unwind 20 --timeout 120 --tag esbmc_deep

Output:  analysis/{tag}/{model}/{gen}/{batch}/{file}.json
         Default tag: esbmc  (preserves original output layout)
"""

import os
import re
import json
import argparse
import subprocess
from concurrent.futures import ProcessPoolExecutor, as_completed

ESBMC_BIN = os.path.join(
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
    "esbmc", "bin", "esbmc"
)

# Defaults — overridden by CLI args
DEFAULT_TIMEOUT = 60   # seconds per file
DEFAULT_UNWIND  = 10   # loop unwind bound
DEFAULT_TAG     = "esbmc"

HUMAN_SOLNS = ["soln1", "soln2"]
MODELS = ["gemma", "llama", "qwen"]
GENS = ["gen_1", "gen_2", "gen_3"]

# Map ESBMC property violations to CWE IDs
ESBMC_CWE_MAP = {
    "array bounds violated":          "CWE-119",
    "array_bounds":                   "CWE-119",
    "buffer overflow":                "CWE-120",
    "dereference failure":            "CWE-476",
    "null pointer":                   "CWE-476",
    "NULL pointer":                   "CWE-476",
    "division by zero":               "CWE-369",
    "arithmetic overflow":            "CWE-190",
    "overflow on":                    "CWE-190",
    "signed integer overflow":        "CWE-190",
    "unsigned integer overflow":      "CWE-190",
    "memory-leak":                    "CWE-401",
    "memory leak":                    "CWE-401",
    "double free":                    "CWE-415",
    "use after free":                 "CWE-416",
    "invalid pointer":                "CWE-825",
    "dynamic object bounds":          "CWE-119",
    "same object violation":          "CWE-119",
    "access to object out of bounds": "CWE-119",
}


def normalize(name: str) -> str:
    return name.replace(" ", "_").replace(".", "")


def get_paths(mode, tag=DEFAULT_TAG):
    if mode == "demo":
        return {
            "CPP_ROOT":      "demo/demo_derived/demo_cpp",
            "ANALYSIS_ROOT": f"demo/demo_analysis/{tag}",
        }
    return {
        "CPP_ROOT":      "derived/cpp",
        "ANALYSIS_ROOT": f"analysis/{tag}",
    }


def parse_esbmc_output(stdout: str, stderr: str):
    """Parse ESBMC output to extract verification result and violations."""
    combined = stdout + "\n" + stderr

    # Determine overall result
    if "VERIFICATION SUCCESSFUL" in combined:
        verdict = "SUCCESS"
    elif "VERIFICATION FAILED" in combined:
        verdict = "FAILED"
    elif "PARSING ERROR" in combined or "CONVERSION ERROR" in combined:
        verdict = "PARSE_ERROR"
    elif "Timed out" in combined or "ERROR: Timed out" in combined:
        verdict = "TIMEOUT"
    else:
        verdict = "ERROR"

    # Extract violated properties
    violations = []
    cwes = set()

    # Look for "Violated property:" blocks
    prop_pattern = re.compile(
        r"Violated property:.*?\n\s*(.*?)(?:\n|$)", re.MULTILINE
    )
    for match in prop_pattern.finditer(combined):
        prop_text = match.group(1).strip()
        violations.append(prop_text)
        for pattern, cwe in ESBMC_CWE_MAP.items():
            if pattern.lower() in prop_text.lower():
                cwes.add(cwe)

    # Also scan for property descriptions in the broader output
    for pattern, cwe in ESBMC_CWE_MAP.items():
        if pattern.lower() in combined.lower() and verdict == "FAILED":
            cwes.add(cwe)

    return verdict, violations, sorted(cwes)


def run_esbmc_one(task):
    """Run ESBMC on a single C++ file."""
    cpp_path = task["cpp_path"]
    out_json_path = task["out_json_path"]
    prob = task["prob_key"]

    os.makedirs(os.path.dirname(out_json_path), exist_ok=True)

    result = {
        "problem_key": prob,
        "verdict": "ERROR",
        "violations": [],
        "cwes": [],
        "parse_error": False,
        "timeout": False,
        "runtime_seconds": 0,
        "stdout_head": "",
        "stderr_head": "",
    }

    timeout = task["timeout"]
    cmd = [
        ESBMC_BIN,
        "--compact-trace",
        "--timeout", str(timeout),
        "--unwind", str(task["unwind"]),
        "--no-unwinding-assertions",
        "--no-div-by-zero-check",  # reduces noise on contest code
        "--overflow-check",        # enabled by default; disable with --no-overflow-check
        cpp_path,
    ]
    if not task["overflow_check"]:
        cmd.remove("--overflow-check")

    try:
        proc = subprocess.run(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=timeout + 30,  # extra buffer beyond ESBMC's own timeout
        )
        stdout = proc.stdout.decode("utf-8", errors="replace")
        stderr = proc.stderr.decode("utf-8", errors="replace")

        verdict, violations, cwes = parse_esbmc_output(stdout, stderr)

        result["verdict"] = verdict
        result["violations"] = violations[:10]  # cap stored violations
        result["cwes"] = cwes
        result["parse_error"] = verdict == "PARSE_ERROR"
        result["timeout"] = verdict == "TIMEOUT"
        result["stdout_head"] = stdout[-1500:]  # tail is more useful
        result["stderr_head"] = stderr[:500]

    except subprocess.TimeoutExpired:
        result["verdict"] = "TIMEOUT"
        result["timeout"] = True

    except FileNotFoundError:
        result["verdict"] = "ERROR"
        result["stderr_head"] = f"ESBMC binary not found: {ESBMC_BIN}"

    json.dump(result, open(out_json_path, "w"), indent=2)
    return task["label"], result["verdict"], result["cwes"]


def build_llm_tasks(paths, cfg):
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

                out_dir = f"{paths['ANALYSIS_ROOT']}/{model}/{gen}/{batch}"

                for cpp_file in os.listdir(cpp_dir):
                    if not cpp_file.endswith(".cpp"):
                        continue
                    prob = normalize(
                        "_".join(cpp_file.split("_")[1:]).replace(".cpp", "")
                    )
                    tasks.append({
                        "cpp_path": os.path.join(cpp_dir, cpp_file),
                        "out_json_path": os.path.join(out_dir, f"{cpp_file}.json"),
                        "prob_key": prob,
                        "label": f"{model}/{gen}/{batch}/{cpp_file}",
                        **cfg,
                    })
    return tasks


def build_human_tasks(paths, cfg):
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

            out_dir = f"{paths['ANALYSIS_ROOT']}/human/{soln}/{batch}"

            for cpp_file in os.listdir(cpp_dir):
                if not cpp_file.endswith(".cpp"):
                    continue
                prob = normalize(
                    "_".join(cpp_file.split("_")[1:]).replace(".cpp", "")
                )
                tasks.append({
                    "cpp_path": os.path.join(cpp_dir, cpp_file),
                    "out_json_path": os.path.join(out_dir, f"{cpp_file}.json"),
                    "prob_key": prob,
                    "label": f"human/{soln}/{batch}/{cpp_file}",
                    **cfg,
                })
    return tasks


def main():
    parser = argparse.ArgumentParser(
        description="Run ESBMC bounded model checker on C++ programs"
    )
    parser.add_argument("--mode", required=True, choices=["demo", "full"])
    parser.add_argument(
        "--jobs", type=int, default=max(1, os.cpu_count() // 2),
    )
    parser.add_argument(
        "--only", choices=["llm", "human", "all"], default="all",
    )
    parser.add_argument(
        "--unwind", type=int, default=DEFAULT_UNWIND,
        help=f"ESBMC loop unwind bound (default: {DEFAULT_UNWIND})",
    )
    parser.add_argument(
        "--timeout", type=int, default=DEFAULT_TIMEOUT,
        help=f"ESBMC timeout in seconds (default: {DEFAULT_TIMEOUT})",
    )
    parser.add_argument(
        "--tag", default=DEFAULT_TAG,
        help=f"Output subdirectory under analysis/ (default: {DEFAULT_TAG})",
    )
    parser.add_argument(
        "--no-overflow-check", dest="overflow_check", action="store_false",
        help="Disable --overflow-check (reproduces original baseline run)",
    )
    parser.set_defaults(overflow_check=True)
    args = parser.parse_args()

    cfg = {
        "timeout":        args.timeout,
        "unwind":         args.unwind,
        "overflow_check": args.overflow_check,
    }

    paths = get_paths(args.mode, args.tag)
    tasks = []
    if args.only in ("llm", "all"):
        tasks.extend(build_llm_tasks(paths, cfg))
    if args.only in ("human", "all"):
        tasks.extend(build_human_tasks(paths, cfg))

    overflow_str = "ON" if args.overflow_check else "OFF"
    print(f"[esbmc] {len(tasks)} tasks, {args.jobs} workers")
    print(f"[esbmc] binary:          {ESBMC_BIN}")
    print(f"[esbmc] tag:             {args.tag}  →  analysis/{args.tag}/")
    print(f"[esbmc] unwind={args.unwind}, timeout={args.timeout}s, overflow-check={overflow_str}")

    counts = {"SUCCESS": 0, "FAILED": 0, "PARSE_ERROR": 0, "TIMEOUT": 0, "ERROR": 0}
    total = 0

    with ProcessPoolExecutor(max_workers=args.jobs) as ex:
        futs = [ex.submit(run_esbmc_one, t) for t in tasks]
        for fut in as_completed(futs):
            label, verdict, cwes = fut.result()
            total += 1
            counts[verdict] = counts.get(verdict, 0) + 1

            if total % 200 == 0:
                analyzable = counts["SUCCESS"] + counts["FAILED"]
                print(
                    f"  [{total}/{len(tasks)}] "
                    f"success={counts['SUCCESS']} failed={counts['FAILED']} "
                    f"parse_err={counts['PARSE_ERROR']} timeout={counts['TIMEOUT']} "
                    f"coverage={analyzable}/{total}"
                )

    analyzable = counts["SUCCESS"] + counts["FAILED"]
    print(f"\nDone. Total={total}")
    print(f"  VERIFICATION SUCCESSFUL: {counts['SUCCESS']}")
    print(f"  VERIFICATION FAILED:     {counts['FAILED']}")
    print(f"  PARSE ERROR:             {counts['PARSE_ERROR']}")
    print(f"  TIMEOUT:                 {counts['TIMEOUT']}")
    print(f"  OTHER ERROR:             {counts['ERROR']}")
    print(f"  Coverage (analyzable):   {analyzable}/{total} "
          f"({analyzable/max(total,1)*100:.1f}%)")


if __name__ == "__main__":
    main()
