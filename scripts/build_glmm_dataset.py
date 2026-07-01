#!/usr/bin/env python3
"""
Build a one-row-per-program analysis table for mixed-effects modeling.

Joins the three analysis tiers at program level:
  - static  : cppcheck (from master_analysis.csv)
  - dynamic : ASan/UBSan (aggregated from sanitizer_detailed.csv, per-test -> per-program)
  - formal  : ESBMC (from esbmc_summary.csv)

Outcome coding follows the inconclusive-verdict handling discussed for the
ICSME resubmission:
  * san_violation   : 1 if ANY executed test triggered a sanitizer error, else 0.
                      NA if the program was never run under sanitizers.
  * esbmc_failed    : 1 if verdict == FAILED, 0 if verdict == SUCCESS,
                      NA otherwise (PARSE_ERROR / TIMEOUT / ERROR -> inconclusive).
  * cppcheck_flag   : 1 if cppcheck reported >=1 CWE, else 0.

Grouping / fixed effects:
  * problem_key : random-effect grouping (programs nested within problem)
  * source      : human vs AI
  * model       : human / gemma / llama / qwen
  * pass_rate, passed_all, n_tests, loc : candidate fixed-effect covariates

Output: results/raw_csv/glmm_program_level.csv  (NA written as empty string)
"""
import csv
import os
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RAW = os.path.join(ROOT, "results", "raw_csv")
MASTER = os.path.join(RAW, "master_analysis.csv")
SAN = os.path.join(RAW, "sanitizer_detailed.csv")
ESBMC = os.path.join(RAW, "esbmc_summary.csv")
OUT = os.path.join(RAW, "glmm_program_level.csv")

# --- 1. sanitizer: per-test -> per-program (any trigger) -------------------
san_run = set()
san_violation = set()
with open(SAN, newline="") as f:
    for r in csv.DictReader(f):
        sid = r["sample_id"]
        san_run.add(sid)
        if r["sanitizer_triggered"].strip().lower() == "true":
            san_violation.add(sid)

# --- 2. esbmc: per-program verdict -----------------------------------------
esbmc_verdict = {}
with open(ESBMC, newline="") as f:
    for r in csv.DictReader(f):
        esbmc_verdict[r["sample_id"]] = r["verdict"].strip()

# --- 3. helper: LOC from source file (best-effort) -------------------------
def loc_for(sample_id):
    path = os.path.join(ROOT, "derived", "cpp", sample_id)
    if not os.path.exists(path):
        return ""
    try:
        with open(path, "rb") as fh:
            return str(sum(1 for _ in fh))
    except OSError:
        return ""

# --- 4. walk master, emit joined rows --------------------------------------
fields = [
    "sample_id", "problem_key", "source", "model", "generation",
    "compiled", "n_tests", "pass_rate", "passed_all", "loc",
    "cppcheck_flag", "cppcheck_cwe_count",
    "san_run", "san_violation",
    "esbmc_verdict", "esbmc_conclusive", "esbmc_failed",
]

n_written = 0
with open(MASTER, newline="") as f, open(OUT, "w", newline="") as out:
    w = csv.DictWriter(out, fieldnames=fields)
    w.writeheader()
    for r in csv.DictReader(f):
        sid = r["sample_id"]
        model = r["model"]
        if model not in ("human", "gemma", "llama", "qwen"):
            continue  # skip stray/garbage rows
        try:
            pass_rate = float(r["pass_rate"]) if r["pass_rate"] else ""
        except ValueError:
            pass_rate = ""
        passed_all = "1" if pass_rate == 1.0 else ("0" if pass_rate != "" else "")

        # sanitizer
        if sid in san_run:
            srun, sviol = "1", ("1" if sid in san_violation else "0")
        else:
            srun, sviol = "0", ""

        # esbmc
        v = esbmc_verdict.get(sid, "")
        if v == "FAILED":
            conclusive, failed = "1", "1"
        elif v == "SUCCESS":
            conclusive, failed = "1", "0"
        else:
            conclusive, failed = "0", ""

        w.writerow({
            "sample_id": sid,
            "problem_key": r["problem_key"],
            "source": "human" if model == "human" else "AI",
            "model": model,
            "generation": r["generation"],
            "compiled": r["compiled"],
            "n_tests": r["total_tests"],
            "pass_rate": pass_rate,
            "passed_all": passed_all,
            "loc": loc_for(sid),
            "cppcheck_flag": "1" if r["cppcheck_has_cwe"] in ("1", "True", "true") else "0",
            "cppcheck_cwe_count": r["cppcheck_cwe_count"],
            "san_run": srun,
            "san_violation": sviol,
            "esbmc_verdict": v,
            "esbmc_conclusive": conclusive,
            "esbmc_failed": failed,
        })
        n_written += 1

print(f"wrote {n_written} program rows -> {OUT}")
