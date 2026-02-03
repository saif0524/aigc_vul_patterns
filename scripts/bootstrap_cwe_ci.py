# scripts/bootstrap_cwe_ci.py
import pandas as pd
import numpy as np

N_BOOT = 2000
ALPHA = 0.05

df = pd.read_csv("results/raw_csv/cppcheck_program_level.csv")



df = df[df["severity"].isin(["warning", "error"])]

# program-level indicator: has at least one CWE
prog = (
    df.groupby(["model", "generation", "instruction_id"])
      .size()
      .reset_index(name="n_cwe")
)
prog["has_cwe"] = (prog["n_cwe"] > 0).astype(int)

rows = []

for (model, gen), g in prog.groupby(["model", "generation"]):
    x = g["has_cwe"].values
    n = len(x)

    boots = []
    for _ in range(N_BOOT):
        sample = np.random.choice(x, size=n, replace=True)
        boots.append(sample.mean())

    lo = np.percentile(boots, 100 * (ALPHA / 2))
    hi = np.percentile(boots, 100 * (1 - ALPHA / 2))

    rows.append({
        "model": model,
        "generation": gen,
        "mean_prevalence": x.mean(),
        "ci_low": lo,
        "ci_high": hi,
        "n_programs": n
    })

out = pd.DataFrame(rows)
out.to_csv("results/tables/bootstrap_cwe_ci.csv", index=False)
print("Wrote results/tables/bootstrap_cwe_ci.csv")