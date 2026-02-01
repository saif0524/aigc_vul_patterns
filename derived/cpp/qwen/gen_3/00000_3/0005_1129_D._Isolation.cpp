#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> dp(n+1, 0), freq(n+1, 0);
    dp[0] = 1;
    int unique = 0;
    for(int i=1; i<=n; i++){
        if(freq[a[i-1]] == 0) unique++;
        freq[a[i-1]]++;
        for(int j=i; j>=1; j--){
            if(unique <= k){
                dp[i] = (dp[i] + dp[j-1]) % MOD;
            }
            freq[a[j-1]]--;
            if(freq[a[j-1]] == 0) unique--;
            if(freq[a[j-1]] == 1) unique++;
            if(unique > k) break;
        }
    }
    cout << dp[n];
}