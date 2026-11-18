#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n-1);
    for(auto &x: a) cin >> x;
    vector<long long> dp(n+1, 0);
    vector<long long> sufsum(n+1, 0);
    long long ans = 0;
    for(int i=n-2;i>=0;i--){
        dp[i] = 1+ dp[min(a[i], n-1)];
        sufsum[i] = sufsum[i+1] + dp[i];
        ans += dp[i] + sufsum[a[i]+1];
    }
    cout << ans;
    return 0;
}