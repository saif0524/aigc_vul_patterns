#!/usr/bin/env python3
"""
Bootstrap Confidence Intervals for TPR and CWE Differences

Calculates:
1. Bootstrap 95% CIs for pass rates (TPR) per model
2. Bootstrap CIs for differences: human - AI models
3. Bootstrap CIs for CWE prevalence rates per model
4. Statistical significance of human vs AI differences

Output: results/raw_csv/bootstrap_ci_results.csv
"""

import pandas as pd
import numpy as np
from pathlib import Path

WORKSPACE = Path(__file__).resolve().parent.parent
RAW_CSV = WORKSPACE / "results" / "raw_csv"

N_BOOTSTRAP = 10000
CI_LEVEL = 0.95
RANDOM_SEED = 42


def bootstrap_mean_ci(data, n_bootstrap=N_BOOTSTRAP, ci_level=CI_LEVEL, seed=RANDOM_SEED):
    """Compute bootstrap confidence interval for mean."""
    np.random.seed(seed)
    n = len(data)
    if n == 0:
        return np.nan, np.nan, np.nan
    
    boot_means = []
    for _ in range(n_bootstrap):
        sample = np.random.choice(data, size=n, replace=True)
        boot_means.append(np.mean(sample))
    
    boot_means = np.array(boot_means)
    alpha = 1 - ci_level
    lower = np.percentile(boot_means, 100 * alpha / 2)
    upper = np.percentile(boot_means, 100 * (1 - alpha / 2))
    point_estimate = np.mean(data)
    
    return point_estimate, lower, upper


def bootstrap_difference_ci(data1, data2, n_bootstrap=N_BOOTSTRAP, ci_level=CI_LEVEL, seed=RANDOM_SEED):
    """Compute bootstrap CI for difference in means (data1 - data2)."""
    np.random.seed(seed)
    n1, n2 = len(data1), len(data2)
    if n1 == 0 or n2 == 0:
        return np.nan, np.nan, np.nan, np.nan
    
    boot_diffs = []
    for _ in range(n_bootstrap):
        sample1 = np.random.choice(data1, size=n1, replace=True)
        sample2 = np.random.choice(data2, size=n2, replace=True)
        boot_diffs.append(np.mean(sample1) - np.mean(sample2))
    
    boot_diffs = np.array(boot_diffs)
    alpha = 1 - ci_level
    lower = np.percentile(boot_diffs, 100 * alpha / 2)
    upper = np.percentile(boot_diffs, 100 * (1 - alpha / 2))
    point_estimate = np.mean(data1) - np.mean(data2)
    
    # P-value (two-tailed): proportion of bootstrap diffs on opposite side of 0
    if point_estimate > 0:
        pval = 2 * np.mean(boot_diffs <= 0)
    else:
        pval = 2 * np.mean(boot_diffs >= 0)
    
    return point_estimate, lower, upper, pval


def main():
    # Load master analysis
    master_path = RAW_CSV / "master_analysis.csv"
    if not master_path.exists():
        print(f"ERROR: {master_path} not found")
        return
    
    master_df = pd.read_csv(master_path)
    print(f"Loaded {len(master_df)} samples from master_analysis.csv")
    
    # Load cppcheck detailed for CWE analysis
    detailed_path = RAW_CSV / "cppcheck_detailed.csv"
    if detailed_path.exists():
        detailed_df = pd.read_csv(detailed_path)
        print(f"Loaded {len(detailed_df)} cppcheck findings")
    else:
        detailed_df = None
    
    results = []
    
    # ========================================
    # 1. Bootstrap CIs for Pass Rates (TPR)
    # ========================================
    print("\n=== Bootstrap CIs for Pass Rates ===")
    
    # Filter to samples with test results
    test_df = master_df[master_df['pass_rate'].notna()].copy()
    print(f"Samples with test results: {len(test_df)}")
    
    model_data = {}
    for model in test_df['model'].unique():
        model_df = test_df[test_df['model'] == model]
        # Use pass_rate directly (already 0-1 range), or binary: pass_rate == 1.0
        pass_binary = (model_df['pass_rate'] == 1.0).astype(int).values
        pass_rates = model_df['pass_rate'].values
        model_data[model] = {'binary': pass_binary, 'rates': pass_rates}
        
        # Binary pass rate
        est, lo, hi = bootstrap_mean_ci(pass_binary)
        results.append({
            'metric': 'full_pass_rate',
            'model': model,
            'n_samples': len(pass_binary),
            'point_estimate': est,
            'ci_lower': lo,
            'ci_upper': hi,
            'ci_width': hi - lo,
        })
        print(f"  {model} full_pass: {est:.3f} [{lo:.3f}, {hi:.3f}] (n={len(pass_binary)})")
        
        # Mean pass rate
        est2, lo2, hi2 = bootstrap_mean_ci(pass_rates)
        results.append({
            'metric': 'mean_pass_rate',
            'model': model,
            'n_samples': len(pass_rates),
            'point_estimate': est2,
            'ci_lower': lo2,
            'ci_upper': hi2,
            'ci_width': hi2 - lo2,
        })
        print(f"  {model} mean_rate: {est2:.3f} [{lo2:.3f}, {hi2:.3f}]")
    
    # ========================================
    # 2. Human vs AI Differences
    # ========================================
    print("\n=== Human vs AI Pass Rate Differences ===")
    
    if 'human' in model_data:
        human_binary = model_data['human']['binary']
        human_rates = model_data['human']['rates']
        
        for model in model_data:
            if model == 'human':
                continue
            
            # Binary difference
            est, lo, hi, pval = bootstrap_difference_ci(human_binary, model_data[model]['binary'])
            significant = lo > 0 or hi < 0  # CI doesn't include 0
            
            results.append({
                'metric': 'full_pass_diff_human_minus_ai',
                'model': f"human - {model}",
                'n_samples': f"{len(human_binary)} vs {len(model_data[model]['binary'])}",
                'point_estimate': est,
                'ci_lower': lo,
                'ci_upper': hi,
                'ci_width': hi - lo,
                'p_value': pval,
                'significant_95': significant,
            })
            print(f"  human - {model} (binary): {est:.3f} [{lo:.3f}, {hi:.3f}] p={pval:.4f} {'*' if significant else ''}")
            
            # Mean rate difference
            est2, lo2, hi2, pval2 = bootstrap_difference_ci(human_rates, model_data[model]['rates'])
            significant2 = lo2 > 0 or hi2 < 0
            
            results.append({
                'metric': 'mean_rate_diff_human_minus_ai',
                'model': f"human - {model}",
                'n_samples': f"{len(human_rates)} vs {len(model_data[model]['rates'])}",
                'point_estimate': est2,
                'ci_lower': lo2,
                'ci_upper': hi2,
                'ci_width': hi2 - lo2,
                'p_value': pval2,
                'significant_95': significant2,
            })
            print(f"  human - {model} (mean): {est2:.3f} [{lo2:.3f}, {hi2:.3f}] p={pval2:.4f} {'*' if significant2 else ''}")
    
    # ========================================
    # 3. CWE Analysis on COMPILED SOLUTIONS ONLY
    # ========================================
    if detailed_df is not None:
        print("\n=== Bootstrap CIs for CWE (COMPILED ONLY) ===")
        
        # Filter to compiled solutions only
        compiled_df = master_df[master_df['compiled'] == True].copy()
        print(f"Compiled solutions: {len(compiled_df)} / {len(master_df)}")
        
        # Calculate CWE count per sample (filter to those with CWE codes)
        detailed_cwe = detailed_df[detailed_df['cwe'].notna()].copy()
        # Normalize sample_id to match master (add .cpp if missing)
        detailed_cwe['sample_id'] = detailed_cwe['sample_id'].apply(
            lambda x: x if x.endswith('.cpp') else x + '.cpp'
        )
        cwe_counts = detailed_cwe.groupby(['sample_id', 'model']).size().reset_index(name='cwe_count')
        
        # Merge with COMPILED samples only
        compiled_with_cwe = compiled_df.merge(cwe_counts[['sample_id', 'cwe_count']], 
                                          on='sample_id', how='left')
        compiled_with_cwe['cwe_count'] = compiled_with_cwe['cwe_count'].fillna(0)
        
        # CWE count per model (compiled only)
        model_cwe_data = {}
        for model in compiled_with_cwe['model'].unique():
            model_df = compiled_with_cwe[compiled_with_cwe['model'] == model]
            cwe_vals = model_df['cwe_count'].values
            has_cwe = (cwe_vals > 0).astype(int)
            model_cwe_data[model] = {'counts': cwe_vals, 'has_cwe': has_cwe}
            
            # Mean CWE count
            est, lo, hi = bootstrap_mean_ci(cwe_vals)
            results.append({
                'metric': 'mean_cwe_count_compiled',
                'model': model,
                'n_samples': len(cwe_vals),
                'point_estimate': est,
                'ci_lower': lo,
                'ci_upper': hi,
                'ci_width': hi - lo,
            })
            print(f"  {model}: {est:.3f} [{lo:.3f}, {hi:.3f}] CWEs/sample (n={len(cwe_vals)} compiled)")
            
            # CWE prevalence (has any CWE)
            est2, lo2, hi2 = bootstrap_mean_ci(has_cwe)
            results.append({
                'metric': 'cwe_prevalence_compiled',
                'model': model,
                'n_samples': len(has_cwe),
                'point_estimate': est2,
                'ci_lower': lo2,
                'ci_upper': hi2,
                'ci_width': hi2 - lo2,
            })
        
        # AI vs Human CWE differences (compiled only)
        print("\n=== AI vs Human CWE Differences (COMPILED ONLY) ===")
        if 'human' in model_cwe_data:
            human_cwe = model_cwe_data['human']['counts']
            human_has = model_cwe_data['human']['has_cwe']
            
            for model in model_cwe_data:
                if model == 'human':
                    continue
                
                # CWE count difference (AI minus human)
                est, lo, hi, pval = bootstrap_difference_ci(model_cwe_data[model]['counts'], human_cwe)
                significant = lo > 0 or hi < 0
                
                results.append({
                    'metric': 'cwe_count_diff_compiled',
                    'model': f"{model} - human",
                    'n_samples': f"{len(model_cwe_data[model]['counts'])} vs {len(human_cwe)}",
                    'point_estimate': est,
                    'ci_lower': lo,
                    'ci_upper': hi,
                    'ci_width': hi - lo,
                    'p_value': pval,
                    'significant_95': significant,
                })
                print(f"  {model} - human (count): {est:.3f} [{lo:.3f}, {hi:.3f}] p={pval:.4f} {'*' if significant else ''}")
                
                # CWE prevalence difference
                est2, lo2, hi2, pval2 = bootstrap_difference_ci(model_cwe_data[model]['has_cwe'], human_has)
                significant2 = lo2 > 0 or hi2 < 0
                
                results.append({
                    'metric': 'cwe_prevalence_diff_compiled',
                    'model': f"{model} - human",
                    'n_samples': f"{len(model_cwe_data[model]['has_cwe'])} vs {len(human_has)}",
                    'point_estimate': est2,
                    'ci_lower': lo2,
                    'ci_upper': hi2,
                    'ci_width': hi2 - lo2,
                    'p_value': pval2,
                    'significant_95': significant2,
                })
                print(f"  {model} - human (prevalence): {est2:.3f} [{lo2:.3f}, {hi2:.3f}] p={pval2:.4f} {'*' if significant2 else ''}")
        
        # ========================================
        # 4. CWE Analysis on PASSING SOLUTIONS ONLY
        # ========================================
        print("\n=== Bootstrap CIs for CWE (PASSING ONLY, pass_rate=1.0) ===")
        
        # Filter to fully passing solutions
        passing_df = master_df[master_df['pass_rate'] == 1.0].copy()
        print(f"Passing solutions: {len(passing_df)} / {len(master_df)}")
        
        # Merge with passing samples
        passing_with_cwe = passing_df.merge(cwe_counts[['sample_id', 'cwe_count']], 
                                          on='sample_id', how='left')
        passing_with_cwe['cwe_count'] = passing_with_cwe['cwe_count'].fillna(0)
        
        # CWE count per model (passing only)
        model_cwe_passing = {}
        for model in passing_with_cwe['model'].unique():
            model_df = passing_with_cwe[passing_with_cwe['model'] == model]
            cwe_vals = model_df['cwe_count'].values
            has_cwe = (cwe_vals > 0).astype(int)
            model_cwe_passing[model] = {'counts': cwe_vals, 'has_cwe': has_cwe}
            
            est, lo, hi = bootstrap_mean_ci(cwe_vals)
            results.append({
                'metric': 'mean_cwe_count_passing',
                'model': model,
                'n_samples': len(cwe_vals),
                'point_estimate': est,
                'ci_lower': lo,
                'ci_upper': hi,
                'ci_width': hi - lo,
            })
            print(f"  {model}: {est:.3f} [{lo:.3f}, {hi:.3f}] CWEs/sample (n={len(cwe_vals)} passing)")
        
        # AI vs Human CWE differences (passing only)
        print("\n=== AI vs Human CWE Differences (PASSING ONLY) ===")
        if 'human' in model_cwe_passing:
            human_cwe_p = model_cwe_passing['human']['counts']
            
            for model in model_cwe_passing:
                if model == 'human':
                    continue
                
                est, lo, hi, pval = bootstrap_difference_ci(model_cwe_passing[model]['counts'], human_cwe_p)
                significant = lo > 0 or hi < 0
                
                results.append({
                    'metric': 'cwe_count_diff_passing',
                    'model': f"{model} - human",
                    'n_samples': f"{len(model_cwe_passing[model]['counts'])} vs {len(human_cwe_p)}",
                    'point_estimate': est,
                    'ci_lower': lo,
                    'ci_upper': hi,
                    'ci_width': hi - lo,
                    'p_value': pval,
                    'significant_95': significant,
                })
                print(f"  {model} - human: {est:.3f} [{lo:.3f}, {hi:.3f}] p={pval:.4f} {'*' if significant else ''}")
    
    # ========================================
    # 5. Per-CWE Prevalence Differences (compiled only)
    # ========================================
    if detailed_df is not None:
        print("\n=== Top CWE Prevalence Differences (COMPILED ONLY) ===")
        
        detailed_df_cwe = detailed_df[detailed_df['cwe'].notna()].copy()
        detailed_df_cwe['cwe'] = detailed_df_cwe['cwe'].astype(int)
        
        top_cwes = detailed_df_cwe['cwe'].value_counts().head(10).index.tolist()
        
        # Normalize sample_id
        detailed_df_cwe['sample_id'] = detailed_df_cwe['sample_id'].apply(
            lambda x: x if x.endswith('.cpp') else x + '.cpp'
        )
        
        # Use compiled_df for fair comparison
        compiled_df_check = master_df[master_df['compiled'] == True].copy()
        
        for cwe in top_cwes:
            # Calculate binary: does sample have this CWE?
            cwe_by_sample = detailed_df_cwe[detailed_df_cwe['cwe'] == cwe].groupby(['sample_id', 'model']).size().reset_index(name='has_cwe')
            cwe_by_sample['has_cwe'] = 1  # Just mark presence
            
            # Merge with COMPILED samples
            compiled_cwe = compiled_df_check.merge(cwe_by_sample[['sample_id', 'has_cwe']], 
                                          on='sample_id', how='left')
            compiled_cwe['has_cwe'] = compiled_cwe['has_cwe'].fillna(0)
            
            model_cwe_binary = {}
            for model in compiled_cwe['model'].unique():
                model_df = compiled_cwe[compiled_cwe['model'] == model]
                model_cwe_binary[model] = model_df['has_cwe'].values
            
            if 'human' in model_cwe_binary:
                human_cwe_binary = model_cwe_binary['human']
                for model in ['gemma', 'llama', 'qwen']:
                    if model in model_cwe_binary:
                        est, lo, hi, pval = bootstrap_difference_ci(
                            model_cwe_binary[model], human_cwe_binary
                        )
                        significant = lo > 0 or hi < 0
                        
                        results.append({
                            'metric': f'cwe_{cwe}_prevalence_diff_compiled',
                            'model': f"{model} - human",
                            'n_samples': f"{len(model_cwe_binary[model])} vs {len(human_cwe_binary)}",
                            'point_estimate': est,
                            'ci_lower': lo,
                            'ci_upper': hi,
                            'ci_width': hi - lo,
                            'p_value': pval,
                            'significant_95': significant,
                        })
    
    # ========================================
    # Save Results
    # ========================================
    results_df = pd.DataFrame(results)
    output_path = RAW_CSV / "bootstrap_ci_results.csv"
    results_df.to_csv(output_path, index=False)
    print(f"\n=== Wrote {len(results_df)} results → {output_path} ===")
    
    # Summary table
    print("\n=== Summary of Significant Differences ===")
    sig_results = results_df[results_df.get('significant_95', False) == True]
    if len(sig_results) > 0:
        print(sig_results[['metric', 'model', 'point_estimate', 'ci_lower', 'ci_upper', 'p_value']].to_string(index=False))
    else:
        print("No significant differences at 95% CI level")


if __name__ == "__main__":
    main()