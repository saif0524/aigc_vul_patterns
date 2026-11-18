#!/usr/bin/env python3
"""Split the few-shot generation JSON files into one .cpp file per program.

Same method as scripts/extract_cpp.py: one file per JSON row, named
<idx>_<safe_name>.cpp, where idx is the row's position in the JSON file (4 digits).

    scripts/extract_cpp.py:  derived/cpp/<model>/gen_N/<batch>/<idx>_<name>.cpp
    this script:             revision_experiments/derived_cpp/fewshot/<model>/gen_N/<idx>_<name>.cpp

Differences: no <batch> folder (the 100 tasks are one file), and rows with no code
(status no_code / api_error) are not written. They are listed in skipped.csv. The main
study never had such rows because the generation notebook dropped them.

The output folders are cleared before each run, so file numbers always match the
current JSON files.

Run from the repository root:
    python3.11 revision_experiments/fewshot_scripts/extract_fewshot_cpp.py
"""
import csv
import glob
import json
import os
import re
import shutil

HERE = os.path.dirname(os.path.abspath(__file__))
GEN_ROOT = os.path.join(os.path.dirname(HERE), "fewshot_100_sample", "generations")
OUT_ROOT = os.path.join(os.path.dirname(HERE), "derived_cpp", "fewshot")


def safe_filename(name):          # identical to scripts/extract_cpp.py
    return re.sub(r"[^\w_.-]", "_", name)


skipped = []
for path in sorted(glob.glob(os.path.join(GEN_ROOT, "*", "gen_*", "*.json"))):
    model, gen = path.split(os.sep)[-3:-1]
    out_dir = os.path.join(OUT_ROOT, model, gen)
    shutil.rmtree(out_dir, ignore_errors=True)
    os.makedirs(out_dir)

    with open(path, "r", encoding="utf-8") as f:
        data = json.load(f)

    n = 0
    for idx, row in enumerate(data):
        name = row.get("name", f"problem_{idx}")
        code = (row.get("generated_cpp") or "").strip()
        if not code:
            skipped.append([model, gen, idx, name, row.get("status", "")])
            continue
        with open(os.path.join(out_dir, f"{idx:04d}_{safe_filename(name)}.cpp"), "w", encoding="utf-8") as out:
            out.write(code)
        n += 1
    print(f"[OK] {model}/{gen}: {n} files written, {len(data) - n} skipped")

with open(os.path.join(OUT_ROOT, "skipped.csv"), "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["model", "generation", "row_index", "problem_name", "status"])
    w.writerows(skipped)
