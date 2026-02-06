#!/usr/bin/env python3
"""Cross-check task problem keys against actual test data"""
import os
import json
import sys
sys.path.insert(0, os.path.dirname(__file__))

from run_tests_parallel import normalize, build_llm_tasks, build_human_tasks, get_paths

def load_all_tests():
    """Load all test shards."""
    all_tests = {}
    for shard in range(3):
        testfile = f"data/testcases/testcases-train-{shard:05d}.json"
        if os.path.exists(testfile):
            tests = json.load(open(testfile))
            all_tests[shard] = {normalize(p["name"]): p for p in tests}
    return all_tests

def main():
    paths = get_paths("full")
    
    # Load all tests
    all_tests = load_all_tests()
    
    # Count total unique problems in test data
    total_test_problems = 0
    for shard in all_tests:
        total_test_problems += len(all_tests[shard])
    
    print(f"=== TEST DATA ===")
    for shard in sorted(all_tests.keys()):
        print(f"  Shard {shard}: {len(all_tests[shard])} unique problems")
    print(f"  Total unique problems in test data: {total_test_problems}")
    
    # Build all tasks
    llm_tasks = build_llm_tasks(paths)
    human_tasks = build_human_tasks(paths)
    all_tasks = llm_tasks + human_tasks
    
    print(f"\n=== TASKS ===")
    print(f"  Total tasks: {len(all_tasks)}")
    
    # Check how many tasks find a matching test
    found_tests = 0
    no_tests = 0
    missing_problems = set()
    
    for task in all_tasks:
        shard = task["shard"]
        prob_key = task["prob_key"]
        
        test_map = all_tests.get(shard)
        if test_map is None:
            no_tests += 1
            continue
        
        if prob_key in test_map:
            found_tests += 1
        else:
            no_tests += 1
            missing_problems.add(prob_key)
    
    print(f"  Tasks with tests found: {found_tests}")
    print(f"  Tasks without tests: {no_tests}")
    print(f"  Unique missing problem keys: {len(missing_problems)}")
    
    if missing_problems:
        print(f"\n  Sample missing problem keys (first 10):")
        for key in sorted(missing_problems)[:10]:
            print(f"    {key}")
    
    print(f"\n=== PROBLEM ===")
    print(f"Expected: ~{len(all_tasks) // 3} tasks without tests (1/3 of {len(all_tasks)})")
    print(f"Expected: ~{2 * len(all_tasks) // 3} tasks with tests (2/3 of {len(all_tasks)})")
    print(f"Actual: {no_tests} without tests, {found_tests} with tests")
    
    if no_tests > len(all_tasks) // 2:
        print(f"\n⚠️  TOO MANY missing tests! {no_tests} tasks ({100*no_tests/len(all_tasks):.1f}%)")
        print("    This suggests problem key normalization mismatch")
    
    # Show some tasks that match and don't match for comparison
    print(f"\n=== EXAMPLES ===")
    print("Tasks WITH tests found:")
    for task in all_tasks:
        shard = task["shard"]
        prob_key = task["prob_key"]
        test_map = all_tests.get(shard, {})
        if prob_key in test_map:
            print(f"  {task['label']}")
            print(f"    prob_key: {prob_key}")
            break
    
    print("\nTasks WITHOUT tests:")
    for task in all_tasks:
        shard = task["shard"]
        prob_key = task["prob_key"]
        test_map = all_tests.get(shard, {})
        if prob_key not in test_map:
            print(f"  {task['label']}")
            print(f"    prob_key: {prob_key}")
            print(f"    (shard {shard} has {len(test_map)} problems)")
            break

if __name__ == "__main__":
    main()
