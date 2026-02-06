"""
Full analysis pipeline for AI-generated C++ vulnerability study.

Orchestrates all analysis steps in order:
1. Parse cppcheck results
2. Merge test pass rates + cppcheck + tags into master CSV

Run: python3.11 scripts/run_full_analysis.py [--skip-cppcheck] [--skip-merge]
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


def run_command(cmd, description):
    """Run a shell command and return success/failure."""
    log(f"Starting: {description}")
    log(f"Command: {' '.join(cmd)}")
    
    try:
        result = subprocess.run(cmd, check=True, cwd=os.getcwd())
        log(f"✓ Completed: {description}")
        return True
    except subprocess.CalledProcessError as e:
        log(f"✗ Failed: {description} (exit code: {e.returncode})")
        return False
    except Exception as e:
        log(f"✗ Error running {description}: {e}")
        return False


def verify_dependencies():
    """Check that required scripts and data exist."""
    required_files = [
        "scripts/parse_cppcheck_unified.py",
        "scripts/merge_tpr_cppcheck_master.py",
        "results/raw_csv/tests_with_cases.csv",
        "data/problem_tags/",
    ]
    
    log("Verifying dependencies...")
    for file_path in required_files:
        if not Path(file_path).exists():
            log(f"✗ Missing: {file_path}")
            return False
        log(f"  ✓ Found: {file_path}")
    
    return True


def main():
    """Run full analysis pipeline."""
    
    log("=" * 70)
    log("AI-Generated C++ Vulnerability Analysis Pipeline")
    log("=" * 70)
    
    # Parse arguments
    skip_cppcheck = "--skip-cppcheck" in sys.argv
    skip_merge = "--skip-merge" in sys.argv
    
    if skip_cppcheck:
        log("Note: --skip-cppcheck flag set; skipping cppcheck parsing")
    if skip_merge:
        log("Note: --skip-merge flag set; skipping master merge")
    
    # Verify dependencies
    if not verify_dependencies():
        log("✗ Dependency check failed. Aborting.")
        sys.exit(1)
    
    log("")
    
    # Step 1: Parse cppcheck results
    if not skip_cppcheck:
        success = run_command(
            ["python3.11", "scripts/parse_cppcheck_unified.py"],
            "Parse cppcheck XML reports"
        )
        if not success:
            log("✗ Cppcheck parsing failed. Aborting.")
            sys.exit(1)
        log("")
    
    # Step 2: Merge all data
    if not skip_merge:
        success = run_command(
            ["python3.11", "scripts/merge_tpr_cppcheck_master.py"],
            "Merge test pass rates + cppcheck + problem tags"
        )
        if not success:
            log("✗ Master merge failed. Aborting.")
            sys.exit(1)
        log("")
    
    # Optional: clang-tidy parsing (if you add it later)
    # success = run_command(
    #     ["python3.11", "scripts/parse_clang_tidy.py"],
    #     "Parse clang-tidy results"
    # )
    
    # Optional: semgrep parsing (if you add it later)
    # success = run_command(
    #     ["python3.11", "scripts/parse_semgrep.py"],
    #     "Parse semgrep results"
    # )
    
    log("=" * 70)
    log("✓ Pipeline completed successfully!")
    log("=" * 70)
    log("")
    log("Output files:")
    log("  - results/raw_csv/cppcheck_detailed.csv")
    log("  - results/raw_csv/cppcheck_summary.csv")
    log("  - results/raw_csv/master_analysis_tpr_cppcheck.csv (test pass rates + cppcheck)")
    log("")


if __name__ == "__main__":
    main()
