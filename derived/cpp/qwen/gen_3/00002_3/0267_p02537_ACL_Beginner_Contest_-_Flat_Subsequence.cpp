#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &a: A) cin >> a;
    
    int dp[300001] = {0};
    int ans = 0;
    
    for(auto a: A){
        int L = max(0, a - K);
        int R = min(300000, a + K);
        int mx = *max_element(dp + L, dp + R + 1);
        dp[a] = mx + 1;
        ans = max(ans, dp[a]);
    }
    
    cout << ans;
}