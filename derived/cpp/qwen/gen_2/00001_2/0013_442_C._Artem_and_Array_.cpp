#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    if(n == 1){
        cout << 0;
        return 0;
    }
    vector<long long> dp(n, 0);
    dp[0] = 0;
    dp[1] = min(a[0], a[1]);
    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + min(a[i-1], a[i]));
    }
    cout << dp[n-1];
}