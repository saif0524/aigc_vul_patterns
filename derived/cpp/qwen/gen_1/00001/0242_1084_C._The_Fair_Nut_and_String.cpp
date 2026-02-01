#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long cnt_b = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'b'){
            cnt_b = (cnt_b + dp[i]) % MOD;
        } else if(s[i] == 'a'){
            dp[i + 1] = (dp[i] + cnt_b) % MOD;
        }
    }
    long long ans = 0;
    for(int i = 0; i <= n; ++i){
        if(s[i - 1] == 'a'){
            ans = (ans + dp[i]) % MOD;
        }
    }
    cout << ans;
}