#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> obstacles(4, vector<bool>(m + 1, false));
    for (int i = 0; i < n; ++i) {
        int a, l, r;
        cin >> a >> l >> r;
        for (int j = l; j <= r; ++j) {
            obstacles[a][j] = true;
        }
    }

    vector<vector<long long>> dp(4, vector<long long>(m + 1, 0));
    dp[2][1] = 1;

    for (int j = 1; j < m; ++j) {
        for (int i = 1; i <= 3; ++i) {
            if (obstacles[i][j]) continue;
            if (i > 1 && !obstacles[i - 1][j + 1]) {
                dp[i - 1][j + 1] = (dp[i - 1][j + 1] + dp[i][j]) % MOD;
            }
            if (!obstacles[i][j + 1]) {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
            if (i < 3 && !obstacles[i + 1][j + 1]) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[2][m] << endl;

    return 0;
}