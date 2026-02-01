#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        dp[i + 1] = dp[i];
        if(i > 0 && s[i] == s[i - 1]){
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
        }
    }
    cout << dp[n] << endl;
}