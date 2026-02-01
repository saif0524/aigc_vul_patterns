#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    vector<vector<ll>> dp(2, vector<ll>(n, 0));
    dp[0][0] = 0;
    dp[1][0] = a[0];
    ll ans = 0;
    for(int i=1;i<n;i++){
        dp[0][i] = dp[1][i-1] + b[i] * i;
        dp[1][i] = dp[0][i-1] + a[i] * i;
        ans = max(ans, max(dp[0][i], dp[1][i]));
    }
    cout << ans;
}