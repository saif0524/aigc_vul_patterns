#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(int &x : a) cin >> x;
    
    vector<int> dp(K + 1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < N; ++i){
        vector<int> ndp(K + 1, 0);
        for(int j = 0; j <= K; ++j){
            for(int k = 0; k <= min(a[i], j); ++k){
                ndp[j] = (ndp[j] + dp[j - k]) % MOD;
            }
        }
        dp = move(ndp);
    }
    
    cout << dp[K] << "\n";
}