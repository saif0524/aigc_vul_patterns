#include <bits/stdc++.h>
using namespace std;

double dp[257][129];
double best[257][129];

double quantize(vector<double>& seq, int start, int m, int l) {
    if (start == seq.size()) return 0.0;
    if (m == 0) return 1e18;
    if (dp[start][m] != -1) return dp[start][m];
    
    double res = 1e18;
    for (int i = start + 1; i <= seq.size() - m + 1; ++i) {
        double vmax = *max_element(seq.begin() + start, seq.begin() + i);
        double vmin = *min_element(seq.begin() + start, seq.begin() + i);
        double step = (vmax - vmin) / (1 << l);
        
        double sum_sq_err = 0.0;
        for (int j = start; j < i; ++j) {
            int idx = round((seq[j] - vmin) / step);
            idx = max(0, min((1 << l) - 1, idx));
            double qval = vmin + idx * step;
            sum_sq_err += (seq[j] - qval) * (seq[j] - qval);
        }
        
        res = min(res, sum_sq_err + quantize(seq, i, m - 1, l));
    }
    
    dp[start][m] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, L;
    while(cin >> N >> M >> L){
        if(N==0 && M==0 && L==0) break;
        vector<double> seq(N);
        for(double &x : seq) cin >> x;
        
        memset(dp, -1, sizeof(dp));
        cout << fixed << setprecision(6) << quantize(seq, 0, M, L) << '\n';
    }
}