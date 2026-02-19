"""
Full analysis pipeline for AI-generated C++ vulnerability study.

Orchestrates all analysis steps in order:
1.  Extract C++ source from JSON generations
2.  Compile and run functional tests
3.  Run cppcheck static analysis
4.  Run clang-tidy static analysis
5.  Run ASan/UBSan dynamic analysis
6.  Parse all tool outputs
7.  Merge into master CSV
8.  (Optional) ESBMC formal verification + parse

ESBMC is opt-in (--esbmc) because it takes several hours.
Three recommended configurations (run sequentially or in parallel):

  # Baseline — no overflow check (reproduces original results)
  python3.11 scripts/run_full_analysis.py --esbmc \
      --esbmc-tag esbmc --esbmc-no-overflow-check

  # Config 1 — overflow-check, same depth
  python3.11 scripts/run_full_analysis.py --esbmc \
      --esbmc-tag esbmc_overflow

  # Config 2 — overflow-check + deeper unwind/timeout
  python3.11 scripts/run_full_analysis.py --esbmc \
      --esbmc-tag esbmc_deep --esbmc-unwind 20 --esbmc-timeout 120

Run: python3.11 scripts/run_full_analysis.py [--skip-extract] [--skip-tests]
     [--skip-cppcheck] [--skip-clang-tidy] [--skip-sanitizers]
     [--skip-parse] [--skip-merge]
     [--esbmc] [--esbmc-tag TAG] [--esbmc-unwind N] [--esbmc-timeout S]
     [--esbmc-no-overflow-check] [--esbmc-jobs N]
"""

import subprocess
import sys
import os
from pathlib import Path
from datetime import datetime


def log(msg):
    """Print timestamped log message."""
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print(f"[{timestamp}] {msg}")


def run_command(cmd, description, shell=False):
    """Run a shell command and return success/failure."""
    log(f"Starting: {description}")
    log(f"Command: {cmd if shell else ' '.join(cmd)}")

    try:
        result = subprocess.run(
            cmd, check=True, cwd=os.getcwd(), shell=shell
        )
        log(f"Completed: {description}")
        return True
    except subprocess.CalledProcessError as e:
        log(f"Failed: {description} (exit code: {e.returncode})")
        return False
    except Exception as e:
        log(f"Error running {description}: {e}")
        return False


def verify_dependencies():
    """Check that required data directories exist."""
    required = [
        "data/instructions/",
        "data/testcases/",
        "data/human/",
        "data/generations/",
        "data/problem_tags/",
        "scripts/extract_cpp.py",
        "scripts/extract_cpp_human.py",
        "scripts/run_tests_parallel.py",
        "scripts/run_cppcheck_parallel.py",
        "scripts/run_clang_tidy.sh",
        "scripts/run_sanitizers.py",
        "scripts/parse_clang_tidy.py",
        "scripts/parse_sanitizers.py",
        "scripts/parse_tests.py",
        "scripts/merge_master_all.py",
    ]

    log("Verifying dependencies...")
    all_ok = True
    for path in required:
        if not Path(path).exists():
            log(f"  Missing: {path}")
            all_ok = False
        else:
            log(f"  Found: {path}")

    return all_ok


def main():
    """Run full analysis pipeline."""

    log("=" * 70)
    log("AI-Generated C++ Vulnerability Analysis Pipeline")
    log("=" * 70)

    # Parse arguments
    import argparse
    parser = argparse.ArgumentParser(
        description="Full analysis pipeline for AI-generated C++ vulnerability study"
    )
    parser.add_argument("--skip-extract",      action="store_true")
    parser.add_argument("--skip-tests",        action="store_true")
    parser.add_argument("--skip-cppcheck",     action="store_true")
    parser.add_argument("--skip-clang-tidy",   action="store_true")
    parser.add_argument("--skip-sanitizers",   action="store_true")
    parser.add_argument("--skip-parse",        action="store_true")
    parser.add_argument("--skip-merge",        action="store_true")
    # ESBMC formal verification (opt-in — takes several hours)
    parser.add_argument("--esbmc",             action="store_true",
                        help="Run ESBMC formal verification (Steps 8a-8b)")
    parser.add_argument("--esbmc-tag",         default="esbmc_overflow",
                        help="Output tag for this ESBMC run (default: esbmc_overflow)")
    parser.add_argument("--esbmc-unwind",      type=int, default=10,
                        help="ESBMC loop unwind bound (default: 10)")
    parser.add_argument("--esbmc-timeout",     type=int, default=60,
                        help="ESBMC timeout per file in seconds (default: 60)")
    parser.add_argument("--esbmc-no-overflow-check", action="store_true",
                        help="Disable --overflow-check (reproduces original baseline)")
    parser.add_argument("--esbmc-jobs",        type=int,
                        default=max(1, os.cpu_count() // 2),
                        help="Parallel workers for ESBMC (default: cpu_count/2)")
    args = parser.parse_args()

    skip_extract    = args.skip_extract
    skip_tests      = args.skip_tests
    skip_cppcheck   = args.skip_cppcheck
    skip_clang_tidy = args.skip_clang_tidy
    skip_sanitizers = args.skip_sanitizers
    skip_parse      = args.skip_parse
    skip_merge      = args.skip_merge

    for flag in [f for f in vars(args) if getattr(args, f) is True]:
        log(f"Note: --{flag.replace('_', '-')} set")

    # Verify dependencies
    if not verify_dependencies():
        log("Dependency check failed. Aborting.")
        sys.exit(1)

    log("")

    # --- Step 1: Extract C++ source files ---
    if not skip_extract:
        success = run_command(
            ["python3.11", "scripts/extract_cpp.py"],
            "Step 1a: Extract C++ from AI generations"
        )
        if not success:
            log("Extraction of AI code failed. Aborting.")
            sys.exit(1)

        success = run_command(
            ["python3.11", "scripts/extract_cpp_human.py"],
            "Step 1b: Extract C++ from human solutions"
        )
        if not success:
            log("Extraction of human code failed. Aborting.")
            sys.exit(1)
        log("")

    # --- Step 2: Compile and run functional tests ---
    if not skip_tests:
        success = run_command(
            ["python3.11", "scripts/run_tests_parallel.py"],
            "Step 2: Compile and run functional tests"
        )
        if not success:
            log("Test execution failed. Aborting.")
            sys.exit(1)
        log("")

    # --- Step 3: Cppcheck static analysis ---
    if not skip_cppcheck:
        success = run_command(
            ["python3.11", "scripts/run_cppcheck_parallel.py"],
            "Step 3: Run cppcheck static analysis"
        )
        if not success:
            log("Cppcheck analysis failed. Aborting.")
            sys.exit(1)
        log("")

    # --- Step 4: Clang-tidy static analysis ---
    if not skip_clang_tidy:
        success = run_command(
            "./scripts/run_clang_tidy.sh --mode full",
            "Step 4: Run clang-tidy static analysis",
            shell=True
        )
        if not success:
            log("Clang-tidy analysis failed. Aborting.")
            sys.exit(1)
        log("")

    # --- Step 5: ASan/UBSan dynamic analysis ---
    if not skip_sanitizers:
        success = run_command(
            ["python3.11", "scripts/run_sanitizers.py"],
            "Step 5: Run ASan/UBSan dynamic analysis"
        )
        if not success:
            log("Sanitizer analysis failed. Aborting.")
            sys.exit(1)
        log("")

    # --- Step 6: Parse all tool outputs ---
    if not skip_parse:
        parsers = [
            (["python3.11", "scripts/parse_tests.py"], "Step 6a: Parse test results"),
            (["python3.11", "scripts/parse_clang_tidy.py"], "Step 6b: Parse clang-tidy results"),
            (["python3.11", "scripts/parse_sanitizers.py"], "Step 6c: Parse sanitizer results"),
        ]
        for cmd, desc in parsers:
            success = run_command(cmd, desc)
            if not success:
                log(f"Warning: {desc} failed. Continuing...")
        log("")

    # --- Step 7: Merge into master CSV ---
    if not skip_merge:
        success = run_command(
            ["python3.11", "scripts/merge_master_all.py"],
            "Step 7: Merge all results into master CSV"
        )
        if not success:
            log("Master merge failed. Aborting.")
            sys.exit(1)
        log("")

    # --- Step 8: ESBMC formal verification (opt-in) ---
    if args.esbmc:
        tag = args.esbmc_tag
        esbmc_cmd = [
            "python3.11", "scripts/run_esbmc.py",
            "--mode", "full",
            "--jobs", str(args.esbmc_jobs),
            "--only", "all",
            "--unwind", str(args.esbmc_unwind),
            "--timeout", str(args.esbmc_timeout),
            "--tag", tag,
        ]
        if args.esbmc_no_overflow_check:
            esbmc_cmd.append("--no-overflow-check")

        success = run_command(
            esbmc_cmd,
            f"Step 8a: Run ESBMC formal verification (tag={tag}, "
            f"unwind={args.esbmc_unwind}, timeout={args.esbmc_timeout}s)"
        )
        if not success:
            log("ESBMC run failed. Skipping parse step.")
        else:
            log("")
            success = run_command(
                ["python3.11", "scripts/parse_esbmc.py",
                 "--mode", "full", "--tag", tag],
                f"Step 8b: Parse ESBMC results (tag={tag})"
            )
            if not success:
                log("Warning: ESBMC parse failed.")
        log("")

    log("=" * 70)
    log("Pipeline completed successfully!")
    log("=" * 70)
    log("")
    log("Core output files:")
    log("  - results/raw_csv/master_analysis.csv")
    log("  - results/raw_csv/cppcheck_detailed.csv")
    log("  - results/raw_csv/cppcheck_summary.csv")
    log("  - results/raw_csv/clang_tidy_detailed.csv")
    log("  - results/raw_csv/clang_tidy_summary.csv")
    log("  - results/raw_csv/sanitizer_detailed.csv")
    log("  - results/raw_csv/sanitizer_summary.csv")
    if args.esbmc:
        tag = args.esbmc_tag
        log(f"ESBMC output files (tag={tag}):")
        log(f"  - results/raw_csv/{tag}_summary.csv")
        log(f"  - results/raw_csv/{tag}_violations.csv")
        log(f"  - results/raw_csv/{tag}_vs_static.csv")
        log(f"  - results/raw_csv/{tag}_cross_reference.csv")
    log("")
    log("Next: Open notebooks/results.ipynb to generate figures and tables.")
    log("")


if __name__ == "__main__":
    main()
