#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> w(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> w[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - w[i - 1]]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= W; ++j) {
        ans = (ans + dp[N][j]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}