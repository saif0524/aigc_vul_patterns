#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    const int mod = 998244353;
    vector<long long> dp(1, 1);
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        int current_width = dp.size();
        for(int j = 0; j < a; ++j){
            dp.push_back(0);
            for(int k = max(0, current_width - 1); k < (int)dp.size() - 1; ++k){
                dp[k + 1] = (dp[k + 1] + dp[k]) % mod;
            }
            current_width++;
        }
        for(int j = 0; j < b; ++j){
            for(int k = current_width - 1; k >= 1; --k){
                dp[k - 1] = (dp[k - 1] + dp[k]) % mod;
                dp[k] = 0;
            }
            current_width--;
        }
    }
    long long ans = 0;
    for(long long x : dp){
        ans = (ans + x) % mod;
    }
    cout << ans;
}