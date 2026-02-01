#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    int m;
    cin >> m;
    vector<pair<int,int>> queries(m);
    for(auto &q : queries) cin >> q.first >> q.second;
    for(auto &[k, pos] : queries){
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, -1e18));
        vector<vector<int>> par(n+1, vector<int>(k+1, -1));
        dp[0][0] = 0;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=k; ++j){
                dp[i][j] = dp[i-1][j];
                par[i][j] = i-1;
                if(j > 0 && dp[i-1][j-1] + a[i-1] >= dp[i][j]){
                    dp[i][j] = dp[i-1][j-1] + a[i-1];
                    par[i][j] = i-1;
                }
            }
        }
        vector<int> ans;
        int idx = n, len = k;
        while(idx > 0 && len > 0){
            if(par[idx][len] == idx - 1 && dp[idx][len] == dp[idx-1][len]){
                idx--;
            }
            else{
                ans.push_back(a[idx-1]);
                idx--;
                len--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans[pos-1] << "\n";
    }
}