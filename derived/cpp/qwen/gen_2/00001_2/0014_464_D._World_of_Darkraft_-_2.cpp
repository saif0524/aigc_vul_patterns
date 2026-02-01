#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    double dp[101] = {};
    for(int i = 0; i < n; ++i){
        double new_dp[101] = {};
        for(int j = 1; j <= 100; ++j){
            new_dp[j] = (dp[j] * (j + 1) + j) / (j + 1.0);
        }
        for(int j = 100; j >= 1; --j){
            new_dp[j] += (dp[j - 1] - new_dp[j]) / (j + 1.0);
        }
        for(int j = 1; j <= 100; ++j){
            dp[j] = new_dp[j];
        }
    }
    double ans = 0;
    for(int i = 1; i <= 100; ++i){
        ans += dp[i] / k;
    }
    cout << fixed << setprecision(10) << ans;
}