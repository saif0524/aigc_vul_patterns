"""
analyze_runs.py
===============
Compare the new ESBMC runs with the earlier ones and write tables to
revision_experiments/esbmc/tables/. Run from the repository root.
"""

import os
import re
import pandas as pd

ROOT = "revision_experiments/esbmc"
OUT = f"{ROOT}/tables"
os.makedirs(OUT, exist_ok=True)

feb = pd.read_csv(f"{ROOT}/reference/esbmc_summary_feb09_run1.csv")
apr = pd.read_csv(f"{ROOT}/reference/esbmc_summary_apr03_run2.csv")
e1 = pd.read_csv(f"{ROOT}/runs/e1_baseline_u10_t60/summary.csv")
e2 = pd.read_csv(f"{ROOT}/runs/e2_overflow_u10_t60/summary.csv")
san = pd.read_csv("results/raw_csv/sanitizer_summary.csv")
master = pd.read_csv("results/raw_csv/master_analysis.csv")

VERDICTS = ["FAILED", "SUCCESS", "TIMEOUT", "PARSE_ERROR", "ERROR"]
MODELS = ["gemma", "llama", "qwen", "human"]


def verdict_table(df, name):
    t = pd.crosstab(df.model, df.verdict).reindex(columns=VERDICTS, fill_value=0)
    t.loc["all"] = t.sum()
    t["total"] = t.sum(axis=1)
    t["conclusive"] = t.SUCCESS + t.FAILED
    t["coverage_pct"] = (100 * t.conclusive / t.total).round(1)
    t["failed_of_conclusive_pct"] = (100 * t.FAILED / t.conclusive).round(1)
    t.to_csv(f"{OUT}/verdicts_{name}.csv")
    return t


# 1. Verdict tables per run
for name, df in [("feb09", feb), ("apr03", apr), ("e1_baseline", e1), ("e2_overflow", e2)]:
    t = verdict_table(df, name)
    print(f"\n== {name}\n{t}")

# 2. Reproducibility: same config, three runs
m = feb[["sample_id", "verdict"]].rename(columns={"verdict": "feb"}).merge(
    apr[["sample_id", "verdict"]].rename(columns={"verdict": "apr"}), on="sample_id").merge(
    e1[["sample_id", "verdict"]].rename(columns={"verdict": "e1"}), on="sample_id")
rep = pd.DataFrame({
    "pair": ["feb vs e1", "apr vs e1", "feb vs apr"],
    "agree_pct": [100 * (m.feb == m.e1).mean(), 100 * (m.apr == m.e1).mean(),
                  100 * (m.feb == m.apr).mean()],
    "n_disagree": [(m.feb != m.e1).sum(), (m.apr != m.e1).sum(), (m.feb != m.apr).sum()],
}).round(2)
rep.to_csv(f"{OUT}/reproducibility_same_config.csv", index=False)
print("\n== reproducibility (no overflow check, unwind 10, 60 s)\n", rep)
print(pd.crosstab(m.feb, m.e1))
pd.crosstab(m.feb, m.e1).to_csv(f"{OUT}/crosstab_feb_vs_e1.csv")

# 3. Effect of --overflow-check (e1 vs e2, same bound and timeout)
x = e1[["sample_id", "model", "verdict"]].merge(
    e2[["sample_id", "verdict", "cwes"]], on="sample_id", suffixes=("_e1", "_e2"))
ct = pd.crosstab(x.verdict_e1, x.verdict_e2)
ct.to_csv(f"{OUT}/crosstab_e1_vs_e2.csv")
print("\n== e1 (rows) vs e2 (cols)\n", ct)

# 4. CWE mix of FAILED programs
def cwe_counts(df):
    c = {}
    for s in df[df.verdict == "FAILED"].cwes.dropna():
        for k in str(s).split("|"):
            if k:
                c[k] = c.get(k, 0) + 1
    return pd.Series(c).sort_values(ascending=False)

cw = pd.concat({"e1_baseline": cwe_counts(e1), "e2_overflow": cwe_counts(e2)}, axis=1).fillna(0).astype(int)
cw.to_csv(f"{OUT}/cwe_counts_failed.csv")
print("\n== CWEs among FAILED programs\n", cw.head(8))

# 5. Parse errors: bits/stdc++.h
def has_bits(sid):
    p = os.path.join("derived/cpp", sid)
    with open(p, errors="ignore") as f:
        return bool(re.search(r"bits/stdc\+\+\.h", f.read()))

e2["bits"] = e2.sample_id.map(has_bits)
e2["parse_error"] = e2.verdict.eq("PARSE_ERROR")
pe = e2.groupby("model").agg(n=("bits", "size"), bits_pct=("bits", "mean"),
                              parse_error_pct=("parse_error", "mean"))
pe["parse_error_without_header_pct"] = [
    e2[(e2.model == k) & ~e2.bits].parse_error.mean() for k in pe.index]
pe = (100 * pe.drop(columns="n")).round(1).join(pe[["n"]] * 0 + e2.groupby("model").size().to_frame("n").values)
pe = pe.reindex(MODELS)
pe.to_csv(f"{OUT}/parse_error_by_header_e2.csv")
print("\n== parse errors vs bits/stdc++.h\n", pe)
print("share of all parse errors with the header:",
      round(100 * e2[e2.parse_error].bits.mean(), 1), "%")
print("parse errors among programs with the header:",
      round(100 * e2[e2.bits].parse_error.mean(), 1), "%")

# 6. Cross-tool agreement per source (sanitizer vs ESBMC FAILED)
san = san[san.compiled == True] if "compiled" in san else san  # noqa: E712
san["san_flag"] = san.any_sanitizer_triggered.astype(bool)
rows = []
for run, df in [("e1_baseline", e1), ("e2_overflow", e2)]:
    d = df.merge(san[["sample_id", "san_flag"]], on="sample_id")
    d["esb"] = d.verdict.eq("FAILED")
    d["concl"] = d.verdict.isin(["SUCCESS", "FAILED"])
    for scope, dd in [("sanitizer-run programs", d), ("ESBMC-conclusive only", d[d.concl])]:
        for k in MODELS + ["all"]:
            g = dd if k == "all" else dd[dd.model == k]
            both = (g.san_flag & g.esb).sum()
            uni = (g.san_flag | g.esb).sum()
            rows.append({"run": run, "scope": scope, "source": k, "n": len(g),
                         "sanitizer": int(g.san_flag.sum()), "esbmc_failed": int(g.esb.sum()),
                         "both": int(both), "jaccard": round(both / uni, 3) if uni else None})
jac = pd.DataFrame(rows)
jac.to_csv(f"{OUT}/jaccard_by_source.csv", index=False)
print("\n== Jaccard (sanitizer vs ESBMC FAILED)\n", jac.to_string(index=False))

# 7. Runtime of ESBMC verdicts
rt = e2.groupby("verdict").runtime_seconds.describe()[["count", "mean", "50%", "max"]].round(1)
rt.to_csv(f"{OUT}/runtime_e2_by_verdict.csv")
print("\n== runtime e2\n", rt)
