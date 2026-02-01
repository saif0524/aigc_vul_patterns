#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <cstring>

const int mod = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> obstacles(n);
    for (auto& [a, l, r] : obstacles) {
        std::cin >> a >> l >> r;
    }

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(3));
    dp[1][1] = 1;

    for (int i = 2; i <= m; ++i) {
        std::vector<bool> blocked(3);
        for (const auto& [a, l, r] : obstacles) {
            if (l <= i && i <= r) {
                blocked[a - 1] = true;
            }
        }

        for (int j = 0; j < 3; ++j) {
            if (blocked[j]) {
                dp[i][j] = 0;
                continue;
            }

            for (int k = std::max(0, j - 1); k <= std::min(2, j + 1); ++k) {
                if (!blocked[k]) {
                    dp[i][j] = add(dp[i][j], dp[i - 1][k]);
                }
            }
        }
    }

    std::cout << dp[m][1] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) solve();

    return 0;
}