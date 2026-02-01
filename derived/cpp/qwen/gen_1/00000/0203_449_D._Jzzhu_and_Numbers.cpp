#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAX = 21; // 2^20 = 1048576 > 10^6

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    
    vector<ll> dp(1<<MAX, 0);
    dp[0] = 1;
    for(int mask = 0; mask < (1<<MAX); ++mask){
        for(int x : a){
            int newMask = mask & ~x;
            dp[mask] = (dp[mask] + dp[newMask]) % MOD;
        }
    }
    
    ll result = dp[(1<<MAX)-1];
    cout << result << "\n";
    return 0;
}