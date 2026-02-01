#include <bits/stdc++.h>
using namespace std;

int n, m;
int l[2005], s[2005], c[2005 + 2005];

int dp[2005][2005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n+m;i++) cin >> c[i];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            int cost = 0;
            int profit = 0;
            int mx = j;
            vector<int> cnt(m + n + 1, 0);
            for(int k=i-1;k>=0;k--){
                cost += s[k];
                if(l[k] > mx){
                    break;
                }
                cnt[l[k]]++;
                profit += c[l[k]];
                while(cnt[l[k]] > 1){
                    cnt[l[k]]--;
                    cnt[l[k] + 1]++;
                    profit -= c[l[k]];
                    profit += c[l[k] + 1];
                    l[k]++;
                }
                mx = max(mx, l[k]);
                dp[i][mx] = max(dp[i][mx], dp[k][j] + profit - cost);
            }
        }
    }
    
    int ans = -1e9;
    for(int i=0;i<=m;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}