#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> obstacles(n);
    for (int i = 0; i < n; ++i) {
        int a, l, r;
        cin >> a >> l >> r;
        obstacles[i] = make_tuple(a, l, r);
    }

    vector<vector<long long>> dp(3, vector<long long>(m + 1, 0));
    dp[2][1] = 1;

    for (int j = 1; j < m; ++j) {
        for (int i = 1; i <= 3; ++i) {
            bool blocked = false;
            for (int k = 0; k < n; ++k) {
                int a, l, r;
                tie(a, l, r) = obstacles[k];
                if (a == i && j >= l && j <= r) {
                    blocked = true;
                    break;
                }
            }
            if (blocked) continue;

            if (i > 1) {
                dp[i - 1][j + 1] = (dp[i - 1][j + 1] + dp[i][j]) % MOD;
            }
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            if (i < 3) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[2][m] << endl;

    return 0;
}