#!/usr/bin/env python3
"""
Run cppcheck in parallel on all cpp files.
Uses ProcessPoolExecutor for concurrent execution.
"""

import os
import sys
import argparse
import subprocess
from pathlib import Path
from concurrent.futures import ProcessPoolExecutor, as_completed

WORKSPACE = Path(__file__).resolve().parent.parent
DERIVED_CPP = WORKSPACE / "derived" / "cpp"
ANALYSIS_CPPCHECK = WORKSPACE / "analysis" / "cppcheck"


def run_cppcheck(cpp_path: Path, timeout: int = 30) -> dict:
    """Run cppcheck on a single file and save XML output."""
    # Compute output path: derived/cpp/model/gen/batch/file.cpp -> analysis/cppcheck/model/gen/batch/file.xml
    rel_path = cpp_path.relative_to(DERIVED_CPP)
    out_dir = ANALYSIS_CPPCHECK / rel_path.parent
    out_file = out_dir / (cpp_path.stem + ".xml")
    
    # Create output directory
    out_dir.mkdir(parents=True, exist_ok=True)
    
    # Run cppcheck
    cmd = [
        "cppcheck",
        "--enable=warning,style,performance,portability",
        "--std=c++17",
        "--xml",
        str(cpp_path)
    ]
    
    try:
        result = subprocess.run(
            cmd,
            capture_output=True,
            timeout=timeout,
            text=True
        )
        # cppcheck outputs XML to stderr
        with open(out_file, "w") as f:
            f.write(result.stderr)
        return {"path": str(cpp_path), "success": True, "timeout": False}
    except subprocess.TimeoutExpired:
        # Write empty error file on timeout
        with open(out_file, "w") as f:
            f.write('<?xml version="1.0"?>\n<results><errors><error id="timeout" msg="Analysis timed out"/></errors></results>\n')
        return {"path": str(cpp_path), "success": False, "timeout": True}
    except Exception as e:
        return {"path": str(cpp_path), "success": False, "timeout": False, "error": str(e)}


def main():
    parser = argparse.ArgumentParser(description="Run cppcheck in parallel")
    parser.add_argument("--jobs", "-j", type=int, default=os.cpu_count() or 4,
                        help="Number of parallel workers")
    parser.add_argument("--timeout", "-t", type=int, default=30,
                        help="Timeout per file in seconds")
    parser.add_argument("--skip-existing", action="store_true",
                        help="Skip files that already have XML output")
    args = parser.parse_args()
    
    # Collect all cpp files
    cpp_files = list(DERIVED_CPP.rglob("*.cpp"))
    total = len(cpp_files)
    print(f"Found {total} cpp files")
    
    # Optionally skip existing
    if args.skip_existing:
        to_process = []
        for cpp_path in cpp_files:
            rel_path = cpp_path.relative_to(DERIVED_CPP)
            out_file = ANALYSIS_CPPCHECK / rel_path.parent / (cpp_path.stem + ".xml")
            if not out_file.exists():
                to_process.append(cpp_path)
        skipped = total - len(to_process)
        print(f"Skipping {skipped} files with existing output, processing {len(to_process)}")
        cpp_files = to_process
        total = len(cpp_files)
    
    if total == 0:
        print("No files to process")
        return
    
    print(f"Running cppcheck with {args.jobs} workers, {args.timeout}s timeout...")
    
    done = 0
    success = 0
    timeouts = 0
    errors = 0
    
    with ProcessPoolExecutor(max_workers=args.jobs) as executor:
        futures = {executor.submit(run_cppcheck, p, args.timeout): p for p in cpp_files}
        
        for future in as_completed(futures):
            done += 1
            result = future.result()
            if result.get("success"):
                success += 1
            elif result.get("timeout"):
                timeouts += 1
            else:
                errors += 1
            
            if done % 100 == 0 or done == total:
                print(f"[{done}/{total}] success={success} timeouts={timeouts} errors={errors}")
    
    print(f"\nComplete: {success} succeeded, {timeouts} timed out, {errors} errors")


if __name__ == "__main__":
    main()
