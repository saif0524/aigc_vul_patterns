#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n-1);
    for(auto &x: a) cin >> x;
    vector<int> dp(n, 0);
    for(int i=n-2; i>=0; i--){
        dp[i] = 1 + dp[min(n-1, a[i]-1)];
    }
    long long ans = 0;
    for(int i=0; i<n-1; i++){
        for(int j=a[i]-1; j>i; j--){
            dp[j] = min(dp[j], 1 + dp[i]);
        }
    }
    for(int i=0; i<n-1; i++){
        ans += dp[i];
    }
    cout << ans;
}