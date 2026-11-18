#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, double>> plants(n);
    for(auto &p : plants){
        cin >> p.first >> p.second;
    }
    vector<vector<int>> dp(m+1, vector<int>(n+1, 1e9));
    dp= 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1];
            int cnt = 0;
            for(int k=j;k>=1;k--){
                if(plants[k-1].first != i) cnt++;
                dp[i][j] = min(dp[i][j], dp[i-1][k-1] + cnt);
            }
        }
    }
    cout << dp[m][n] << "\n";
}