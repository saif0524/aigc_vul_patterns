#!/usr/bin/env python3
"""cppcheck on the few-shot programs. Same command as scripts/run_cppcheck_parallel.py.

    python3.11 revision_experiments/fewshot_scripts/run_cppcheck_fewshot.py --jobs 8

Output: revision_experiments/analysis/fewshot/cppcheck/<model>/gen_N/<stem>.xml
"""
import subprocess
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

import common

TIMEOUT_XML = ('<?xml version="1.0"?>\n<results><errors><error id="timeout" '
               'msg="Analysis timed out"/></errors></results>\n')


def run_one(args):
    cpp_path, out_file, timeout = args
    out_file.parent.mkdir(parents=True, exist_ok=True)
    cmd = ["cppcheck", "--enable=warning,style,performance,portability",
           "--std=c++17", "--xml", str(cpp_path)]
    try:
        r = subprocess.run(cmd, capture_output=True, timeout=timeout, text=True)
        out_file.write_text(r.stderr)          # cppcheck writes its XML to stderr
        return "success"
    except subprocess.TimeoutExpired:
        out_file.write_text(TIMEOUT_XML)
        return "timeout"
    except Exception:
        return "error"


def main():
    ap = common.base_parser("cppcheck on few-shot programs", 8)
    ap.add_argument("--timeout", "-t", type=int, default=30, help="seconds per file")
    a = ap.parse_args()

    root = a.out_root or common.out_root("cppcheck")
    jobs = []
    for p in common.collect(a.models, a.gens, a.limit):
        out = root / p.relative_to(common.SRC_ROOT).with_suffix(".xml")
        if a.skip_existing and out.exists():
            continue
        jobs.append((p, out, a.timeout))
    print(f"[cppcheck] {len(jobs)} files, {a.jobs} workers -> {root}")

    counts = {"success": 0, "timeout": 0, "error": 0}
    with ProcessPoolExecutor(max_workers=a.jobs) as ex:
        for i, fut in enumerate(as_completed([ex.submit(run_one, j) for j in jobs]), 1):
            counts[fut.result()] += 1
            if i % 50 == 0 or i == len(jobs):
                print(f"  [{i}/{len(jobs)}] {counts}")


if __name__ == "__main__":
    main()
