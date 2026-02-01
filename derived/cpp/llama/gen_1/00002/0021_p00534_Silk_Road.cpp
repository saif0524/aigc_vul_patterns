#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> D(N);
    for (int i = 0; i < N; i++) {
        std::cin >> D[i];
    }

    std::vector<int> C(M);
    for (int i = 0; i < M; i++) {
        std::cin >> C[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dp[i][j] != INT_MAX) {
                dp[i][j + 1] = std::min(dp[i][j + 1], dp[i][j]);
                if (j + 1 <= M - (N - i - 1)) {
                    dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + D[i] * C[j]);
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= M; i++) {
        ans = std::min(ans, dp[N][i]);
    }

    std::cout << ans << std::endl;

    return 0;
}