import json, glob, os, csv

INPUT_GLOB = "analysis/tests/**/*.json"
OUT_ALL  = "results/raw_csv/tests_all.csv"
OUT_WITH = "results/raw_csv/tests_with_cases.csv"
OUT_NO   = "results/raw_csv/tests_no_cases.csv"

def find_root_index(parts):
    for key in ("demo_tests", "tests"):
        if key in parts:
            return parts.index(key)
    return None

def extract_problem_key_from_stem(stem: str) -> str:
    """
    stem examples:
      0000_1012_E._Cycle_sort
      0001_1037_E._Trips
      0029_331_E2._Deja_Vu   (human/test naming might differ)
    Strategy:
      drop leading shard prefix up to first underscore.
    """
    s = stem
    if "_" in s:
        s = s.split("_", 1)[1]
    return s

rows_all, rows_with, rows_no = [], [], []

for jf in glob.glob(INPUT_GLOB, recursive=True):
    parts = jf.split(os.sep)
    idx = find_root_index(parts)
    if idx is None:
        continue

    try:
        model = parts[idx + 1]
        generation = parts[idx + 2]
        batch = parts[idx + 3]
    except IndexError:
        continue

    with open(jf, "r", encoding="utf-8") as f:
        d = json.load(f)

    total = int(d.get("total", 0) or 0)
    passed = int(d.get("passed", 0) or 0)

    file_stem = os.path.basename(jf).replace(".json", "")  # e.g., 0000_1012_E._Cycle_sort
    sample_id = f"{model}/{generation}/{batch}/{file_stem}"

    # Prefer JSON, fallback to filename
    problem_key = d.get("problem_key")
    pk_src = "json"
    if not problem_key:
        problem_key = extract_problem_key_from_stem(file_stem)
        pk_src = "filename"

    shard = d.get("shard")
    if shard is None:
        # fallback shard from stem prefix if present (0000_...)
        shard = file_stem.split("_", 1)[0] if "_" in file_stem else ""

    compiled = int(bool(d.get("compiled", False)))
    compile_attempted = int(bool(d.get("compile_attempted", True)))  # many logs omit this; assume attempted
    timeout = int(bool(d.get("timeout", False)))

    has_tests = int(bool(d.get("has_tests", total > 0)))
    no_tests = int(bool(d.get("no_tests", total == 0)))
    reason = d.get("reason", "")

    row = {
        "sample_id": sample_id,
        "model": model,
        "generation": generation,
        "batch": batch,
        "problem_key": problem_key,
        "problem_key_source": pk_src,
        "shard": shard,
        "compile_attempted": compile_attempted,
        "compiled": compiled,
        "has_tests": has_tests,
        "no_tests": no_tests,
        "reason": reason,
        "passed": passed,
        "total_tests": total,
        "pass_rate": (passed / total) if total > 0 else "",
        "timeout": timeout,
    }

    rows_all.append(row)
    if has_tests:
        rows_with.append(row)
    else:
        rows_no.append(row)

os.makedirs("results/raw_csv", exist_ok=True)

def write_csv(path, rows):
    if not rows:
        print(f"[WARN] no rows for {path}")
        return
    fieldnames = list(rows[0].keys())
    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        w.writerows(rows)

write_csv(OUT_ALL, rows_all)
write_csv(OUT_WITH, rows_with)
write_csv(OUT_NO, rows_no)

print(f"ALL:        {len(rows_all)} → {OUT_ALL}")
print(f"With tests: {len(rows_with)} → {OUT_WITH}")
print(f"No tests:   {len(rows_no)} → {OUT_NO}")

# Debug: how many used filename fallback?
fallback = sum(1 for r in rows_all if r["problem_key_source"] == "filename")
print(f"problem_key from filename fallback: {fallback}/{len(rows_all)}")
