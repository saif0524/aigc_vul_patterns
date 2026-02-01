#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tags(n);
        vector<long long> scores(n);
        for(int i=0;i<n;i++) cin >> tags[i];
        for(int i=0;i<n;i++) cin >> scores[i];
        vector<vector<long long>> dp(47, vector<long long>(n+1, LLONG_MIN));
        for(int i=0;i<n;i++){
            dp[0][i] = scores[i];
        }
        for(int i=1;i<47;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(tags[j]!=tags[k] && (1LL<<(i-1)) < abs((1LL<<j) - (1LL<<k))){
                        dp[i][k] = max(dp[i][k], dp[i-1][j] + abs(scores[j] - scores[k]));
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<47;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
}