#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> dp(n+1, 0), dp2(n+1, 0), f(n+1, 0), f2(n+1, 0);
    dp[0] = f[0] = 1;
    for(int i = 1; i <= n; ++i){
        if(s[i-1] == '('){
            dp[i] = (dp[i-1] + f[i-1]) % MOD;
            f[i] = (f[i-1] * 2) % MOD;
        }
        else if(s[i-1] == ')'){
            dp[i] = f2[i-1];
            f[i] = 0;
        }
        else{
            dp[i] = (dp[i-1] + f[i-1] + f2[i-1]) % MOD;
            f[i] = (f[i-1] * 2 + f2[i-1]) % MOD;
        }
        if(s[i-1] == ')'){
            dp2[i] = (dp2[i-1] + dp[i-1]) % MOD;
            f2[i] = (f2[i-1] * 2 + f[i-1]) % MOD;
        }
        else if(s[i-1] == '('){
            dp2[i] = f[i-1];
            f2[i] = (f[i-1] * 2) % MOD;
        }
        else{
            dp2[i] = (dp2[i-1] + dp[i-1] + f[i-1]) % MOD;
            f2[i] = (f2[i-1] * 2 + f[i-1] * 2) % MOD;
        }
    }
    cout << (dp[n] + dp2[n]) % MOD;
    return 0;
}