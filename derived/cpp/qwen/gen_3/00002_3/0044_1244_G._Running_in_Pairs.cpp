#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> dp(n+1, 0);
    vector<int> ans1(n), ans2(n);
    for(int i=1; i<=n; ++i){
        vector<long long> new_dp(dp);
        for(int j=1; j<=n; ++j){
            if(dp[i-1] + max(i, j) <= k){
                if(dp[i-1] + max(i, j) > new_dp[i]){
                    new_dp[i] = dp[i-1] + max(i, j);
                    if(i >= j){
                        ans1[i-1] = i;
                        ans2[i-1] = j;
                    }
                    else{
                        ans1[i-1] = j;
                        ans2[i-1] = i;
                    }
                }
            }
        }
        dp = new_dp;
    }
    if(dp[n] == 0){
        cout << "-1";
        return 0;
    }
    cout << dp[n] << "\n";
    for(int i=0; i<n; ++i) cout << ans1[i] << " \n"[i==n-1];
    for(int i=0; i<n; ++i) cout << ans2[i] << " \n"[i==n-1];
}