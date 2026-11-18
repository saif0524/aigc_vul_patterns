"""Shared paths for the few-shot analysis scripts.

Input:   revision_experiments/derived_cpp/fewshot/<model>/gen_N/<idx>_<name>.cpp
Output:  revision_experiments/analysis/fewshot/<tool>/<model>/gen_N/<file>
(the same layout as analysis/<tool>/<model>/gen_N/<batch>/<file> in the main study,
 without the <batch> folder)
"""
import argparse
import json
import os
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
SRC_ROOT = REPO / "revision_experiments" / "derived_cpp" / "fewshot"
ANALYSIS_ROOT = REPO / "revision_experiments" / "analysis" / "fewshot"      # cppcheck, clang-tidy
ESBMC_ROOT = REPO / "revision_experiments" / "esbmc_fewshot"                # all ESBMC stages
MODELS = ["gemma", "llama", "qwen"]


def out_root(tool: str) -> Path:
    return ANALYSIS_ROOT / tool


def collect(models=None, gens=None, limit=None):
    """All few-shot .cpp files, sorted. limit = first N per model/gen (for smoke tests)."""
    files = []
    for model in models or MODELS:
        for gen_dir in sorted((SRC_ROOT / model).glob("gen_*")):
            if gens and gen_dir.name not in gens:
                continue
            fs = sorted(gen_dir.glob("*.cpp"))
            files.extend(fs[:limit] if limit else fs)
    return files


def base_parser(description, default_jobs):
    p = argparse.ArgumentParser(description=description)
    p.add_argument("--jobs", "-j", type=int, default=default_jobs, help="parallel workers")
    p.add_argument("--models", nargs="+", choices=MODELS, help="default: all three")
    p.add_argument("--gens", nargs="+", help="e.g. gen_1 (default: all present)")
    p.add_argument("--limit", type=int, help="only the first N files per model/gen (smoke test)")
    p.add_argument("--skip-existing", action="store_true", help="skip files that already have output")
    p.add_argument("--out-root", type=Path, help="override the output root (smoke tests)")
    return p



class _Tee:
    def __init__(self, *streams):
        self.streams = streams

    def write(self, text):
        for st in self.streams:
            st.write(text)
        return len(text)

    def flush(self):
        for st in self.streams:
            st.flush()


def start_log(path):
    """Append everything printed from now on to `path` (kept across runs)."""
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    f = open(path, "a", buffering=1)
    f.write(f"\n=== {time.strftime('%Y-%m-%d %H:%M:%S')} | {' '.join(sys.argv)} ===\n")
    sys.stdout = _Tee(sys.__stdout__, f)


def append_meta(path, record):
    """meta.json = {"invocations": [...]}; each run adds an entry, none is overwritten."""
    path = Path(path)
    meta = json.loads(path.read_text()) if path.exists() else {"invocations": []}
    if "invocations" not in meta:
        meta = {"invocations": [meta]}
    meta["invocations"].append(record)
    path.write_text(json.dumps(meta, indent=2))


def log_run(stage, record):
    """Append one line to esbmc_fewshot/runs.jsonl (one JSON object per run, all stages)."""
    ESBMC_ROOT.mkdir(parents=True, exist_ok=True)
    with open(ESBMC_ROOT / "runs.jsonl", "a") as f:
        f.write(json.dumps({"stage": stage, **record}) + "\n")
