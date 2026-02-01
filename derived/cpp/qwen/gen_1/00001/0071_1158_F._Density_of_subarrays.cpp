#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<vector<int>> dp(n+1, vector<int>(c+1));
    vector<int> fact(n+1, 1);
    vector<int> ifact(n+1, 1);
    for(int i=1;i<=n;i++){
        fact[i] = 1LL * fact[i-1] * i % MOD;
        ifact[i] = 1LL * ifact[i-1] * pow(i, MOD-2, MOD) % MOD;
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=c;j++){
            dp[i+1][j] = dp[i][j];
        }
        for(int j=1;j<=c;j++){
            dp[i+1][j] = (dp[i+1][j] + 1LL * dp[i][j-1] * (a[i] == j)) % MOD;
        }
    }
    vector<int> sum(c+1, 0);
    for(int j=0;j<=c;j++){
        for(int i=1;i<=n;i++){
            sum[j] = (sum[j] + dp[i][j]) % MOD;
        }
    }
    vector<int> ans(n+1, 0);
    for(int p=0;p<=n;p++){
        for(int j=0;j<=c;j++){
            if(sum[j] == 0) continue;
            int cnt = 0;
            for(int k=1;k<=p;k++){
                cnt = (cnt + 1LL * fact[p] * ifact[k] % MOD * ifact[p-k] % MOD) % MOD;
            }
            ans[p] = (ans[p] + 1LL * cnt * sum[j] % MOD * pow(c-j, n-p, MOD) % MOD) % MOD;
        }
    }
    for(int i=0;i<n;i++){
        ans[n] = (ans[n] + 1LL * fact[n] * ifact[i] % MOD * ifact[n-i] % MOD) % MOD;
    }
    for(int i=0;i<=n;i++){
        cout << ans[i] << " \n"[i==n];
    }
}