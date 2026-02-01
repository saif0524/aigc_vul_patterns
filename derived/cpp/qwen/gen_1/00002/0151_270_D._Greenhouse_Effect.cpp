#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, double>> plants(n);
    for(auto &p : plants) cin >> p.first >> p.second;

    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
    for(int i=0; i<=n; i++) dp[0][i] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            int cnt = 0;
            for(int k=j-1; k>=0; k--){
                if(plants[k].first != i) cnt++;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + cnt);
            }
        }
    }

    cout << dp[m][n];
}