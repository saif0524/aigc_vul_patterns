#!/usr/bin/env python3
"""Draw the 100-task random subset for the few-shot prompting experiment.

Simple random sample (no stratification) of 100 of the 851 benchmark tasks,
with a fixed seed so the draw can be reproduced.

Run from the repository root:
    python3.11 revision_experiments/fewshot_100_sample/sample_tasks.py

Outputs (in this folder):
    sample_tasks.csv              one row per sampled task: name, key, shard, index, tags
    descriptions-sample.json      [{name, description}], same format as data/instructions/
    representativeness.csv        zero-shot rates on the sample vs. all 851 tasks
"""
import csv
import glob
import json
import os
import random
import re

import pandas as pd

SEED = 20261102
N = 100

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
HERE = os.path.dirname(os.path.abspath(__file__))


def norm(s):
    """Key that matches problem names across files (they differ in '.', '-', '_')."""
    return re.sub(r"[^a-z0-9]", "", s.lower())


# --- all tasks, from the instruction files ---------------------------------
tasks = []
for path in sorted(glob.glob(os.path.join(ROOT, "data", "instructions", "descriptions-train-*.json"))):
    shard = re.search(r"(\d{5})\.json$", path).group(1)
    with open(path, encoding="utf-8") as f:
        for i, e in enumerate(json.load(f)):
            tasks.append({"shard": shard, "index": i, "name": e["name"], "description": e["description"]})
assert len(tasks) == 851, len(tasks)
assert len({norm(t["name"]) for t in tasks}) == 851

tags = {}
for path in glob.glob(os.path.join(ROOT, "data", "problem_tags", "problem_tags_*.json")):
    with open(path, encoding="utf-8") as f:
        for e in json.load(f):
            tags[norm(e["problem_name"])] = e["cf_tags"]

# --- draw -------------------------------------------------------------------
tasks.sort(key=lambda t: (t["shard"], t["index"]))
rng = random.Random(SEED)
sample = sorted(rng.sample(tasks, N), key=lambda t: (t["shard"], t["index"]))
sample_norm = {norm(t["name"]) for t in sample}

with open(os.path.join(HERE, "sample_tasks.csv"), "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["problem_name", "norm_key", "shard", "index_in_shard", "cf_tags"])
    for t in sample:
        w.writerow([t["name"], norm(t["name"]), t["shard"], t["index"], ";".join(tags.get(norm(t["name"]), []))])

with open(os.path.join(HERE, "descriptions-sample.json"), "w", encoding="utf-8") as f:
    json.dump([{"name": t["name"], "description": t["description"]} for t in sample], f, ensure_ascii=False, indent=1)

# --- check: does the sample look like the full benchmark under zero-shot? ---
df = pd.read_csv(os.path.join(ROOT, "results", "raw_csv", "glmm_program_level.csv"))
df["norm_key"] = df["problem_key"].map(norm)
df["in_sample"] = df["norm_key"].isin(sample_norm)
assert df.loc[df.in_sample, "norm_key"].nunique() == N

rows = []
for label, d in [("all_851", df), ("sample_100", df[df.in_sample])]:
    for model in ["human", "gemma", "llama", "qwen"]:
        m = d[d.model == model]
        ran = m[m.san_run == 1]
        rows.append({
            "set": label,
            "model": model,
            "programs": len(m),
            "passed_all_pct": round(100 * m.passed_all.mean(), 1),
            "sanitizer_pct_of_run": round(100 * ran.san_violation.mean(), 1),
            "esbmc_failed": int((m.esbmc_failed == 1).sum()),
        })
pd.DataFrame(rows).to_csv(os.path.join(HERE, "representativeness.csv"), index=False)
print(pd.DataFrame(rows).to_string(index=False))
