"""
Full analysis pipeline for AI-generated C++ vulnerability study.

Orchestrates all analysis steps in order:
1. Extract C++ source from JSON generations
2. Compile and run functional tests
3. Run cppcheck static analysis
4. Run clang-tidy static analysis
5. Run ASan/UBSan dynamic analysis
6. Parse all tool outputs
7. Merge into master CSV

Run: python3.11 scripts/run_full_analysis.py [--skip-extract] [--skip-tests]
     [--skip-cppcheck] [--skip-clang-tidy] [--skip-sanitizers] [--skip-merge]
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
    flags = set(sys.argv[1:])
    skip_extract = "--skip-extract" in flags
    skip_tests = "--skip-tests" in flags
    skip_cppcheck = "--skip-cppcheck" in flags
    skip_clang_tidy = "--skip-clang-tidy" in flags
    skip_sanitizers = "--skip-sanitizers" in flags
    skip_parse = "--skip-parse" in flags
    skip_merge = "--skip-merge" in flags

    for flag in flags:
        log(f"Note: {flag} set")

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

    log("=" * 70)
    log("Pipeline completed successfully!")
    log("=" * 70)
    log("")
    log("Output files:")
    log("  - results/raw_csv/master_analysis.csv")
    log("  - results/raw_csv/cppcheck_detailed.csv")
    log("  - results/raw_csv/cppcheck_summary.csv")
    log("  - results/raw_csv/clang_tidy_detailed.csv")
    log("  - results/raw_csv/clang_tidy_summary.csv")
    log("  - results/raw_csv/sanitizer_detailed.csv")
    log("  - results/raw_csv/sanitizer_summary.csv")
    log("")
    log("Next: Open notebooks/results.ipynb to generate figures and tables.")
    log("")


if __name__ == "__main__":
    main()
