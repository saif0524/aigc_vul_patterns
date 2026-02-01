#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, T;
    cin >> n >> T;
    vector<pair<int,int>> songs(n);
    for(auto &s: songs) cin >> s.first >> s.second;
    vector<double> dp(T+1, 0.0);
    for(int i=0; i<n; i++){
        vector<double> new_dp(T+1, 0.0);
        for(int t=1; t<=T; t++){
            if(t >= songs[i].second){
                new_dp[t] = 1.0;
            } else {
                new_dp[t] = (dp[t] * (1.0 - songs[i].first / 100.0));
            }
            if(t-1 > 0) new_dp[t] += (dp[t-1] * (songs[i].first / 100.0));
        }
        dp = new_dp;
    }
    double expected = 0.0;
    for(int t=1; t<=T; t++) expected += dp[t];
    cout << fixed << setprecision(9) << expected << "\n";
}