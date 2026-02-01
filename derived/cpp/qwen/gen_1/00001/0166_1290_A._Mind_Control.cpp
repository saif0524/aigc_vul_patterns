#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        for(int i = 0; i < n; ++i){
            dp[i][i] = a[i];
        }
        for(int len = 2; len <= n; ++len){
            for(int i = 0; i + len - 1 < n; ++i){
                int j = i + len - 1;
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
            }
        }
        
        long long ans = -1;
        for(int i = 0; i + k < m - 1; ++i){
            ans = max(ans, dp[i + k + 1][n - 1]);
        }
        for(int i = m; i + k < n; ++i){
            ans = max(ans, dp[0][i - k - 1]);
        }
        ans = max(ans, dp[max(0, m - k)][min(n - 1, m + k - 1)]);
        cout << ans + accumulate(a.begin(), a.end(), 0LL) / 2 << "\n";
    }
}