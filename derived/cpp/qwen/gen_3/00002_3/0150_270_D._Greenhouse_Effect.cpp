#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<double>> plants(m);
    for(int i=0; i<n; i++){
        int s;
        double x;
        cin >> s >> x;
        plants[s-1].push_back(x);
    }
    vector<int> dp(m, 1e9);
    dp[0] = 0;
    for(int i=1; i<m; i++){
        vector<int> new_dp(m, 1e9);
        for(int j=0; j<i; j++){
            int need = dp[j] + (int) plants[i].size() - (int) (upper_bound(plants[j].begin(), plants[j].end(), plants[i].back()) - plants[j].begin());
            new_dp[i] = min(new_dp[i], need);
        }
        for(int j=0; j<=i; j++){
            if(i != j){
                new_dp[j] = min(new_dp[j], dp[j] + (int) plants[i].size());
            }
        }
        dp = new_dp;
    }
    int ans = *min_element(dp.begin(), dp.end());
    cout << ans;
}