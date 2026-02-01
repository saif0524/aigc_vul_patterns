#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

const int INF = INT_MAX / 2;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        std::vector<std::vector<int>> ndp(n + 1, std::vector<int>(n + 1, INF));
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (dp[j][k] == INF) continue;

                if (j > 0) {
                    ndp[j - 1][k] = std::min(ndp[j - 1][k], dp[j][k] + b[i]);
                }
                if (k < n) {
                    ndp[j + 1][k] = std::min(ndp[j + 1][k], dp[j][k] + a[i]);
                }
            }
        }
        dp = ndp;
    }

    std::vector<int> c(n + 1, INF);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            c[i] = std::min(c[i], dp[i][j]);
        }
    }

    std::vector<int> nc(n + 1, INF);
    for (int i = 0; i <= n; ++i) {
        if (c[i] == INF) continue;
        for (int j = 0; j <= n; ++j) {
            nc[i + j] = std::min(nc[i + j], c[i] + c[j]);
        }
    }
    c = nc;

    int ans = INF;
    for (int i = 0; i <= n; ++i) {
        ans = std::min(ans, c[i]);
    }

    std::cout << ans * m / 2LL << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}