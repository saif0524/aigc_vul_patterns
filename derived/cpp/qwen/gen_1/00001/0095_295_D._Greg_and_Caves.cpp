#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    if(m < 2){
        cout << 0;
        return 0;
    }
    long long dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=m;++i){
        dp[1][i] = i-1;
    }
    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j){
            dp[i][j] = (dp[i-1][j-1] + dp[i][j-1] + (j-1) * dp[i-1][j]) % MOD;
        }
    }
    long long ans = 0;
    for(int i=1;i<=m;++i){
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans;
}