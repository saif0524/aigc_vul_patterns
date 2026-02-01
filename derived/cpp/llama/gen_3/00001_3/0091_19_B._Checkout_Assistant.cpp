#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2005;
const long long INF = 1e18;

int n;
int t[MAX_N], c[MAX_N];
long long dp[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> c[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + c[i]);
            dp[i + 1][max(0, j - t[i])] = min(dp[i + 1][max(0, j - t[i])], dp[i][j]);
        }
    }

    long long ans = INF;

    for (int j = 0; j <= n; ++j) {
        ans = min(ans, dp[n][j]);
    }

    cout << ans << '\n';

    return 0;
}