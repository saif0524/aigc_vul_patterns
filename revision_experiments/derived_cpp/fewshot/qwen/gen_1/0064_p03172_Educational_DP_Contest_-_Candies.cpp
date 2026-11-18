#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(auto &x : a) cin >> x;
    
    vector<int> dp(K+1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < N; ++i){
        vector<int> new_dp(K+1, 0);
        for(int j = 0; j <= K; ++j){
            if(dp[j] ==0) continue;
            for(int k =0; k <= min(K-j, a[i]); ++k){
                new_dp[j+k] = (new_dp[j+k] + dp[j]) % MOD;
            }
        }
        dp = new_dp;
    }
    
    cout << dp[K] << "\n";
    return 0;
}