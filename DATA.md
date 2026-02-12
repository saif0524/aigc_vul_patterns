# Data Documentation

## Overview

This project uses **completely frozen datasets** in the `data/` folder. All data—problem instructions, testcases, human solutions, and AI-generated code—are immutable artifacts of this study, extracted from google-deepmind/code_contests and generated via OpenRouter API. This ensures reproducibility across runs and for external reviewers.

## Source & Version

- **Repository**: [google-deepmind/code_contests](https://github.com/google-deepmind/code_contests)
- **Commit SHA**: `fa7a4f8139aab08362503f3344778eb86901709a`
- **Extraction Date**: October 2025 (mid-month)
- **Immutable**: All data frozen as of the commit above. No changes post-extraction.

## Key Principle

**All data in the `data/` folder is frozen.** This includes:
- Problem instructions and metadata (from code-contest)
- Test cases (from code-contest)
- Human reference solutions (from code-contest)
- AI-generated code (from OpenRouter API)

No data is regenerated; all analysis runs against fixed snapshots. This guarantees reproducibility.

The following datasets are **immutable** and extracted from google-deepmind/code_contests at commit `fa7a4f8139aab08362503f3344778eb86901709a`:

### `data/instructions/`
- **Source**: Problem descriptions from google-deepmind/code_contests
- **Format**: JSON (one file per shard)
- **Contents**: Problem statements, input/output specifications, examples
- **Files**:
  - `descriptions-train-00000.json`
  - `descriptions-train-00001.json`
  - `descriptions-train-00002.json`
- **Total Records**: [Number of problems]

### `data/problem_tags/`
- **Source**: Problem metadata (difficulty, categories) from google-deepmind/code_contests
- **Format**: JSON (one file per shard)
- **Contents**: `cf_tags` and other problem attributes
- **Files**:
  - `problem_tags_00000.json`
  - `problem_tags_00001.json`
  - `problem_tags_00002.json`
- **Filtering**: Only problems with at least one human C++ solution

### `data/testcases/`
- **Source**: Test inputs and expected outputs from google-deepmind/code_contests
- **Format**: JSON (one file per shard)
- **Contents**: Input/output test cases for validation
- **Files**:
  - `testcases-train-00000.json`
  - `testcases-train-00001.json`
  - `testcases-train-00002.json`
- **Filtering**: Only testcases for problems with human solutions

### `data/human/`
- **Source**: Human reference C++ solutions from google-deepmind/code_contests
- **Format**: JSON (solutions indexed by problem ID)
- **Contents**: Two distinct solution sets per problem (where available)
- **Files**:
  - `human_cpp_solutions_00000.json`
  - `human_cpp_solutions_00001.json`
  - `human_cpp_solutions_00002.json`
- **Total Solutions**: [Number of human solutions across both sets]

### `data/generations/`
- **Source**: Generated code via OpenRouter API
- **Models**: 
  - Gemma 3 27B IT
  - LLaMA 3.3 70B Instruct
  - Qwen 2.5 Coder 32B Instruct
- **API**: OpenRouter (model endpoints and parameters documented below)
- **Status**: Generated during experiments; reproducibility depends on model versions/API state at time of generation
- **Directories**:
  - `gemma/` – Gemma 3 27B IT generations
  - `llama/` – LLaMA 3.3 70B Instruct generations
  - `qwen/` – Qwen 2.5 Coder 32B Instruct generations

## Data Categories Summary

| Category | Source | Status | Frozen? |
|----------|--------|--------|---------|
| Instructions | google-deepmind/code_contests | Fixed | ✓ Yes |
| Problem tags | google-deepmind/code_contests | Fixed | ✓ Yes |
| Testcases | google-deepmind/code_contests | Fixed | ✓ Yes |
| Human solutions | google-deepmind/code_contests | Fixed | ✓ Yes |
| Generated code | OpenRouter API | Fixed | ✓ Yes |

## Filtering & Preprocessing

All datasets were extracted with the following criteria:
- **Inclusion**: Only problems that have **at least one human C++ solution**
- **Sharding**: Data split into three shards (00000, 00001, 00002) for organizational clarity
- **No deduplication** [or state if deduplication was applied]
- **No solution filtering** beyond availability of human baseline

## Reproducibility

### Frozen Datasets (google-deepmind/code_contests)

To reproduce with identical data:
1. Checkout google-deepmind/code_contests at commit: `fa7a4f8139aab08362503f3344778eb86901709a`
2. Extract using the same filtering criteria (problems with ≥1 human solution)
3. Verify against checksums below (if available)

### Generated Code (OpenRouter)

Generated code outputs are **frozen artifacts** from experiments executed with specific models and parameters:
- **API**: OpenRouter
- **Models**: 
  - Gemma 3 27B IT
  - LLaMA 3.3 70B Instruct
  - Qwen 2.5 Coder 32B Instruct
- **Decoding Parameters** (OpenRouter defaults):
  - Temperature: 1.0
  - Top-p: 1.0
  - Top-k: 0 (disabled)
  - Frequency penalty: 0.0
  - Presence penalty: 0.0
  - Repetition penalty: 1.0
  - Min-p: 0.0
  - Top-a: 0.0
  - Seed: Not set
- **Date Range**: October 2025 (mid-month)
- **Status**: Frozen; these are the exact outputs used in all analysis and results

**Note**: Generated code outputs are fixed snapshots from the experiment run. Exact reproducibility of generation may depend on OpenRouter API state at the time of generation, but the outputs themselves are immutable for this study.

## Checksums (SHA-256)

Generate with:
```bash
find data/ -name "*.json" -type f | sort | xargs sha256sum
```

[Add checksums when ready for publication/archival]

## Citation

If using this frozen dataset, cite:
```
google-deepmind/code_contests (commit fa7a4f8139aab08362503f3344778eb86901709a)
Extracted: October 2025
Filter: Problems with ≥1 human C++ solution
```

## Notes

- All paths are relative to the project root
- JSON files are sharded for practical handling of large datasets
- The `data/` directory is read-only in this study; all analysis outputs go to `analysis/` and `results/`
