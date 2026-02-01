#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<vector<int>> fac(n + 1, vector<int>(n + 1));
    fac[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            fac[i][j] = (fac[i - 1][j] + fac[i - 1][j - 1]) % MOD;
        }
    }

    vector<int> dp(n, 0);
    dp[0] = 1;
    vector<int> used(n, 0);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (used[j] != b[i]) {
                dp[i] = (dp[i] + (long long) dp[j] * fac[i - 1][j] % MOD) % MOD;
            }
        }
        used[i] = b[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used[i] != i) {
            ans = (ans + (long long) dp[i] * fac[n - 1][i] % MOD) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}