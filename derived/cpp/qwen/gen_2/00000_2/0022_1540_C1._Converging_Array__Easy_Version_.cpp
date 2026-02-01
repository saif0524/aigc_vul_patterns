#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    for(auto &x : c) cin >> x;
    vector<int> b(n-1);
    for(auto &x : b) cin >> x;
    int q;
    cin >> q;
    vector<int> x(q);
    for(auto &x : x) cin >> x;
    
    vector<vector<long long>> dp(n, vector<long long>(101, 0));
    for(int i = 0; i <= c[0]; ++i) dp[0][i] = 1;
    
    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= c[i]; ++j){
            for(int k = 0; k <= c[i-1]; ++k){
                int lo = max(0, j - b[i-1]);
                int hi = min(c[i-1], j + b[i-1]);
                if(k >= lo && k <= hi){
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                }
            }
        }
    }
    
    for(auto &xq : x){
        long long ans = 0;
        for(int i = xq; i <= 100; ++i){
            ans = (ans + dp[n-1][i]) % MOD;
        }
        cout << ans << "\n";
    }
}