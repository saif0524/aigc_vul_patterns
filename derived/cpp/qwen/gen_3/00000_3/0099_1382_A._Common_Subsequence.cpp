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
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        if(dp[n][m] == 0){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << dp[n][m] << " ";
            vector<int> ans;
            int i=n, j=m;
            while(i > 0 && j > 0){
                if(a[i-1] == b[j-1]){
                    ans.push_back(a[i-1]);
                    i--;
                    j--;
                } else if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                } else {
                    j--;
                }
            }
            reverse(ans.begin(), ans.end());
            for(int x : ans){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}