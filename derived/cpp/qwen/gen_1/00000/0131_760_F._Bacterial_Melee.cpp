#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = i; j >= 0; --j){
            sum = (sum + dp[j]) % MOD;
            if(j-1 >= 0 && s[j] == s[j-1]){
                break;
            }
            if(j > 0 && s[j] == s[j-1] && (j-2 < 0 || s[j] != s[j-2])){
                dp[i+1] = (dp[i+1] + sum) % MOD;
                break;
            }
        }
        dp[i+1] = (dp[i+1] + sum) % MOD;
    }
    cout << dp[n] << "\n";
}