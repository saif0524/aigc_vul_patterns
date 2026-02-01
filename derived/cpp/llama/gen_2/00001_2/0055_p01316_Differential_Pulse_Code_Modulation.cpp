#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int N, M;
    while (std::cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }

        std::vector<int> C(M);
        for (int i = 0; i < M; i++) {
            std::cin >> C[i];
        }

        std::vector<int> x(N);
        for (int i = 0; i < N; i++) {
            std::cin >> x[i];
        }

        const int INF = INT_MAX / 2;
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(256, INF));
        dp[0][128] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 256; j++) {
                if (dp[i][j] == INF) {
                    continue;
                }

                for (int k = 0; k < M; k++) {
                    int nj = std::min(255, std::max(0, j + C[k]));
                    dp[i + 1][nj] = std::min(dp[i + 1][nj], dp[i][j] + (x[i] - j) * (x[i] - j));
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < 256; i++) {
            ans = std::min(ans, dp[N][i] + (x[N - 1] - i) * (x[N - 1] - i));
        }

        std::cout << ans << std::endl;
    }

    return 0;
}