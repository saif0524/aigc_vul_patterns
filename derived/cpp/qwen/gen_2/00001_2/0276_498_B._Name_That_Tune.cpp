#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, T;
    cin >> n >> T;
    vector<pair<int, int>> songs(n);
    for(auto &song : songs){
        cin >> song.first >> song.second;
    }
    double dp[T+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int t=1; t<=T; t++){
        for(int k=0; k<n; k++){
            dp[t][k] += dp[t-1][k];
            if(t >= songs[k].second){
                dp[t][k+1] += dp[t-1][k];
            }
            else{
                double p = songs[k].first / 100.0;
                dp[t][k] += dp[t-1][k] * p;
                dp[t][k+1] += dp[t-1][k] * (1-p);
            }
        }
    }
    double ans = 0;
    for(int k=1; k<=n; k++){
        ans += k * dp[T][k];
    }
    cout << fixed << setprecision(10) << ans;
}