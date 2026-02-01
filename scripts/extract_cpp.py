import os
import json
import re

BASE_DATA = "data/generations"
BASE_OUT  = "derived/cpp"

MODELS = ["gemma", "llama", "qwen",]
GENS   = ["gen_1", "gen_2", "gen_3"]

def safe_filename(name):
    return re.sub(r"[^\w_.-]", "_", name)

def extract_all():
    for model in MODELS:
        for gen in GENS:
            gen_dir = os.path.join(BASE_DATA, model, gen)
            if not os.path.isdir(gen_dir):
                continue

            for fname in sorted(os.listdir(gen_dir)):
                if not fname.endswith(".json"):
                    continue

                batch = fname.split("-")[-1].replace(".json", "")
                out_dir = os.path.join(BASE_OUT, model, gen, batch)
                os.makedirs(out_dir, exist_ok=True)

                with open(os.path.join(gen_dir, fname), "r", encoding="utf-8") as f:
                    data = json.load(f)

                for idx, row in enumerate(data):
                    name = row.get("name", f"problem_{idx}")
                    code = row.get("generated_cpp", "").strip()

                    cpp_name = f"{idx:04d}_{safe_filename(name)}.cpp"
                    with open(os.path.join(out_dir, cpp_name), "w", encoding="utf-8") as out:
                        out.write(code)

                print(f"[OK] {model}/{gen}/{batch}: {len(data)} files")

if __name__ == "__main__":
    extract_all()
