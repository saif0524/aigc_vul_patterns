# Revision experiments (ICSE 2027 #5449)

New analyses for the major revision. Nothing here changes the original results in `results/` or `analysis/`.

| Folder | Purpose |
|---|---|
| `esbmc/` | Rerun of ESBMC under fixed, recorded settings; coverage and reproducibility analysis |
| `esbmc/reference/` | Copies of the earlier ESBMC summaries, kept for comparison |
| `esbmc/runs/<run_name>/` | One folder per run: `json/` (per-file ESBMC output), `summary.csv`, `meta.json` (flags, machine load, timestamps) |

## Why the ESBMC rerun

The paper's ESBMC numbers (661 FAILED) come from a first run committed on Feb 9 (`394975f9`). That run used no `--overflow-check`, although the paper's listing shows it. An April commit (`86aa9911`) replaced the summary files with a rerun of the same configuration that gives 384 FAILED. The unwind-20 run turned overflow checking on at the same time as it raised the bound.

## Reference runs

| File | Flags | FAILED | SUCCESS | TIMEOUT | PARSE_ERROR |
|---|---|---|---|---|---|
| `esbmc_summary_feb09_run1.csv` | unwind 10, 60 s, no overflow check | 661 | 1,551 | 1,621 | 5,039 |
| `esbmc_summary_apr03_run2.csv` | unwind 10, 60 s, no overflow check | 384 | 1,296 | 2,154 | 5,039 |
| `esbmc_summary_u20_t120.csv` | unwind 20, 120 s, overflow check | 832 | 663 | 2,339 | 5,039 |

## Reported run

`esbmc/runs/e2_overflow_u10_t60` (overflow check on, unwind 10, 60 s) is the run the revised paper reports. All findings are for zero-shot generation; see `esbmc/revision_experiments.md`. `esbmc/runs/e1_baseline_u10_t60` (overflow check off) and `pilot_baseline` are kept on disk but not reported.

## Running

From the repository root:

```bash
python3.11 revision_experiments/esbmc/run_esbmc_config.py \
    --run-name <name> [--no-overflow-check] [--unwind N] [--timeout S] --jobs 8
```

The script resumes if interrupted. Do not run two configurations at the same time: timeouts depend on machine load.
