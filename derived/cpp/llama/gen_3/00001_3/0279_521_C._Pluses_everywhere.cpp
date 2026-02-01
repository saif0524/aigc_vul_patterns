#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    ll dp[n][k + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j >= 0; j--) {
            sum = (sum * 10 + str[j] - '0') % MOD;
            if (i - j + 1 <= k + 1) {
                for (int x = 0; x <= k; x++) {
                    if (x == 0 && i == j) {
                        if (str[j] != '0')
                            dp[i][x] = (dp[i][x] + sum) % MOD;
                    } else if (x > 0 && i > j) {
                        dp[i][x] = (dp[i][x] + (sum * dp[j - 1][x - 1]) % MOD) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[n - 1][k] << '\n';

    return 0;
}