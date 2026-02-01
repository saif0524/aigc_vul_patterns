#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> rows(n);
    for (auto& row : rows) {
        cin >> row;
    }

    vector<int> counts(m, 0);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (rows[i][j] == '1') {
                ++counts[j];
            }
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n + 1, 1e9));
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int j = 0; j < m; ++j) {
            int ones = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0 && rows[i][j] == '1') {
                    ++ones;
                } else if ((mask & (1 << i)) != 0 && rows[i][j] == '0') {
                    ++ones;
                }
            }
            dp[mask][ones] = min(dp[mask][ones], counts[j]);
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j <= n; ++j) {
                if ((i & (1 << k)) == 0) {
                    int mask = i ^ (1 << k);
                    dp[mask][j] = min(dp[mask][j], dp[i][j]);
                    if (j < n) {
                        dp[mask][n - j] = min(dp[mask][n - j], dp[i][j]);
                    }
                }
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i <= n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    cout << ans << '\n';
    return 0;
}