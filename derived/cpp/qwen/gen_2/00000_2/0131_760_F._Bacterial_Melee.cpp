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
    vector<int> dp(n, 1);
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i-1]){
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }
        for(int j = i-2; j >= 0; --j){
            if(s[j] == s[i]){
                dp[i] = (dp[i] + dp[j]) % MOD;
                break;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans;
}