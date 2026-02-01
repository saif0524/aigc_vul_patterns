#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> obstacle(3, vector<bool>(m + 1, false));
    for (int i = 0; i < n; ++i) {
        int a, l, r;
        cin >> a >> l >> r;
        for (int j = l; j <= r; ++j) {
            obstacle[a - 1][j] = true;
        }
    }

    vector<vector<long long>> dp(3, vector<long long>(m + 1, 0));
    dp[1][1] = 1;

    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < 3; ++i) {
            if (obstacle[i][j]) continue;
            if (dp[i][j] == 0) continue;

            // Move to (i - 1, j + 1)
            if (i > 0 && !obstacle[i - 1][j + 1]) {
                dp[i - 1][j + 1] = (dp[i - 1][j + 1] + dp[i][j]) % MOD;
            }

            // Move to (i, j + 1)
            if (!obstacle[i][j + 1]) {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }

            // Move to (i + 1, j + 1)
            if (i < 2 && !obstacle[i + 1][j + 1]) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    if (obstacle[1][m]) {
        cout << 0 << endl;
    } else {
        cout << dp[1][m] << endl;
    }

    return 0;
}