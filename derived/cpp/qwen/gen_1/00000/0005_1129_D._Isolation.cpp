#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> freq(n + 1, 0);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int distinct_once = 0;
    for(int i = 1; i <= n; ++i){
        if(++freq[a[i-1]] == 1) distinct_once++;
        if(freq[a[i-1]] == 2) distinct_once--;
        if(distinct_once <= k) dp[i] = dp[i-1];
        dp[i] = (dp[i] + dp[i-1]) % MOD;
        if(i > k){
            if(--freq[a[i-k-1]] == 1) distinct_once++;
            if(freq[a[i-k-1]] == 0) distinct_once--;
        }
    }
    cout << dp[n] << "\n";
}