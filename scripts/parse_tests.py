import json, glob, os, csv

INPUT_GLOB = "analysis/tests/**/*.json"
OUT_WITH = "results/raw_csv/tests_with_cases.csv"
OUT_NO   = "results/raw_csv/tests_no_cases.csv"

rows_with, rows_no = [], []

for jf in glob.glob(INPUT_GLOB, recursive=True):
    parts = jf.split(os.sep)
    try:
        idx = parts.index("tests")
        model = parts[idx + 1]
        generation = parts[idx + 2]
    except (ValueError, IndexError):
        continue

    with open(jf) as f:
        d = json.load(f)

    total = d.get("total", 0)
    row = {
        "model": model,
        "generation": generation,
        "instruction_id": os.path.basename(jf).split("_")[0],
        "compiled": int(d.get("compiled", False)),
        "pass_rate": (d.get("passed", 0) / total) if total > 0 else None,
        "timeout": int(d.get("timeout", False)),
        "total_tests": total
    }

    if total > 0:
        rows_with.append(row)
    else:
        rows_no.append(row)

os.makedirs("results/raw_csv", exist_ok=True)

def write_csv(path, rows):
    if not rows:
        return
    with open(path, "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=rows[0].keys())
        writer.writeheader()
        writer.writerows(rows)

write_csv(OUT_WITH, rows_with)
write_csv(OUT_NO, rows_no)

print(f"With tests: {len(rows_with)} → {OUT_WITH}")
print(f"No tests:  {len(rows_no)} → {OUT_NO}")
