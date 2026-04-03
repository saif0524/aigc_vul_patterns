# VulBench-CPP: Appendix Content for Replication Package

This document outlines the appendix sections removed from the paper submission to meet the 10+2 page limit. All content supports the three research questions (RQ1: AI vs. human comparison; RQ2: generation stability; RQ3: unique vulnerability classes per tier) and should be included in the replication package at https://anonymous.4open.science/r/bsa-aigcvul-257B

## Appendix A: Per-Model Cppcheck CWE Type Distributions

*Supports RQ1 (AI vs. human comparison) and RQ3 (unique vulnerability classes per tier)*

**Figure A1: Top-10 cppcheck CWE type distributions per model**

Shows four subplots comparing cppcheck CWE findings:
- **Gemma 3 27B IT**: Dominated by code-quality CWEs (398, 563, 570/571)
- **LLaMA 3.3 70B Instruct**: Similar profile to Gemma with style-focused warnings
- **Qwen 2.5 Coder 32B Instruct**: Consistent with other AI models
- **Human**: Exhibits proportionally more security-relevant categories (CWE-119, CWE-252)

**Key Finding**: AI models share nearly identical profiles dominated by code-quality CWEs, while human code exhibits qualitatively different, more security-relevant patterns. This illustrates why static analysis alone cannot distinguish AI from human code.

---

## Appendix B: MITRE Top-25 CWE Prevalence by Model

*Supports RQ1 (AI vs. human comparison)*

**Table B1: MITRE Top-25 CWE prevalence by model and generation**

Fraction of analyzable programs (SUCCESS or FAILED) with at least one MITRE Top-25 CWE detected by cppcheck:

| Model | Gen | Analyzable | Top-25 (%) |
|-------|-----|-----------|-----------|
| **Gemma** | gen_1 | 745 | 0 (0.0%) |
| | gen_2 | 740 | 12 (1.6%) |
| | gen_3 | 753 | 10 (1.3%) |
| **LLaMA** | gen_1 | 849 | 0 (0.0%) |
| | gen_2 | 800 | 8 (1.0%) |
| | gen_3 | 847 | 15 (1.8%) |
| **Qwen** | gen_1 | 850 | 5 (0.6%) |
| | gen_2 | 823 | 19 (2.3%) |
| | gen_3 | 816 | 9 (1.1%) |
| **Human** | soln1 | 851 | 96 (11.3%) |
| | soln2 | 844 | 101 (12.0%) |

**Key Finding**: AI-generated programs have near-zero Top-25 prevalence (0–2.3%), while human solutions reach 11–12%. This reflects that human competitive programming code, written under time pressure without security review, more frequently introduces classic high-severity weaknesses (CWE-119, CWE-190). Conversely, AI-generated code exhibits higher confirmed runtime violations (3.6× gap) but in different vulnerability classes not prominently featured in MITRE Top-25 rankings.

---

## Appendix C: Static Cross-Tool Agreement (Cppcheck vs. Clang-tidy)

*Supports RQ3 (unique vulnerability classes per tier)*

**Table C1: Static cross-tool agreement between cppcheck and clang-tidy**

Agreement = (Both flagged + Neither flagged) / Total

| Model | Both | Cppcheck only | Clang-tidy only | Neither | Total | Agreement |
|-------|------|---------------|-----------------|---------|-------|-----------|
| Gemma | 360 | 661 | 260 | 957 | 2238 | 58.8% |
| LLaMA | 369 | 471 | 469 | 1187 | 2496 | 62.3% |
| Qwen | 364 | 544 | 376 | 1205 | 2489 | 63.0% |
| Human | 543 | 222 | 461 | 469 | 1695 | 59.7% |

**Key Finding**: Across all models, 59–63% agreement means the two static tools disagree on roughly 40% of programs, echoing the near-zero Jaccard agreement between dynamic and formal verification tiers. Cppcheck-only findings dominate for AI models (661, 471, 544), while clang-tidy-only findings are substantial for human code (461), driven by `modernize-*` and `bugprone-*` checks that detect richer data-flow patterns in more complex human code.

---

## Appendix D: Problem Category Distribution

*General benchmark characterization; supports reproducibility and generalization across all RQs*

**Table D1: Benchmark composition by problem category (851 tasks)**

Categories are derived from Codeforces problem metadata. Many tasks are labeled with multiple categories (1,382 total category instances across 851 tasks, average 1.63 per task).

| Problem Category | Count | % of Tasks |
|-----------------|-------|-----------|
| Implementation | 158 | 18.6% |
| Greedy | 134 | 15.7% |
| Math | 125 | 14.7% |
| Dynamic Programming | 114 | 13.4% |
| Brute Force | 94 | 11.0% |
| Constructive Algorithms | 85 | 10.0% |
| Data Structures | 81 | 9.5% |
| Graphs | 65 | 7.6% |
| Sorting | 61 | 7.2% |
| Binary Search | 57 | 6.7% |
| DFS and Similar | 48 | 5.6% |
| Trees | 40 | 4.7% |
| Strings | 38 | 4.5% |
| Number Theory | 34 | 4.0% |
| Bitmasks | 28 | 3.3% |
| Two Pointers | 28 | 3.3% |
| Combinatorics | 27 | 3.2% |
| Disjoint Set Union (DSU) | 22 | 2.6% |
| Geometry | 20 | 2.3% |
| Divide and Conquer | 16 | 1.9% |
| *(16 additional categories with <1.9% each)* | — | — |

**Key Finding**: The 851 competitive programming tasks span a diverse range of algorithmic problem types. Implementation, greedy algorithms, and mathematical problems together account for 48.9% of the benchmark. Data structure and graph algorithm problems add another 19.3%. This diversity ensures the benchmark exercises multiple code patterns, from array indexing and pointer arithmetic to complex graph traversals, capturing the breadth of vulnerability-prone patterns in AI-generated code.

---

## Integration Notes for Replication Package

All of the above appendix material should be included in the replication package along with:

1. **Raw analysis outputs** (CSV files for each tool tier)
2. **Evaluation scripts** (for reproducibility)
3. **Annotated results** (cross-reference tables between tools)
4. **This appendix.md** (for context and additional findings)

The main paper (main.tex) addresses three core research questions:
- **RQ1**: AI vs. human comparison — vulnerability rates under multi-tier verification
- **RQ2**: Generation Stability — reproducibility of vulnerability patterns across independent generations
- **RQ3**: Unique Vulnerability Classes per Tier — what each verification tier detects and how distributions differ between AI and human code

These appendix materials support practitioners who want to:
- Understand the diversity of the benchmark (Appendix D)
- Conduct deeper multi-tool analyses (Appendix C)
- Compare against MITRE Top-25 standards (Appendix B)
- Investigate per-model CWE patterns (Appendix A)

