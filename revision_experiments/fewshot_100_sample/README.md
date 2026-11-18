# Few-shot experiment

Run from the repository root.

1. Draw the 100-task sample (simple random sampling, seed `20261102`). This writes `sample_tasks.csv` and `descriptions-sample.json`.

   ```bash
   python3.11 revision_experiments/fewshot_100_sample/sample_tasks.py
   ```

2. Select the two demonstrations (seed `20261102`). This writes `shots.json`. A candidate is a human solution to a task outside the sample that compiled, passed all tests, had no ASan/UBSan report and no cppcheck finding, and was not ESBMC FAILED.

   ```bash
   python3.11 revision_experiments/fewshot_100_sample/select_shots.py
   ```

3. Generate code. `notebooks/generate_code_v2.ipynb` reads `descriptions-sample.json` and builds each prompt with `build_messages` (two demonstrations, then the task). Outputs go to `generations/<model>/gen_1/`.

   ```python
   import sys; sys.path.insert(0, "revision_experiments/fewshot_100_sample")
   from build_prompt import build_messages
   messages = build_messages(description)
   ```

4. Extract the programs and run the tools: see "Few-Shot Prompting Experiment" in the root `README.MD`.
