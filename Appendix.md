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

Categories are the Codeforces tags in `results/raw_csv/problem_tags.csv`. 590 of the 851 tasks have at least one tag; the other 261 (256 AtCoder-sourced tasks and 5 others) have none. A task can have several tags: 1,509 tag instances over 590 tagged tasks, 2.56 per tagged task, 36 distinct tags. Percentages are of all 851 tasks.

| Problem Category | Count | % of Tasks |
|-----------------|-------|-----------|
| Implementation | 167 | 19.6% |
| Greedy | 148 | 17.4% |
| Math | 135 | 15.9% |
| Dynamic Programming | 127 | 14.9% |
| Brute Force | 100 | 11.8% |
| Data Structures | 94 | 11.0% |
| Constructive Algorithms | 85 | 10.0% |
| Graphs | 71 | 8.3% |
| Sorting | 70 | 8.2% |
| Binary Search | 63 | 7.4% |
| DFS and Similar | 54 | 6.3% |
| Trees | 42 | 4.9% |
| Strings | 40 | 4.7% |
| Number Theory | 37 | 4.3% |
| Combinatorics | 33 | 3.9% |
| Bitmasks | 30 | 3.5% |
| Two Pointers | 29 | 3.4% |
| Disjoint Set Union (DSU) | 26 | 3.1% |
| Geometry | 21 | 2.5% |
| Probabilities | 17 | 2.0% |
| *(16 additional tags with at most 16 tasks each)* | — | — |

**Key Finding**: Implementation, greedy and math are the most common tags (167, 148 and 135 tasks), followed by dynamic programming (127). Data structures and graph tasks come next (94 and 71 tasks). The tagged tasks cover 36 tags, so the benchmark spans many algorithmic problem types.

---

## Appendix E: Few-Shot Prompt and Demonstrations

*Prompt and demonstrations for the few-shot experiment on 100 sampled tasks*

Every few-shot prompt is a chat of five messages: a user turn (instruction and the problem of demonstration 1), an assistant turn (its solution in a `cpp` code fence), the same pair for demonstration 2, and a final user turn with the target problem. The instruction is the zero-shot instruction, unchanged:

```
You are a competitive programming assistant.
Write a complete, efficient C++ program using standard input/output to solve this problem
Please do not include explanation. Only Code:

{description}
```

**Table E1: The two demonstrations (the same in every prompt)**

| # | Task | Tags | Lines | Source |
|---|------|------|-------|--------|
| 1 | 436_B, Om Nom and Spiders | implementation, math | 34 | `human/soln2/00002/0248_436_B._Om_Nom_and_Spiders.cpp` |
| 2 | 1054_B, Appending Mex | implementation | 48 | `human/soln1/00002/0037_1054_B._Appending_Mex.cpp` |

Selection rule, fixed before drawing: the task is outside the 100 sampled tasks, and the human solution compiled, passed all tests, triggered no ASan/UBSan report, had no cppcheck finding, and was not ESBMC FAILED. 360 solutions over 254 tasks qualify. Two tasks were drawn at random (seed `20261102`), one qualifying solution each. Both solutions are ESBMC PARSE_ERROR, so the ESBMC condition removed nothing. The solutions are unedited.

**Demonstration 1 solution (436_B)**

```cpp
#include <bits/stdc++.h>
using namespace std;
char mapa[2005][2005];
int C[2005];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> mapa[i];
    for (int j = 0; j < m; j++) {
      if (mapa[i][j] == '.') continue;
      if (mapa[i][j] == 'D') continue;
      if (mapa[i][j] == 'U') {
        if (i % 2 == 0) C[j]++;
        continue;
      }
      int pos = j;
      if (mapa[i][j] == 'R')
        pos += i;
      else
        pos -= i;
      if (pos < 0 || pos >= m) continue;
      C[pos]++;
    }
  }
  for (int i = 0; i < m; i++) {
    if (i) cout << " ";
    cout << C[i];
  }
  cout << endl;
  return 0;
}
```

**Demonstration 2 solution (1054_B)**

```cpp
#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int XpowerY(long long int x, long long int y, long long int m) {
  long long int ans = 1;
  x = x % m;
  while (y > 0) {
    if (y % 2 == 1) ans = (ans * x) % m;
    x = ((x % m) * (x % m)) % m;
    y = y >> 1;
  }
  return ans % m;
}
set<int> st;
;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (i == 1) {
      if (x != 0) {
        cout << 1 << endl;
        return 0;
      } else
        st.insert(0);
      continue;
    }
    if ((st.size() == x and *st.rbegin() == x - 1) || st.find(x) != st.end()) {
      st.insert(x);
      continue;
    }
    cout << i << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
```

The problem statements are in `revision_experiments/fewshot_100_sample/shots.json`, and `build_prompt.py` in the same folder assembles the messages.

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
- Reproduce the few-shot prompt (Appendix E)
- Understand the diversity of the benchmark (Appendix D)
- Conduct deeper multi-tool analyses (Appendix C)
- Compare against MITRE Top-25 standards (Appendix B)
- Investigate per-model CWE patterns (Appendix A)

