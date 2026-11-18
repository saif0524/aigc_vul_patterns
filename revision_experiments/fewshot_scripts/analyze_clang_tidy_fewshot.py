#!/usr/bin/env python3
"""Analysis of the clang-tidy results for the revision experiments.

The paper's clang-tidy column (Table II) counts a program as flagged when clang-tidy
reports at least one `bugprone-*` or `clang-analyzer-*` (security) diagnostic. Almost every
program also gets `modernize-*` or `performance-*` style diagnostics, so "any diagnostic" is
about 100% for every source and is not used. This script applies the paper's definition to

  * zero-shot AI programs on the 100 sampled tasks (all three generations, and gen_1 only),
  * the few-shot programs,
  * human solutions on the same tasks,
  * the full benchmark (to reproduce Table II and look for what drives the human rate).

Writes to revision_experiments/analysis/fewshot/:
    clang_tidy_flag_rates.csv    rates by group and check family
    clang_tidy_regression.csv    clustered (GEE, by task) odds ratios
    clang_tidy_top_checks.csv    per-check program shares, AI vs human, full benchmark

Run from the repository root:
    python3.11 revision_experiments/fewshot_scripts/analyze_clang_tidy_fewshot.py
"""
import re
import warnings

import numpy as np
import pandas as pd
import statsmodels.api as sm
import statsmodels.formula.api as smf
import yaml

import common

warnings.simplefilter("ignore")
RAW = common.REPO / "results" / "raw_csv"
SAMPLE = common.REPO / "revision_experiments" / "fewshot_100_sample"
OUT = common.ANALYSIS_ROOT
norm = lambda s: re.sub(r"[^a-z0-9]", "", str(s).lower())
keys = set(pd.read_csv(SAMPLE / "sample_tasks.csv").norm_key)

FAMILIES = ["bugprone", "analyzer", "performance", "modernize"]


# ------------------------------------------------------------------ few-shot
def load_fewshot():
    rows = []
    for model in common.MODELS:
        for ym in sorted((OUT / "clang_tidy" / model).glob("gen_*/*.yaml")):
            d = (yaml.safe_load(ym.read_text(errors="replace")) or {}).get("Diagnostics", []) or []
            names = [x.get("DiagnosticName", "") for x in d]
            cpp = common.SRC_ROOT / model / ym.parent.name / (ym.stem + ".cpp")
            loc = sum(1 for l in cpp.read_text(errors="replace").splitlines() if l.strip()) if cpp.exists() else np.nan
            rows.append(dict(
                group="few-shot", model=model, task=norm(ym.stem.split("_", 1)[1]),
                bugprone=sum(n.startswith("bugprone-") for n in names),
                analyzer=sum(n.startswith("clang-analyzer-") for n in names),
                performance=sum(n.startswith("performance-") for n in names),
                modernize=sum(n.startswith("modernize-") for n in names),
                compile_error=int(any(x.get("Level") == "Error" for x in d)), nloc=loc,
                checks=set(n for n in names if n.startswith(("bugprone-", "clang-analyzer-")))))
    return pd.DataFrame(rows)


# ------------------------------------------------------------------ zero-shot (main study)
def load_main():
    c = pd.read_csv(RAW / "clang_tidy_summary.csv")
    for col in ["bugprone", "analyzer", "performance", "modernize", "errors"]:
        c[col] = pd.to_numeric(c[col], errors="coerce").fillna(0)
    c["sample_id"] = c.file
    g = pd.read_csv(RAW / "glmm_program_level.csv")[["sample_id", "loc"]].rename(columns={"loc": "nloc"})
    g["sample_id"] = g.sample_id.str.replace(r"\.cpp$", "", regex=True)
    c = c.merge(g, on="sample_id", how="left")
    det = pd.read_csv(RAW / "clang_tidy_detailed.csv", usecols=["file", "diagnostic_name"])
    det = det[det.diagnostic_name.str.startswith(("bugprone-", "clang-analyzer-"), na=False)]
    chk = det.groupby("file").diagnostic_name.agg(set)
    c["checks"] = c.file.map(chk).apply(lambda s: s if isinstance(s, set) else set())
    c["task"] = c.problem_key.map(norm)
    c["compile_error"] = (c.errors > 0).astype(int)
    c["group"] = np.where(c.model == "human", "human", "zero-shot")
    return c


def flag(df):
    return ((df.bugprone > 0) | (df.analyzer > 0)).astype(int)


def rate_row(label, df):
    r = {"group": label, "programs": len(df), "flagged_pct": round(100 * flag(df).mean(), 1)}
    for f in FAMILIES:
        r[f + "_pct"] = round(100 * (df[f] > 0).mean(), 1)
    r["clang_compile_error_pct"] = round(100 * df.compile_error.mean(), 1)
    ok = df[df.compile_error == 0]
    r["flagged_pct_no_compile_error"] = round(100 * flag(ok).mean(), 1)
    return r


def gee(df, y, formula, term):
    d = df.copy()
    d["y"] = y
    r = smf.gee("y ~ " + formula, groups="task", data=d, family=sm.families.Binomial(),
                cov_struct=sm.cov_struct.Exchangeable()).fit()
    lo, hi = r.conf_int().loc[term]
    return dict(n=len(d), OR=round(float(np.exp(r.params[term])), 2), lo=round(float(np.exp(lo)), 2),
                hi=round(float(np.exp(hi)), 2), p=float(r.pvalues[term]))


def main():
    fs, mn = load_fewshot(), load_main()
    zs_s = mn[(mn.group == "zero-shot") & mn.task.isin(keys)].copy()
    hu_s = mn[(mn.group == "human") & mn.task.isin(keys)].copy()
    zs1 = zs_s[zs_s.gen == "gen_1"]

    # ---- rates
    rates = [rate_row("few-shot AI", fs), rate_row("zero-shot AI (3 generations)", zs_s),
             rate_row("zero-shot AI (gen_1)", zs1), rate_row("human (same tasks)", hu_s)]
    for m in common.MODELS:
        rates.append(rate_row(f"few-shot {m}", fs[fs.model == m]))
        rates.append(rate_row(f"zero-shot {m} (3 generations)", zs_s[zs_s.model == m]))
    rates.append(rate_row("full benchmark: AI", mn[mn.group == "zero-shot"]))
    rates.append(rate_row("full benchmark: human", mn[mn.group == "human"]))
    for m in common.MODELS:
        rates.append(rate_row(f"full benchmark: {m}", mn[mn.model == m]))
    R = pd.DataFrame(rates)
    R.to_csv(OUT / "clang_tidy_flag_rates.csv", index=False)
    print(R.to_string(index=False))

    # ---- regressions (clustered by task)
    both = pd.concat([fs.assign(few=1), zs_s.assign(few=0)], ignore_index=True)
    both["y"] = flag(both)
    both["loc_z"] = (both["nloc"] - both["nloc"].mean()) / both["nloc"].std()
    ai_h = pd.concat([fs.assign(ai=1), zs_s.assign(ai=1), hu_s.assign(ai=0)], ignore_index=True)
    ai_h["y"] = flag(ai_h)
    ai_h["loc_z"] = (ai_h["nloc"] - ai_h["nloc"].mean()) / ai_h["nloc"].std()
    ai_h["few"] = (ai_h.group == "few-shot").astype(int)
    full = mn.copy()
    full["y"] = flag(full)
    full["ai"] = (full.group == "zero-shot").astype(int)
    full["loc_z"] = (full["nloc"] - full["nloc"].mean()) / full["nloc"].std()
    full = full.dropna(subset=["loc_z"])
    reg = []
    def add(name, res): reg.append(dict(comparison=name, **res))
    add("few-shot vs zero-shot AI (sample tasks)", gee(both, both.y, "few", "few"))
    add("few-shot vs zero-shot AI, adjusted for LOC", gee(both.dropna(subset=["loc_z"]), both.dropna(subset=["loc_z"]).y, "few + loc_z", "few"))
    add("zero-shot AI vs human (sample tasks)", gee(ai_h[ai_h.few == 0], ai_h[ai_h.few == 0].y, "ai", "ai"))
    fs_hu = pd.concat([ai_h[ai_h.ai == 0], ai_h[ai_h.few == 1]])
    add("few-shot AI vs human (sample tasks)", gee(fs_hu, fs_hu.y, "ai", "ai"))
    add("full benchmark: AI vs human", gee(full, full.y, "ai", "ai"))
    add("full benchmark: AI vs human, adjusted for LOC", gee(full, full.y, "ai + loc_z", "ai"))
    ok = full[full.compile_error == 0]
    add("full benchmark: AI vs human, programs clang compiled, adjusted for LOC", gee(ok, ok.y, "ai + loc_z", "ai"))
    G = pd.DataFrame(reg)
    G.to_csv(OUT / "clang_tidy_regression.csv", index=False)
    print("\n", G.to_string(index=False))

    # ---- which checks differ (full benchmark, program-level share)
    def share(df):
        c = {}
        for s in df.checks:
            for n in s:
                c[n] = c.get(n, 0) + 1
        return pd.Series(c) / len(df)
    A, H = share(full[full.ai == 1]), share(full[full.ai == 0])
    T = pd.DataFrame({"ai_pct": 100 * A, "human_pct": 100 * H}).fillna(0)
    T["diff_human_minus_ai"] = T.human_pct - T.ai_pct
    T = T.sort_values("diff_human_minus_ai", ascending=False).round(1)
    T.to_csv(OUT / "clang_tidy_top_checks.csv")
    print("\nchecks most over-represented in human code:\n", T.head(8).to_string())
    print("\nchecks most over-represented in AI code:\n", T.tail(5).to_string())
    fa = share(fs)
    print("\nfew-shot top checks (% of few-shot programs):\n", (100 * fa).round(1).sort_values(ascending=False).head(8).to_string())


if __name__ == "__main__":
    main()
