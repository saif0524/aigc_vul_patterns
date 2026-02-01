#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long dp[2000005];

void solve() {
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
    }
    cout << (3 * dp[n - 2] - dp[n - 3] + MOD) % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}