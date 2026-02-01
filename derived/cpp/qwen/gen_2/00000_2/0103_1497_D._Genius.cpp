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
        vector<vector<long long>> dp(n, vector<long long>(1<<16, LLONG_MIN));
        for(int i=0;i<n;i++){
            dp[i][1<<tags[i]] = scores[i];
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int mask=0;mask<(1<<16);mask++){
                if(dp[i][mask] == LLONG_MIN) continue;
                for(int j=0;j<n;j++){
                    if(tags[i] != tags[j]){
                        int new_mask = mask | (1<<tags[j]);
                        long long new_iq = abs((1LL<<i) - (1LL<<j));
                        if(new_iq < (1<<16)){
                            dp[j][new_mask] = max(dp[j][new_mask], dp[i][mask] + abs(scores[i] - scores[j]));
                            ans = max(ans, dp[j][new_mask]);
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}