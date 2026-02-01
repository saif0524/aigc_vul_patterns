#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    for(int i=0;i<k;i++){
        vector<long long> new_dp(n+1, 0);
        long long pre = 0;
        for(int j=1;j<=n;j++){
            if(s[j-1] == '0') continue;
            pre = (pre + dp[j-1]) % MOD;
            if(j + n - j >= n - i - 1) new_dp[j] = (new_dp[j] + pre) % MOD;
        }
        dp = new_dp;
    }
    long long result = 0;
    for(int i=1;i<=n;i++){
        if(s[n-i] == '0') continue;
        result = (result + dp[n-i] * (s[n-i] - '0')) % MOD;
    }
    cout << result;
}