#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> intervals(n);
    for(auto &p : intervals) cin >> p.first >> p.second;
    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    });
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    long long sum = 0;
    int last_end = -1;
    for(int i = 0; i < n; ++i){
        int start = intervals[i].first;
        int end = intervals[i].second;
        if(start > last_end){
            for(int j = k; j > 0; --j) dp[j] = (sum + (j < k ? dp[j] : 0)) % MOD;
            sum = (sum * 2) % MOD;
            sum = (sum + dp[0]) % MOD;
            last_end = end;
        }
        sum = (sum - dp[k] + MOD) % MOD;
        dp[k] = (dp[k] + dp[k-1]) % MOD;
        for(int j = k-1; j > 0; --j) dp[j] = (dp[j] + dp[j-1]) % MOD;
        dp[0] = (dp[0] + 1) % MOD;
    }
    cout << dp[k];
}