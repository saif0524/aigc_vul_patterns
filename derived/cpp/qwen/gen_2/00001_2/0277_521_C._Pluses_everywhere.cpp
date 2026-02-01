#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k && j <= i - 1; j++){
            long long num = 0;
            for(int l = i; l >= 1 && i - l < 18; l--){
                num = (num * 10 + s[l-1] - '0') % MOD;
                if(s[l-1] != '0' || l == i){
                    dp[i][j] = (dp[i][j] + (j > 0 ? dp[l-1][j-1] : 0) * num) % MOD;
                }
            }
        }
    }

    cout << dp[n][k];
}