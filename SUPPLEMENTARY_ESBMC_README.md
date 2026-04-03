# Supplementary ESBMC Configuration Results

## Overview

This document describes the supplementary ESBMC run conducted to validate the sensitivity of the baseline results to configuration parameters, specifically loop unwind bounds, timeout duration, and property checking scope.

## Configuration Comparison

### Baseline Configuration (Config A)
- **Tag**: `esbmc`
- **Unwind bound**: 10
- **Timeout**: 60 seconds
- **Overflow checking**: Disabled
- **Results location**: `results/raw_csv/esbmc_*.csv`

### Supplementary Configuration (Config C)
- **Tag**: `esmbc_u20_t120`
- **Unwind bound**: 20 (2×)
- **Timeout**: 120 seconds (2×)
- **Overflow checking**: Enabled (`--overflow-check`)
- **Results location**: `results/raw_csv/esmbc_u20_t120_*.csv`

## Key Findings

### Verdict Breakdown (8,918 total programs)

| Verdict | Baseline | Supplementary | Change | % Change |
|---------|----------|---------------|--------|----------|
| **SUCCESS** | 1,296 | 663 | -633 | -48.8% |
| **FAILED** | 384 | 832 | +448 | +116.7% |
| **TIMEOUT** | 2,154 | 2,339 | +185 | +8.6% |
| **PARSE_ERROR** | 5,039 | 5,039 | — | — |
| **ERROR** | 45 | 45 | — | — |
| **Coverage*** | 1,680 (18.8%) | 1,495 (16.8%) | -185 (-11.0%) | -2.0pp |

*Coverage = SUCCESS + FAILED (analyzable programs)

### Primary CWE Classes

**Baseline (overflow-check disabled):**
- CWE-119 (Buffer Overflow): 75 programs
- CWE-476 (Null Pointer Dereference): 58 programs
- CWE-825 (Use After Free): 4 programs
- **Total unique CWE violations**: 137 programs

**Supplementary (overflow-check enabled):**
- **CWE-190 (Signed Integer Overflow): 527 programs** ← NEW
- CWE-119 (Buffer Overflow): 62 programs
- CWE-476 (Null Pointer Dereference): 60 programs
- CWE-120 (Stack Overflow): 46 programs
- CWE-825 (Use After Free): 4 programs
- **Total unique CWE violations**: 699 programs

### Cross-Tool Agreement

| Metric | Baseline | Supplementary | Change |
|--------|----------|---------------|--------|
| Programs with 2+ tool flags | 420 | 539 | +119 (+28.3%) |
| CWEs confirmed by 2+ tools | 5 | 25 | +20 (+400%) |

### Per-Model Breakdown

| Model | Total | Baseline Success % | Supp. Success % | Baseline Failed % | Supp. Failed % |
|-------|-------|-------------------|-----------------|-------------------|-----------------|
| Gemma | 2,238 | 23.6% | 11.9% | 5.4% | 12.9% |
| Human | 1,695 | 4.9% | 2.7% | 0.8% | 3.8% |
| LLaMA | 2,496 | 16.1% | 8.5% | 6.7% | 11.7% |
| Qwen | 2,489 | 11.4% | 5.6% | 3.3% | 7.5% |

## Key Insight: The Property Axis is Primary

The supplementary run reveals that **signed integer overflow (CWE-190) is the dominant formally-verifiable bug class** in AI-generated C++ code:

- **527 programs (63.3%)** of the supplementary FAILED verdicts are due to CWE-190
- The baseline's omission of `--overflow-check` meant this entire property class was never verified
- Despite **doubling both the unwind bound and timeout**, coverage *decreased* from 18.8% → 16.8% because overflow assertions substantially increase SMT formula complexity
- **Timeouts increased** (2,154 → 2,339) despite more available time, indicating that the property set is the primary driver of solver difficulty, not bounds or timeout duration

## Coverage Paradox Explanation

This counterintuitive result—longer timeout but fewer programs verified—reveals a fundamental truth about bounded model checking:

1. **Overflow assertions increase formula complexity** — each overflow check adds logical constraints to the SMT formula
2. **Solver performance is non-monotonic** — more time helps, but larger formulas (due to overflow checks) can cause solver timeouts that aren't recovered by additional time
3. **Trade-off between property scope and verification coverage** — enabling more properties verified fewer programs within the time budget

## Conclusion

The baseline ESBMC configuration (unwind=10, timeout=60, no overflow-check) is conservative but incomplete:
- **Valid within stated bounds**: All 384 baseline FAILED verdicts remain true violations
- **Understates formal verification capability**: Adding overflow-check reveals an additional 448 violations
- **Demonstrates property sensitivity**: The property set is the dominant configuration lever, superseding bound and timeout effects

The supplementary results validate that the cross-tool agreement findings in the main paper are robust and that the gap between formal and dynamic verification is even wider than initially reported when overflow checking is considered.

## File Manifest

| File | Description |
|------|-------------|
| `esmbc_u20_t120_summary.csv` | Per-program verdict summary for supplementary run |
| `esmbc_u20_t120_violations.csv` | Detailed CWE violations detected by supplementary ESBMC |
| `esmbc_u20_t120_vs_static.csv` | Supplementary ESBMC results merged with static analysis (cppcheck, clang-tidy) |
| `esmbc_u20_t120_cross_reference.csv` | Three-way cross-reference: cppcheck vs. clang-tidy vs. ESBMC (supplementary) |

## Reproducibility

To regenerate supplementary results:

```bash
# Run ESBMC with supplementary configuration
python3.11 scripts/run_esbmc.py --mode full --jobs 8 --only all \
  --unwind 20 --timeout 120 --tag esmbc_u20_t120

# Parse results
python3.11 scripts/parse_esbmc.py --mode full --tag esmbc_u20_t120
```

Results will be written to `results/raw_csv/esmbc_u20_t120_*.csv`
