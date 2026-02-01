#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> dp(n, 0);
    int ans = 0;
    for(int i = n-2; i >= 0; --i){
        if(a[i] > a[i+1]){
            dp[i] = dp[i+1] + 1;
        } else {
            int j = i + dp[i+1] + 1;
            if(j < n && a[i] > a[j]) dp[i] = dp[i+1] + 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}