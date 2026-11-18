# ESBMC rerun: findings (Oct 26, 2026)

**Scope.** Every result below is for **zero-shot** generation: one fixed prompt, no security guidance, no examples, temperature 1.0, three open-weight models (Gemma 3 27B IT, LLaMA 3.3 70B Instruct, Qwen 2.5 Coder 32B Instruct). Nothing here says how the models behave under few-shot, security-aware or other prompting; the prompting experiment (Task 2) tests that. The paper should carry this qualifier wherever it states the formal-tier findings.

**Reported run:** `runs/e2_overflow_u10_t60`. ESBMC 8.0.0, `--overflow-check`, unwind 10, timeout 60 s, 16 workers, all 8,918 programs, idle machine. Settings and timestamps are in `runs/e2_overflow_u10_t60/meta.json`. Tables are in `tables/`.

The no-overflow baseline rerun (`runs/e1_baseline_u10_t60`) is not part of the reporting and is not used below. Its files are kept on disk.

| Verdict | Programs | Share |
|---|---|---|
| PARSE_ERROR | 5,039 | 56.5% |
| TIMEOUT | 1,897 | 21.3% |
| FAILED | 1,103 | 12.4% |
| SUCCESS | 832 | 9.3% |
| ERROR | 47 | 0.5% |

Conclusive (SUCCESS or FAILED): 1,935 programs, 21.7% of the benchmark.

## 1. Formal-tier results under zero-shot generation

Failure rate among conclusive programs:

| Source | Conclusive | FAILED | Rate | Coverage |
|---|---|---|---|---|
| Gemma | 745 | 389 | 52.2% | 33.3% |
| LLaMA | 659 | 403 | 61.2% | 26.4% |
| Qwen | 410 | 240 | 58.5% | 16.5% |
| Human | 121 | 71 | 58.7% | 7.1% |
| AI total | 1,814 | 1,032 | 56.9% | |

- Under zero-shot generation, ESBMC with overflow checking shows no AI-vs-human difference in the failure rate (56.9% vs. 58.7%). This is descriptive: 121 human programs are conclusive, and conclusive coverage depends on who wrote the code (section 3).
- The paper currently says the formal tier shows the same direction as the sanitizers (AI 25.9-36.7% vs. human 18.8%). Those numbers come from a run without overflow checking and do not match the flags the paper lists. Replace them.
- 641 of the 1,103 FAILED programs carry CWE-190. The others are CWE-119 (69), CWE-476 (77), CWE-120 (45) and CWE-825 (5).

## 2. Paper statements to correct

- **Signed overflow:** ESBMC with `--overflow-check` does flag it. Example 2 ("Blocked Points", `4*n*(n+1)`) is FAILED with CWE-190 in all three Gemma generations, so the example's claim that ESBMC returns SUCCESS is wrong. Replace the example and rewrite the statements at main.tex L312, L517 and L574.
- **Unwind 20 / 120 s:** against this run, unwind 20 gives fewer FAILED (832 vs. 1,103). 289 programs that fail at unwind 10 time out at unwind 20 even with 120 s; only 18 move toward FAILED. The paper's claim that bound and timeout are the main sensitivity axes, and that deeper exploration finds more, is not supported by this comparison.
- **Example 1 ("Bear and Raspberry"):** FAILED with CWE-190 in all three generations. Consistent with the text.
- **Example 3 ("String Multiplication"):** FAILED (CWE-476) for gen_1 only; gen_2 times out and gen_3 is SUCCESS. Say it is one generation.
- **Numbers to regenerate** from this run: the verdict table, Table II (ESBMC column), 661, 598, 576, 63, the Jaccard values, and the formal row of the GLMM (`build_glmm_dataset.py` reads the April `esbmc_summary.csv`).

## 3. Coverage (for the new subsection)

- Every program containing `<bits/stdc++.h>` gets PARSE_ERROR (100%). The header explains 66.8% of parse errors.

| Source | Has header | Parse-error rate | Without header |
|---|---|---|---|
| Gemma | 0.0% | 22.7% | 22.7% |
| LLaMA | 19.0% | 51.5% | 40.1% |
| Qwen | 58.8% | 69.2% | 25.3% |
| Human | 84.1% | 89.9% | 36.1% |

- Human code is the least covered (7.1%) and the most likely to include the header, so the conclusive subset does not represent either population.
- Runtime: PARSE_ERROR finishes in 0.5 s on average; FAILED has a median of 3.8 s; every TIMEOUT ends at the 60 s limit (`tables/runtime_e2_by_verdict.csv`).

## 4. Cross-tool agreement under zero-shot generation (sanitizer vs. ESBMC FAILED)

Population: the 8,245 programs that compiled for the sanitizer tier. The paper uses a 4,295-program subset; one definition is needed.

| Source | Sanitizer | ESBMC FAILED | Both | Jaccard | Jaccard, conclusive only |
|---|---|---|---|---|---|
| Gemma | 173 | 388 | 31 | 0.058 | 0.075 |
| LLaMA | 217 | 401 | 24 | 0.040 | 0.057 |
| Qwen | 224 | 240 | 15 | 0.033 | 0.061 |
| Human | 43 | 70 | 1 | 0.009 | 0.014 |
| All | 657 | 1,099 | 71 | 0.042 | 0.062 |

Agreement is low for every source, human included, which answers Reviewer C's question about whether low agreement is AI-specific. The human estimate rests on one overlapping program, so it should not be compared with the AI values.

## 5. Still to do

1. Rebuild the regression input and the tables above from this run; fix the cross-tool subset definition.
2. Header-substitution rerun and parse-error categories.
3. Rewrite Example 2, the overflow statements and the unwind-sensitivity paragraph.
4. Scope the formal-tier findings in the abstract, RQ1 and the Conclusion to zero-shot generation.
