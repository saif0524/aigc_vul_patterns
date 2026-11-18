#!/usr/bin/env python3
"""Per-program summaries of the few-shot cppcheck (XML) and clang-tidy (YAML) output.

Writes, in revision_experiments/analysis/fewshot/:
    cppcheck_summary.csv     one row per program
    clang_tidy_summary.csv   one row per program
    static_vs_zeroshot.csv   few-shot vs zero-shot gen_1 on the same tasks and models

A cppcheck finding is any <error> element except the timeout placeholder; "CWE-tagged"
means the element carries a cwe attribute (as has_cwe in the main study's
cppcheck_summary.csv). For clang-tidy a program has a finding when its YAML lists at
least one diagnostic; Level "Error" means clang could not compile the file.

Run from the repository root:
    python3.11 revision_experiments/fewshot_scripts/summarize_static_fewshot.py
"""
import re
import xml.etree.ElementTree as ET
from pathlib import Path

import pandas as pd
import yaml

import common

OUT = common.ANALYSIS_ROOT
RAW = common.REPO / "results" / "raw_csv"
norm = lambda s: re.sub(r"[^a-z0-9]", "", s.lower())


def task_key(stem):                       # "0001_1490_G._Old_Floppy_Drive_" -> normalized name
    return norm(stem.split("_", 1)[1])


cc_rows, ct_rows = [], []
for model in common.MODELS:
    for xml in sorted((OUT / "cppcheck" / model).glob("gen_*/*.xml")):
        try:
            errs = ET.parse(xml).getroot().iter("error")
            errs = [e for e in errs if e.get("id") != "timeout"]
            timed_out = "timeout" in xml.read_text()[:2000] and not errs
            parsed = True
        except ET.ParseError:
            errs, timed_out, parsed = [], False, False
        sev = [e.get("severity") for e in errs]
        cc_rows.append({
            "sample_id": f"{model}/{xml.parent.name}/{xml.stem}", "model": model, "task_key": task_key(xml.stem),
            "parsed_ok": int(parsed), "timed_out": int(timed_out), "total_findings": len(errs),
            "cwe_tagged": sum(1 for e in errs if e.get("cwe")),
            "error": sev.count("error"), "warning": sev.count("warning"), "style": sev.count("style"),
            "performance": sev.count("performance"), "portability": sev.count("portability"),
        })
    for ym in sorted((OUT / "clang_tidy" / model).glob("gen_*/*.yaml")):
        data = yaml.safe_load(ym.read_text(errors="replace")) or {}
        d = data.get("Diagnostics", []) or []
        names = [x.get("DiagnosticName", "") for x in d]
        ct_rows.append({
            "sample_id": f"{model}/{ym.parent.name}/{ym.stem}", "model": model, "task_key": task_key(ym.stem),
            "total_diagnostics": len(d), "compile_errors": sum(1 for x in d if x.get("Level") == "Error"),
            "analyzer": sum(n.startswith("clang-analyzer-") for n in names),
            "security": sum(n.startswith("clang-analyzer-security") for n in names),
            "bugprone": sum(n.startswith("bugprone-") for n in names),
            "performance": sum(n.startswith("performance-") for n in names),
            "modernize": sum(n.startswith("modernize-") for n in names),
        })
cc, ct = pd.DataFrame(cc_rows), pd.DataFrame(ct_rows)
cc.to_csv(OUT / "cppcheck_summary.csv", index=False)
ct.to_csv(OUT / "clang_tidy_summary.csv", index=False)

# ---- zero-shot gen_1 on the same tasks ----
g = pd.read_csv(RAW / "glmm_program_level.csv")
g = g[(g.model.isin(common.MODELS)) & (g.generation == "gen_1")].copy()
g["task_key"] = g.problem_key.map(norm)
zct = pd.read_csv(RAW / "clang_tidy_summary.csv")
zct = zct[zct.model.isin(common.MODELS) & (zct.gen == "gen_1")].copy()
zct["task_key"] = zct.problem_key.map(norm)
zcc = pd.read_csv(RAW / "cppcheck_summary.csv")
zcc = zcc[zcc.model.isin(common.MODELS) & (zcc.generation == "gen_1")].copy()
zcc["task_key"] = zcc.problem_key.map(norm)

rows = []
for model in common.MODELS:
    keys = set(cc[cc.model == model].task_key)
    f_cc, f_ct = cc[cc.model == model], ct[ct.model == model]
    z_cc = zcc[(zcc.model == model) & zcc.task_key.isin(keys)]
    z_ct = zct[(zct.model == model) & zct.task_key.isin(keys)]
    for arm, a, b in [("few-shot", f_cc, f_ct), ("zero-shot gen_1", z_cc, z_ct)]:
        tf = "total_findings" if arm == "few-shot" else "total_errors"
        cw = "cwe_tagged" if arm == "few-shot" else "has_cwe"
        rows.append({
            "model": model, "arm": arm, "programs": len(a),
            "cppcheck_any_pct": round(100 * (a[tf] > 0).mean(), 1),
            "cppcheck_cwe_pct": round(100 * (a[cw] > 0).mean(), 1),
            "cppcheck_mean": round(a[tf].mean(), 2),
            "tidy_programs": len(b),
            "tidy_any_pct": round(100 * (b.total_diagnostics > 0).mean(), 1),
            "tidy_analyzer_pct": round(100 * (b.analyzer > 0).mean(), 1) if arm == "few-shot" else round(100 * (b.analyzer > 0).mean(), 1),
            "tidy_bugprone_pct": round(100 * (b.bugprone > 0).mean(), 1),
            "tidy_mean": round(b.total_diagnostics.mean(), 2),
        })
res = pd.DataFrame(rows)
res.to_csv(OUT / "static_vs_zeroshot.csv", index=False)
print(f"cppcheck rows {len(cc)} (unparsed {int((cc.parsed_ok == 0).sum())}, timeouts {int(cc.timed_out.sum())}); "
      f"clang-tidy rows {len(ct)} (files with compile errors {int((ct.compile_errors > 0).sum())})")
print(res.to_string(index=False))
