#!/usr/bin/env python3
"""clang-tidy on the few-shot programs. Same command as scripts/run_clang_tidy.sh.

    python3.11 revision_experiments/fewshot_scripts/run_clang_tidy_fewshot.py --jobs 4

Output: revision_experiments/analysis/fewshot/clang_tidy/<model>/gen_N/<stem>.yaml
"""
import shutil
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor, as_completed

import common

CHECKS = "clang-analyzer-security*,bugprone-*,performance-*,modernize-*"
BINARY = shutil.which("clang-tidy-21") or shutil.which("clang-tidy")


def run_one(args):
    cpp_path, out_file, timeout = args
    out_file.parent.mkdir(parents=True, exist_ok=True)
    cmd = [BINARY, str(cpp_path), "-p=.", f"-checks={CHECKS}",
           f"-export-fixes={out_file}", "--", "-std=c++17"]
    try:
        subprocess.run(cmd, capture_output=True, timeout=timeout, cwd=common.REPO)
        return "done"
    except subprocess.TimeoutExpired:
        return "timeout"
    except Exception:
        return "error"


def main():
    if not BINARY:
        sys.exit("clang-tidy-21 (or clang-tidy) not found on PATH")
    ap = common.base_parser("clang-tidy on few-shot programs", 4)
    ap.add_argument("--timeout", "-t", type=int, default=300, help="seconds per file")
    a = ap.parse_args()

    root = a.out_root or common.out_root("clang_tidy")
    jobs = []
    for p in common.collect(a.models, a.gens, a.limit):
        out = root / p.relative_to(common.SRC_ROOT).with_suffix(".yaml")
        if a.skip_existing and out.exists():
            continue
        jobs.append((p, out, a.timeout))
    print(f"[clang-tidy] {BINARY}: {len(jobs)} files, {a.jobs} workers -> {root}")

    counts = {"done": 0, "timeout": 0, "error": 0}
    with ThreadPoolExecutor(max_workers=a.jobs) as ex:
        for i, fut in enumerate(as_completed([ex.submit(run_one, j) for j in jobs]), 1):
            counts[fut.result()] += 1
            if i % 50 == 0 or i == len(jobs):
                print(f"  [{i}/{len(jobs)}] {counts}")


if __name__ == "__main__":
    main()
