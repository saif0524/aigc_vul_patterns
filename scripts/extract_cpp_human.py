import os
import json
import re

BASE_DATA = "data/human"
BASE_OUT  = "derived/cpp/human"

def safe_filename(name):
    return re.sub(r"[^\w_.-]", "_", name)

def extract_all():
    for fname in sorted(os.listdir(BASE_DATA)):
        if not fname.endswith(".json"):
            continue

        # e.g., human_cpp_solutions_00000.json
        batch = fname.replace(".json", "").split("_")[-1]

        out_dir_1 = os.path.join(BASE_OUT, "soln1", batch)
        out_dir_2 = os.path.join(BASE_OUT, "soln2", batch)
        os.makedirs(out_dir_1, exist_ok=True)
        os.makedirs(out_dir_2, exist_ok=True)

        with open(os.path.join(BASE_DATA, fname), "r", encoding="utf-8") as f:
            data = json.load(f)

        written_1 = 0
        written_2 = 0

        for pid, row in enumerate(data):
            problem_name = row.get("problem_name", f"problem_{pid}")
            solutions = row.get("solutions", [])

            if not isinstance(solutions, list):
                continue

            for sid, code in enumerate(solutions[:2]):  # only first two
                code = code.strip()
                if not code:
                    continue

                cpp_name = f"{pid:04d}_{safe_filename(problem_name)}.cpp"

                if sid == 0:
                    out_path = os.path.join(out_dir_1, cpp_name)
                    written_1 += 1
                elif sid == 1:
                    out_path = os.path.join(out_dir_2, cpp_name)
                    written_2 += 1
                else:
                    continue

                with open(out_path, "w", encoding="utf-8") as out:
                    out.write(code)

        print(f"[OK] human {batch}: soln1={written_1}, soln2={written_2}")

if __name__ == "__main__":
    extract_all()