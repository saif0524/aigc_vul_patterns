import os
import json
import subprocess
import re
import argparse

TIMEOUT = 10

HUMAN_SOLNS = ["soln1", "soln2"]
MODELS = ["gemma", "llama", "qwen"]
GENS   = ["gen_1", "gen_2", "gen_3"]

def normalize(name: str) -> str:
    return name.replace(" ", "_").replace(".", "")

def run_binary(bin_path, inp):
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


def run_batch(model, gen, batch, paths):
#    CPP_DIR = f"derived/cpp/{model}/{gen}/{batch}"
    CPP_DIR = f"{paths['CPP_ROOT']}/{model}/{gen}/{batch}"
    BIN_DIR = f"{paths['BIN_ROOT']}/{model}/{gen}/{batch}"
    OUT_DIR = f"{paths['ANALYSIS_ROOT']}/{model}/{gen}/{batch}"

    # FIX: handle batch names like 00000_2
    batch_id = int(batch.split("_")[0])
    shard = batch_id % 3
    TESTFILE = f"data/testcases/testcases-train-{shard:05d}.json"

    if not os.path.isdir(CPP_DIR) or not os.path.exists(TESTFILE):
        return

    os.makedirs(BIN_DIR, exist_ok=True)
    os.makedirs(OUT_DIR, exist_ok=True)

    tests = json.load(open(TESTFILE))

    # Build test lookup by problem name
    test_map = {
        normalize(p["name"]): p for p in tests
    }

    for cpp_file in os.listdir(CPP_DIR):
        if not cpp_file.endswith(".cpp"):
            continue

        prob = normalize("_".join(cpp_file.split("_")[1:]).replace(".cpp",""))

        if prob not in test_map:
            continue

        cpp_path = os.path.join(CPP_DIR, cpp_file)
        bin_path = os.path.join(BIN_DIR, cpp_file.replace(".cpp",""))

        result = {
            "compiled": False,
            "passed": 0,
            "total": 0,
            "timeout": False
        }

        compile_proc = subprocess.run(
            ["g++", "-std=c++17", "-O2", cpp_path, "-o", bin_path],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )

        if compile_proc.returncode != 0:
            json.dump(result, open(f"{OUT_DIR}/{cpp_file}.json", "w"), indent=2)
            continue

        result["compiled"] = True
        problem = test_map[prob]

        pub = problem["public_tests"]
        for inp, exp in zip(pub["input"], pub["output"]):
            out, to = run_binary(bin_path, inp)
            result["total"] += 1
            if not to and out.strip() == exp.strip():
                result["passed"] += 1
            result["timeout"] |= to

        json.dump(result, open(f"{OUT_DIR}/{cpp_file}.json", "w"), indent=2)
        print(f"[OK] {model}/{gen}/{batch}/{cpp_file} → {result['passed']}/{result['total']}")


def run_human_batch(soln, batch, paths):
    if not batch.isdigit():
        return

    batch_id = int(batch)
    shard = batch_id % 3

    CPP_DIR = f"{paths['CPP_ROOT']}/human/{soln}/{batch}"
    BIN_DIR = f"{paths['BIN_ROOT']}/human/{soln}/{batch}"
    OUT_DIR = f"{paths['ANALYSIS_ROOT']}/human/{soln}/{batch}"
    TESTFILE = f"data/testcases/testcases-train-{shard:05d}.json"

    if not os.path.isdir(CPP_DIR) or not os.path.exists(TESTFILE):
        return

    os.makedirs(BIN_DIR, exist_ok=True)
    os.makedirs(OUT_DIR, exist_ok=True)

    tests = json.load(open(TESTFILE))
    test_map = { normalize(p["name"]): p for p in tests }

    for cpp_file in os.listdir(CPP_DIR):
        if not cpp_file.endswith(".cpp"):
            continue

        prob = normalize("_".join(cpp_file.split("_")[1:]).replace(".cpp", ""))
        if prob not in test_map:
            continue

        cpp_path = os.path.join(CPP_DIR, cpp_file)
        bin_path = os.path.join(BIN_DIR, cpp_file.replace(".cpp", ""))

        result = {
            "compiled": False,
            "passed": 0,
            "total": 0,
            "timeout": False
        }

        compile_proc = subprocess.run(
            ["g++", "-std=c++17", "-O2", cpp_path, "-o", bin_path],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )

        if compile_proc.returncode != 0:
            json.dump(result, open(f"{OUT_DIR}/{cpp_file}.json", "w"), indent=2)
            continue

        result["compiled"] = True
        pub = test_map[prob]["public_tests"]

        for inp, exp in zip(pub["input"], pub["output"]):
            out, to = run_binary(bin_path, inp)
            result["total"] += 1
            if not to and out.strip() == exp.strip():
                result["passed"] += 1
            result["timeout"] |= to

        json.dump(result, open(f"{OUT_DIR}/{cpp_file}.json", "w"), indent=2)
        print(f"[OK] human/{soln}/{batch}/{cpp_file} → {result['passed']}/{result['total']}")


def run_all(mode):
    paths = get_paths(mode)

    for model in MODELS:
        for gen in GENS:
            base = f"{paths['CPP_ROOT']}/{model}/{gen}"
            if not os.path.isdir(base):
                continue
            for batch in sorted(os.listdir(base)):
                run_batch(model, gen, batch, paths)


def run_all_human(mode):
    paths = get_paths(mode)

    for soln in HUMAN_SOLNS:
        base = f"{paths['CPP_ROOT']}/human/{soln}"
        if not os.path.isdir(base):
            continue
        for batch in sorted(os.listdir(base)):
            run_human_batch(soln, batch, paths)


def parse_args():
    parser = argparse.ArgumentParser(
        description=(
            "Run compilation and test evaluation for LLM-generated and human-written "
            "C++ solutions. Supports full runs and an isolated demo mode."
        ),
        epilog=(
            "Examples:\n"
            "  Full experiment (paper results):\n"
            "    python run_tests.py --mode full\n\n"
            "  Demo run (isolated paths, small subset):\n"
            "    python run_tests.py --mode demo\n"
        ),
        formatter_class=argparse.RawTextHelpFormatter
    )

    parser.add_argument(
        "--mode",
        required=True,                     # ← FORCE the argument
        choices=["demo", "full"],
        help=(
            "Execution mode:\n"
            "  full  - run on the full dataset using standard paths\n"
            "  demo  - run on a small, isolated demo dataset under demo/ paths"
        )
    )

    return parser.parse_args()


if __name__ == "__main__":
    args = parse_args()
    run_all(args.mode)
    run_all_human(args.mode)