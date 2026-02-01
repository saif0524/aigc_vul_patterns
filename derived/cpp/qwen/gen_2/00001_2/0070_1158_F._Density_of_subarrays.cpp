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
    
    vector<int> dp(1<<c, 0);
    dp[0] = 1;
    for(auto x: a){
        int mask = 0;
        mask |= (1<<(x-1));
        for(int j=(1<<c)-1; j>=0; --j){
            if((j|mask) == j){
                dp[j] = (dp[j] + dp[j^mask]) % MOD;
            }
        }
    }
    
    vector<int> fact(n+1, 1), ifact(n+1, 1);
    for(int i=2; i<=n; ++i){
        fact[i] = 1LL * fact[i-1] * i % MOD;
        ifact[i] = 1LL * ifact[i-1] * pow(i, MOD-2, MOD) % MOD;
    }
    
    vector<int> ans(n+1, 0);
    for(int mask=1; mask<(1<<c); ++mask){
        int cnt = __builtin_popcount(mask);
        ans[cnt] = (ans[cnt] + 1LL * dp[mask] * fact[n]) % MOD;
        for(int j=0; j<cnt; ++j){
            ans[cnt-j] = (ans[cnt-j] - 1LL * dp[mask] * fact[n-j] % MOD * ifact[j] % MOD + MOD) % MOD;
        }
    }
    
    for(int i=0; i<=n; ++i){
        cout << ans[i] << (i<n?" ":"\n");
    }
}