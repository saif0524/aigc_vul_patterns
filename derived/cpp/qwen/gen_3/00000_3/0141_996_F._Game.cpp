#include <bits/stdc++.h>
using namespace std;

double solve(vector<int>& f, int n) {
    if (n == 0) return f[0];
    vector<double> dp(1 << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
        int count = __builtin_popcount(mask);
        if (count == n) {
            dp[mask] = f[mask];
            continue;
        }
        int cnt = n - count;
        double best = 1e9;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                double val = dp[mask | (1 << i)];
                best = min(best, val);
                if (count == 0) {
                    val = dp[mask | (1 << i)];
                    best = max(best, val);
                }
            }
        }
        dp[mask] = count == 0 ? best / cnt : best / cnt;
    }
    return dp[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    vector<int> f(1 << n);
    for(auto &x: f) cin >> x;
    cout << fixed << setprecision(6) << solve(f, n) << "\n";
    for(int i=0;i<r;i++){
        int z, g;
        cin >> z >> g;
        f[z] = g;
        cout << fixed << setprecision(6) << solve(f, n) << "\n";
    }
}