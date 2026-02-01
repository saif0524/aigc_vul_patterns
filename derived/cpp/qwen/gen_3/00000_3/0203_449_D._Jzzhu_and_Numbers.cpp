#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX = 20;
const int MAX_MASK = (1 << MAX) + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> dp(MAX_MASK, 0);
    dp[0] = 1;
    for(int x : a) {
        for(int mask = MAX_MASK - 1; mask >= 0; --mask) {
            if(dp[mask] == 0) continue;
            dp[mask | x] = (dp[mask | x] + dp[mask]) % MOD;
        }
    }
    int result = 0;
    for(int mask = 1; mask < MAX_MASK; ++mask) {
        if(dp[mask] > 0 && (mask & (mask - 1)) == 0) {
            result = (result + dp[mask]) % MOD;
        }
    }
    cout << result;
    return 0;
}