#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> dp(n+1, 0);
    long long ans = 0;
    for(int i=0;i<n;i++){
        dp[i+1] = dp[i];
        if(i-1>=0&& s[i]==s[i-1]){
            dp[i+1] = max(dp[i+1], (long long)i-1+1);
        }
        if(i-2>=0&& s[i]==s[i-2]){
            dp[i+1] = max(dp[i+1], (long long)i-2+1);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i+1<n && s[i]==s[i+1]){
            dp[i] = max(dp[i], dp[i+2]+2);
        }
        if(i+2<n && s[i]==s[i+2]){
            dp[i] = max(dp[i], dp[i+3]+3);
        }
        ans += dp[i];
    }
    cout << ans;
}