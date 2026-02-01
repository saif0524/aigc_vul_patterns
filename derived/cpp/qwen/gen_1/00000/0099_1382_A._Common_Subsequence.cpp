#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i][j] || dp[i-1][j-1];
            }
        }
        if(!dp[n][m]){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<int> ans;
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(a[i-1] == b[j-1] && dp[i-1][j-1]){
                ans.push_back(a[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << " ";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}