#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> dp(4, vector<long long>(m+1, 0));
    for(long long i = 0; i < n; ++i){
        long long w, c;
        cin >> w >> c;
        for(long long j = m; j >= w; --j){
            dp[w][j] = max(dp[w][j], dp[w-w][j-w] + c);
        }
    }
    long long max_cost = 0;
    for(long long i = 0; i <= m; ++i){
        for(long long j = 0; j < 4; ++j){
            max_cost = max(max_cost, dp[j][i]);
        }
    }
    cout << max_cost;
}