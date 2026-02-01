#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int length=2; length<=n; length++){
        for(int i=0; i<=n-length; i++){
            int j = i + length - 1;
            if(s[i] == s[j]) dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            dp[i][j] = (dp[i][j] - dp[i+1][j-1] + MOD) % MOD;
        }
    }
    cout << dp[0][n-1];
}