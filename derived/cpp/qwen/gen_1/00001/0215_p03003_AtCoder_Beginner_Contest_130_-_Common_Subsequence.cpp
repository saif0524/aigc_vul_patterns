#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for(auto &x: S) cin >> x;
    for(auto &x: T) cin >> x;
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    dp[0][0] = 1;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            if(i > 0 && j > 0 && S[i-1] == T[j-1]){
                dp[i][j] = (dp[i][j] - dp[i-1][j-1] + MOD) % MOD;
            }
            if(i > 0 && j > 0 && S[i-1] == T[j-1]){
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
        }
    }
    cout << dp[N][M] << "\n";
}