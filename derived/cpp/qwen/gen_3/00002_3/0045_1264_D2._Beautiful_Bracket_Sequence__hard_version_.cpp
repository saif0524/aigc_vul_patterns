#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> open(n+1, 0), close(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '(') open[i] = open[i-1] + 1;
        else if(s[i-1] == ')') close[i] = close[i-1] + 1;
        else open[i] = open[i-1] + 1, close[i] = close[i-1] + 1;
    }
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '('){
            for(int j = 1; j <= i; j++){
                if(open[j-1] - close[j-1] > 0) dp[i] = (dp[i] + dp[j-1]) % MOD;
            }
        }
        else if(s[i-1] == ')'){
            for(int j = i-1; j >= 0; j--){
                if(open[j] - close[j] > 0) dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
        else{
            int sum1 = 0, sum2 = 0;
            for(int j = 1; j <= i; j++){
                if(open[j-1] - close[j-1] > 0) sum1 = (sum1 + dp[j-1]) % MOD;
            }
            for(int j = i-1; j >= 0; j--){
                if(open[j] - close[j] > 0) sum2 = (sum2 + dp[j]) % MOD;
            }
            dp[i] = (dp[i] + (1LL * sum1 * sum2) % MOD) % MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(open[i] == close[i]) ans = (ans + (1LL * (open[i] - close[i]) * dp[i]) % MOD) % MOD;
    }
    cout << ans;
}