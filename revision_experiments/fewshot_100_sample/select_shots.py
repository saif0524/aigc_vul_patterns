#!/usr/bin/env python3
"""Pick the two human solutions used as the fixed 2-shot examples.

Rules, set before drawing:
  * the problem is not one of the 100 sampled test tasks
  * the human solution compiled, passed all tests, ran under ASan/UBSan with no
    violation, had no cppcheck finding, and was not ESBMC FAILED
  * two different problems, drawn at random (seed below), one qualifying
    solution per problem, also drawn at random

Run from the repository root after sample_tasks.py:
    python3.11 revision_experiments/fewshot_100_sample/select_shots.py

Output: shots.json  [{problem_name, description, sample_id, cf_tags, loc, esbmc_verdict, code}]
"""
import glob
import json
import os
import random
import re

import pandas as pd

SEED = 20261102
K = 2

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
HERE = os.path.dirname(os.path.abspath(__file__))


def norm(s):
    return re.sub(r"[^a-z0-9]", "", s.lower())


sample = set(pd.read_csv(os.path.join(HERE, "sample_tasks.csv"))["norm_key"])

desc, tags = {}, {}
for path in glob.glob(os.path.join(ROOT, "data", "instructions", "descriptions-train-*.json")):
    with open(path, encoding="utf-8") as f:
        for e in json.load(f):
            desc[norm(e["name"])] = (e["name"], e["description"])
for path in glob.glob(os.path.join(ROOT, "data", "problem_tags", "problem_tags_*.json")):
    with open(path, encoding="utf-8") as f:
        for e in json.load(f):
            tags[norm(e["problem_name"])] = e["cf_tags"]

df = pd.read_csv(os.path.join(ROOT, "results", "raw_csv", "glmm_program_level.csv"))
df["norm_key"] = df["problem_key"].map(norm)
pool = df[
    (df.model == "human")
    & (~df.norm_key.isin(sample))
    & (df.compiled == 1)
    & (df.passed_all == 1)
    & (df.san_run == 1)
    & (df.san_violation == 0)
    & (df.cppcheck_flag == 0)
    & (df.esbmc_failed != 1)
].sort_values("sample_id")
print(f"pool: {len(pool)} solutions over {pool.norm_key.nunique()} problems")

rng = random.Random(SEED)
problems = rng.sample(sorted(pool.norm_key.unique()), K)
shots = []
for nk in problems:
    sid = rng.choice(sorted(pool[pool.norm_key == nk].sample_id))
    row = pool[pool.sample_id == sid].iloc[0]
    with open(os.path.join(ROOT, "derived", "cpp", sid), encoding="utf-8") as f:
        code = f.read().strip()
    name, description = desc[nk]
    shots.append({
        "problem_name": name,
        "description": description,
        "sample_id": sid,
        "cf_tags": tags.get(nk, []),
        "loc": int(row["loc"]),
        "esbmc_verdict": row["esbmc_verdict"],
        "code": code,
    })
    print(f"{name}  |  {sid}  |  {int(row['loc'])} LOC  |  ESBMC {row['esbmc_verdict']}")

with open(os.path.join(HERE, "shots.json"), "w", encoding="utf-8") as f:
    json.dump(shots, f, ensure_ascii=False, indent=1)
