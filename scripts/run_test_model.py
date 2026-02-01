import os
import json
import subprocess
import re

TIMEOUT = 10

MODELS = ["gemma"]
GENS   = ["gen_1"]

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

def run_batch(model, gen, batch):
    CPP_DIR = f"derived/cpp/{model}/{gen}/{batch}"
    BIN_DIR = f"bin/{model}/{gen}/{batch}"
    OUT_DIR = f"analysis/tests/{model}/{gen}/{batch}"

    batch_id = int(batch)
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

def run_all():
    for model in MODELS:
        for gen in GENS:
            base = f"derived/cpp/{model}/{gen}"
            if not os.path.isdir(base):
                continue
            for batch in sorted(os.listdir(base)):
                run_batch(model, gen, batch)

if __name__ == "__main__":
    run_all()