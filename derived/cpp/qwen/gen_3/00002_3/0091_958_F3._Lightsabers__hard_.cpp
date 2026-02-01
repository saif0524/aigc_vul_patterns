#include <bits/stdc++.h>
using namespace std;

const int MOD = 1009;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(m + 1, 0);
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        cnt[c]++;
    }
    vector<vector<int>> dp(k + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= k; ++i){
        for(int c = 0; c <= m; ++c){
            dp[i][c] = dp[i-1][c];
            if(c > 0){
                for(int j = 1; j <= cnt[c] && j <= i; ++j){
                    dp[i][c] = (dp[i][c] + dp[i-j][c-1]) % MOD;
                }
            }
        }
    }
    int result = 0;
    for(int c = 1; c <= m; ++c){
        result = (result + dp[k][c]) % MOD;
    }
    cout << result;
}