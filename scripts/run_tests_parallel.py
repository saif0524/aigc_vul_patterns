import os
import json
import argparse
import subprocess
from functools import lru_cache
from concurrent.futures import ProcessPoolExecutor, as_completed

TIMEOUT = 10

HUMAN_SOLNS = ["soln1", "soln2"]
MODELS = ["gemma", "llama", "qwen"]
GENS   = ["gen_1", "gen_2", "gen_3"]

def normalize(name: str) -> str:
    return name.replace(" ", "_").replace(".", "")

def run_binary(bin_path, inp: str):
    try:
        p = subprocess.run(
            [bin_path],
            input=inp.encode(),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=TIMEOUT
        )
        return p.stdout.decode("latin-1").strip(), False
    except subprocess.TimeoutExpired:
        return "<timeout>", True

def get_paths(mode):
    if mode == "demo":
        return {
            "CPP_ROOT": "demo/demo_derived/demo_cpp",
            "ANALYSIS_ROOT": "demo/demo_analysis/demo_tests",
            "BIN_ROOT": "demo/demo_bin"
        }
    else:
        return {
            "CPP_ROOT": "derived/cpp",
            "ANALYSIS_ROOT": "analysis/tests",
            "BIN_ROOT": "bin"
        }

@lru_cache(maxsize=16)
def load_test_map(shard: int):
    testfile = f"data/testcases/testcases-train-{shard:05d}.json"
    if not os.path.exists(testfile):
        return None
    tests = json.load(open(testfile))
    return { normalize(p["name"]): p for p in tests }

def compile_and_test_one(task):
    """
    task dict contains:
      cpp_path, out_json_path, bin_path, prob_key, shard
    """
    cpp_path = task["cpp_path"]
    out_json_path = task["out_json_path"]
    bin_path = task["bin_path"]
    prob = task["prob_key"]
    shard = task["shard"]

    os.makedirs(os.path.dirname(bin_path), exist_ok=True)
    os.makedirs(os.path.dirname(out_json_path), exist_ok=True)

    result = {
        "compiled": False,
        "passed": 0,
        "total": 0,
        "timeout": False,

        "compile_attempted": True,
        "has_tests": False,
        "no_tests": False,
        "reason": None,
        "problem_key": prob,
        "shard": shard,
    }

    # Prevent stale binaries
    try:
        if os.path.exists(bin_path):
            os.remove(bin_path)
    except OSError:
        pass

    compile_proc = subprocess.run(
        ["g++", "-std=c++17", "-O2", cpp_path, "-o", bin_path],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )

    if compile_proc.returncode != 0:
        result["reason"] = "compile_error"
        result["compile_stderr_head"] = compile_proc.stderr.decode("utf-8", errors="replace")[:500]
        json.dump(result, open(out_json_path, "w"), indent=2)
        return task["label"], False, 0, 0

    result["compiled"] = True

    test_map = load_test_map(shard)
    if test_map is None:
        result["no_tests"] = True
        result["reason"] = "no_tests_file"
        json.dump(result, open(out_json_path, "w"), indent=2)
        return task["label"], True, 0, 0

    problem = test_map.get(prob)
    if problem is None:
        result["no_tests"] = True
        result["reason"] = "no_test_mapping"
        json.dump(result, open(out_json_path, "w"), indent=2)
        return task["label"], True, 0, 0

    # Run tests
    result["has_tests"] = True
    result["reason"] = "tested"
    pub = problem["public_tests"]

    for inp, exp in zip(pub["input"], pub["output"]):
        out, to = run_binary(bin_path, inp)
        result["total"] += 1
        if not to and out.strip() == exp.strip():
            result["passed"] += 1
        result["timeout"] |= to

    json.dump(result, open(out_json_path, "w"), indent=2)
    return task["label"], True, result["passed"], result["total"]

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
                    prob = normalize("_".join(cpp_file.split("_")[1:]).replace(".cpp", ""))
                    cpp_path = os.path.join(cpp_dir, cpp_file)

                    # Unique paths per file => no collisions
                    bin_path = os.path.join(bin_dir, cpp_file[:-4])  # strip .cpp
                    out_json = os.path.join(out_dir, f"{cpp_file}.json")

                    tasks.append({
                        "cpp_path": cpp_path,
                        "bin_path": bin_path,
                        "out_json_path": out_json,
                        "prob_key": prob,
                        "shard": shard,
                        "label": f"{model}/{gen}/{batch}/{cpp_file}"
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
                prob = normalize("_".join(cpp_file.split("_")[1:]).replace(".cpp", ""))
                cpp_path = os.path.join(cpp_dir, cpp_file)

                bin_path = os.path.join(bin_dir, cpp_file[:-4])
                out_json = os.path.join(out_dir, f"{cpp_file}.json")

                tasks.append({
                    "cpp_path": cpp_path,
                    "bin_path": bin_path,
                    "out_json_path": out_json,
                    "prob_key": prob,
                    "shard": shard,
                    "label": f"human/{soln}/{batch}/{cpp_file}"
                })
    return tasks

def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument("--mode", required=True, choices=["demo", "full"])
    p.add_argument("--jobs", type=int, default=max(1, os.cpu_count() // 2),
                   help="Number of parallel workers (processes).")
    p.add_argument("--only", choices=["llm", "human", "all"], default="all")
    return p.parse_args()

def main():
    args = parse_args()
    paths = get_paths(args.mode)

    tasks = []
    if args.only in ("llm", "all"):
        tasks.extend(build_llm_tasks(paths))
    if args.only in ("human", "all"):
        tasks.extend(build_human_tasks(paths))

    print(f"Discovered {len(tasks)} tasks. Running with {args.jobs} workers...")

    ok_compile = 0
    tot = 0
    passed = 0
    total_tests = 0

    with ProcessPoolExecutor(max_workers=args.jobs) as ex:
        futs = [ex.submit(compile_and_test_one, t) for t in tasks]
        for fut in as_completed(futs):
            label, compiled_ok, p, n = fut.result()
            tot += 1
            ok_compile += int(compiled_ok)
            passed += p
            total_tests += n
            if tot % 200 == 0:
                pr = (passed / total_tests) if total_tests else 0.0
                print(f"[{tot}/{len(tasks)}] compile_ok={ok_compile} pass_rate={pr:.3f}")

    print("Done.")
    print(f"Total programs: {tot}")
    print(f"Compiled OK:    {ok_compile}")
    if total_tests:
        print(f"Aggregate pass rate: {passed/total_tests:.3f} over {total_tests} tests")
    else:
        print("No tests executed.")

if __name__ == "__main__":
    main()