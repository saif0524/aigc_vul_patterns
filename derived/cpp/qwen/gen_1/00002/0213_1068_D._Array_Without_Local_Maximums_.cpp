#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<ll> dp(n);
    if(a[0] != -1) dp[0] = 1;
    else dp[0] = 200;
    if(a[n-1] != -1) dp[n-1] = 1;
    else dp[n-1] = 200;
    for(int i=1;i<n;i++){
        if(a[i] != -1){
            if(a[i-1] != -1){
                if(a[i] > a[i-1]) dp[i] = 0;
                else dp[i] = dp[i-1];
            }
            else{
                dp[i] = min(a[i],200) - 1 + dp[i-1];
                if(a[i] == 200) dp[i] -= 1;
            }
        }
        else{
            if(a[i-1] != -1){
                dp[i] = 200 - a[i-1] + dp[i-1];
            }
            else{
                dp[i] = dp[i-1] * 200 % MOD;
            }
        }
        dp[i] %= MOD;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i] != -1){
            if(a[i+1] != -1){
                if(a[i] > a[i+1]) dp[i] = 0;
                else dp[i] = min(dp[i],dp[i+1]);
            }
            else{
                dp[i] = min(a[i],200) - 1 + dp[i+1];
                if(a[i] == 200) dp[i] -= 1;
            }
        }
        else{
            if(a[i+1] != -1){
                ll add = dp[i+1] * (200 - a[i+1]) % MOD;
                dp[i] = (dp[i] + add) % MOD;
            }
            else{
                ll add = dp[i+1] * 200 % MOD;
                dp[i] = (dp[i] * 200 % MOD + add) % MOD;
            }
        }
        dp[i] %= MOD;
    }
    cout << dp[0];
}