#!/bin/bash
# Waits for the pilot (PID passed as $1), then runs the two full configurations one after the other.
# Never run them concurrently: ESBMC timeouts depend on machine load.
cd "$(dirname "$0")/../.." || exit 1
RUNS=revision_experiments/esbmc/runs
while kill -0 "$1" 2>/dev/null; do sleep 10; done
python3.11 revision_experiments/esbmc/run_esbmc_config.py --run-name e2_overflow_u10_t60 --jobs 16 > $RUNS/e2_overflow_u10_t60.log 2>&1
python3.11 revision_experiments/esbmc/run_esbmc_config.py --run-name e1_baseline_u10_t60 --no-overflow-check --jobs 16 > $RUNS/e1_baseline_u10_t60.log 2>&1
