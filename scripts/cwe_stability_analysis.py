#!/usr/bin/env python3
"""
Per-CWE Stability Analysis Across Generations

Calculates:
1. Jaccard similarity of CWE sets between generations
2. Rank correlation of CWE frequencies
3. Bhattacharyya distance of CWE distributions
4. Per-CWE prevalence stability

Output: results/raw_csv/cwe_stability.csv
"""

import pandas as pd
import numpy as np
from scipy import stats
from itertools import combinations
from pathlib import Path

WORKSPACE = Path(__file__).resolve().parent.parent
RAW_CSV = WORKSPACE / "results" / "raw_csv"


def jaccard_similarity(set1, set2):
    """Jaccard index: |A ∩ B| / |A ∪ B|"""
    if len(set1) == 0 and len(set2) == 0:
        return 1.0
    intersection = len(set1 & set2)
    union = len(set1 | set2)
    return intersection / union if union > 0 else 0.0


def spearman_rank_correlation(freq1, freq2, all_cwes):
    """Spearman rank correlation of CWE frequencies."""
    # Create frequency vectors aligned to all CWEs
    vec1 = [freq1.get(c, 0) for c in all_cwes]
    vec2 = [freq2.get(c, 0) for c in all_cwes]
    
    if sum(vec1) == 0 or sum(vec2) == 0:
        return np.nan
    
    corr, pval = stats.spearmanr(vec1, vec2)
    return corr


def bhattacharyya_distance(freq1, freq2, all_cwes):
    """Bhattacharyya distance between CWE distributions."""
    # Normalize to probability distributions
    vec1 = np.array([freq1.get(c, 0) for c in all_cwes], dtype=float)
    vec2 = np.array([freq2.get(c, 0) for c in all_cwes], dtype=float)
    
    if vec1.sum() == 0 or vec2.sum() == 0:
        return np.nan
    
    p1 = vec1 / vec1.sum()
    p2 = vec2 / vec2.sum()
    
    # BC coefficient = sum(sqrt(p1 * p2))
    bc = np.sum(np.sqrt(p1 * p2))
    
    # Bhattacharyya distance = -ln(BC)
    if bc == 0:
        return np.inf
    return -np.log(bc)


def main():
    # Load cppcheck detailed results
    detailed_path = RAW_CSV / "cppcheck_detailed.csv"
    if not detailed_path.exists():
        print(f"ERROR: {detailed_path} not found")
        return
    
    df = pd.read_csv(detailed_path)
    print(f"Loaded {len(df)} cppcheck findings")
    
    # Filter to CWE-related findings only
    df_cwe = df[df['cwe'].notna()].copy()
    df_cwe['cwe'] = df_cwe['cwe'].astype(int)
    print(f"Findings with CWE: {len(df_cwe)}")
    print(f"Unique CWEs: {df_cwe['cwe'].nunique()}")
    
    # Get all unique CWEs across dataset
    all_cwes = sorted(df_cwe['cwe'].unique())
    
    results = []
    
    # For each model, compare generations
    for model in df_cwe['model'].unique():
        model_df = df_cwe[df_cwe['model'] == model]
        generations = sorted(model_df['generation'].unique())
        
        if len(generations) < 2:
            continue
        
        # Get CWE sets and frequencies per generation
        gen_data = {}
        for gen in generations:
            gen_df = model_df[model_df['generation'] == gen]
            cwe_set = set(gen_df['cwe'].unique())
            cwe_freq = gen_df['cwe'].value_counts().to_dict()
            gen_data[gen] = {'set': cwe_set, 'freq': cwe_freq, 'count': len(gen_df)}
        
        # Compare all pairs of generations
        for gen1, gen2 in combinations(generations, 2):
            data1 = gen_data[gen1]
            data2 = gen_data[gen2]
            
            jaccard = jaccard_similarity(data1['set'], data2['set'])
            spearman = spearman_rank_correlation(data1['freq'], data2['freq'], all_cwes)
            bhatt = bhattacharyya_distance(data1['freq'], data2['freq'], all_cwes)
            
            results.append({
                'model': model,
                'gen1': gen1,
                'gen2': gen2,
                'cwe_count_gen1': len(data1['set']),
                'cwe_count_gen2': len(data2['set']),
                'findings_gen1': data1['count'],
                'findings_gen2': data2['count'],
                'jaccard_similarity': jaccard,
                'spearman_correlation': spearman,
                'bhattacharyya_distance': bhatt,
            })
    
    # Per-CWE prevalence across models/generations
    print("\n=== Per-CWE Prevalence ===")
    cwe_prevalence = []
    
    for cwe in all_cwes:
        cwe_df = df_cwe[df_cwe['cwe'] == cwe]
        
        for model in df_cwe['model'].unique():
            model_cwe = cwe_df[cwe_df['model'] == model]
            
            # Count per generation
            gen_counts = model_cwe.groupby('generation').size().to_dict()
            
            # Count unique files affected
            files_affected = model_cwe['sample_id'].nunique()
            
            cwe_prevalence.append({
                'cwe': f"CWE-{cwe}",
                'model': model,
                'total_findings': len(model_cwe),
                'files_affected': files_affected,
                **{f'count_{g}': gen_counts.get(g, 0) for g in sorted(gen_counts.keys())}
            })
    
    # Save stability results
    if results:
        stability_df = pd.DataFrame(results)
        stability_path = RAW_CSV / "cwe_stability.csv"
        stability_df.to_csv(stability_path, index=False)
        print(f"\nWrote {len(stability_df)} rows → {stability_path}")
        
        print("\n=== CWE Stability Summary ===")
        print(stability_df.to_string(index=False))
    
    # Save per-CWE prevalence
    if cwe_prevalence:
        prevalence_df = pd.DataFrame(cwe_prevalence)
        prevalence_path = RAW_CSV / "cwe_prevalence.csv"
        prevalence_df.to_csv(prevalence_path, index=False)
        print(f"\nWrote {len(prevalence_df)} rows → {prevalence_path}")
    
    # Summary statistics
    print("\n=== Overall Stability Metrics ===")
    if results:
        df_res = pd.DataFrame(results)
        print(f"Mean Jaccard similarity: {df_res['jaccard_similarity'].mean():.3f}")
        print(f"Mean Spearman correlation: {df_res['spearman_correlation'].mean():.3f}")
        print(f"Mean Bhattacharyya distance: {df_res['bhattacharyya_distance'].mean():.3f}")


if __name__ == "__main__":
    main()
