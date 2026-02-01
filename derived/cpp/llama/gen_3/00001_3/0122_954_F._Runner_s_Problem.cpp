#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

struct Obstacle {
    int row, left, right;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Obstacle> obstacles(n);
    for (auto& o : obstacles) {
        cin >> o.row >> o.left >> o.right;
    }

    vector<vector<int>> dp(3, vector<int>(m + 1, 0));
    dp[1][1] = 1;

    for (int j = 2; j <= m; ++j) {
        for (int i = 0; i < 3; ++i) {
            bool blocked = false;
            for (const auto& o : obstacles) {
                if (o.row == i + 1 && o.left <= j && j <= o.right) {
                    blocked = true;
                    break;
                }
            }
            if (blocked) {
                dp[i][j] = 0;
                continue;
            }

            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            if (i < 2) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % MOD;
            }
        }
    }

    cout << dp[1][m] << '\n';

    return 0;
}