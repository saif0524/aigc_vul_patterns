#!/usr/bin/env python3
"""
Mixed-effects modeling for the ICSME resubmission (RQ1: AI vs human security).

For each security tier we fit a logistic regression of the binary violation
outcome on `source` (AI vs human) plus candidate covariates, with the
within-problem clustering handled two complementary ways:

  (A) GEE  : marginal logistic regression, exchangeable working correlation
             clustered on problem_key -> clustering-robust SEs and Wald p-values.
             Used for BACKWARD ELIMINATION (drop highest-p covariate until all
             remaining covariates significant at alpha; `source` is forced in).

  (B) BinomialBayesMixedGLM : a true mixed-effects (conditional) logistic model
             with a random intercept for problem_key, reported as the headline
             "mixed-effects regression" the reviewers asked for.

Outcomes:
  san_violation  (denominator: san_run == 1)
  esbmc_failed   (denominator: esbmc_conclusive == 1)
  cppcheck_flag  (denominator: all programs)
"""
import warnings
import numpy as np
import pandas as pd
import statsmodels.api as sm
import statsmodels.formula.api as smf
from statsmodels.genmod.bayes_mixed_glm import BinomialBayesMixedGLM

warnings.simplefilter("ignore")
ALPHA = 0.05
CSV = "results/raw_csv/glmm_program_level.csv"

df = pd.read_csv(CSV)
# standardize continuous covariates so estimates are comparable / converge well
for c in ["pass_rate", "loc", "n_tests"]:
    df[c] = pd.to_numeric(df[c], errors="coerce")
df["loc_z"] = (df["loc"] - df["loc"].mean()) / df["loc"].std()
df["ntests_z"] = (df["n_tests"] - df["n_tests"].mean()) / df["n_tests"].std()
# source as 0/1 (AI = 1), human = reference
df["AI"] = (df["source"] == "AI").astype(int)

CANDIDATES = ["AI", "pass_rate", "loc_z", "ntests_z"]
FORCED = ["AI"]


def subset(outcome, denom):
    d = df[df[denom] == 1].copy()
    d = d.dropna(subset=[outcome] + CANDIDATES)
    d[outcome] = d[outcome].astype(int)
    return d


def backward_gee(d, outcome):
    """Backward elimination on GEE Wald p-values; FORCED terms never dropped."""
    terms = list(CANDIDATES)
    while True:
        formula = f"{outcome} ~ " + " + ".join(terms)
        m = smf.gee(formula, groups="problem_key", data=d,
                    cov_struct=sm.cov_struct.Exchangeable(),
                    family=sm.families.Binomial()).fit()
        p = m.pvalues.drop("Intercept")
        droppable = p[[t for t in p.index if t not in FORCED]]
        if droppable.empty or droppable.max() <= ALPHA:
            return m, terms
        worst = droppable.idxmax()
        terms.remove(worst)


def fit_mixed(d, outcome, terms):
    formula = f"{outcome} ~ " + " + ".join(terms)
    vc = {"problem": "0 + C(problem_key)"}
    m = BinomialBayesMixedGLM.from_formula(
        formula, {"problem": "0 + C(problem_key)"}, d).fit_vb()
    return m


def report(outcome, denom):
    d = subset(outcome, denom)
    n_prob = d["problem_key"].nunique()
    print("\n" + "=" * 72)
    print(f"OUTCOME: {outcome}   (n={len(d)} programs, {n_prob} problems, "
          f"events={int(d[outcome].sum())})")
    print("=" * 72)

    gee, kept = backward_gee(d, outcome)
    print(f"\n[A] GEE clustered logistic — backward-eliminated model: {' + '.join(kept)}")
    or_tab = pd.DataFrame({
        "coef": gee.params,
        "OR": np.exp(gee.params),
        "p": gee.pvalues,
    })
    print(or_tab.to_string(float_format=lambda x: f"{x:.4f}"))
    ai_or = np.exp(gee.params["AI"])
    lo, hi = np.exp(gee.conf_int().loc["AI"])
    print(f"    --> AI odds ratio = {ai_or:.2f}  (95% CI {lo:.2f}-{hi:.2f}), "
          f"p = {gee.pvalues['AI']:.3g}")

    print(f"\n[B] Mixed-effects logistic (random intercept | problem_key): "
          f"{outcome} ~ {' + '.join(kept)}")
    try:
        mm = fit_mixed(d, outcome, kept)
        sm_tab = pd.DataFrame({
            "post_mean": mm.fe_mean,
            "OR": np.exp(mm.fe_mean),
            "post_sd": mm.fe_sd,
        }, index=mm.model.exog_names[:len(mm.fe_mean)])
        print(sm_tab.to_string(float_format=lambda x: f"{x:.4f}"))
    except Exception as e:
        print(f"    [mixed model failed to converge: {e}]")


if __name__ == "__main__":
    report("san_violation", "san_run")
    report("esbmc_failed", "esbmc_conclusive")
    report("cppcheck_flag", "compiled")  # all compiled programs get cppcheck
