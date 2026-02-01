#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> intervals(n);
    for(auto &p : intervals){
        cin >> p.first >> p.second;
    }
    sort(intervals.begin(), intervals.end());
    
    vector<long long> dp(k+1, 0);
    dp[0] = 1;
    vector<long long> prefix(k+1, 0);
    prefix[0] = 1;
    
    int current_right = -1;
    int active = 0;
    
    for(int i = 0; i < n; ++i){
        int l = intervals[i].first;
        int r = intervals[i].second;
        while(current_right < l){
            current_right++;
            if(active >= k){
                prefix[active+1] = (prefix[active+1] + prefix[active]) % MOD;
            }
            if(active >= k){
                dp[active] = (dp[active] + prefix[active+1] - prefix[k] + MOD) % MOD;
            }
            if(active >= 1){
                prefix[active] = (prefix[active] + dp[active-1]) % MOD;
            }
            if(active >= k){
                prefix[k] = (prefix[k] + dp[k-1]) % MOD;
            }
            if(active >= 1){
                active--;
            }
        }
        if(active < k){
            dp[active+1] = (dp[active+1] + prefix[active]) % MOD;
            prefix[active+1] = (prefix[active+1] + prefix[active]) % MOD;
            active++;
        }
    }
    long long result = dp[k];
    cout << result;
    return 0;
}