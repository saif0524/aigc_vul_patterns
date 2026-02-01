#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> S(N);
    std::vector<int> T(M);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> T[i];
    }

    long long dp[N + 1][M + 1][2] = {};
    dp[0][0][0] = 1;

    for (int n = 0; n <= N; n++) {
        for (int m = 0; m <= M; m++) {
            long long skipS = dp[n][m][0];
            long long skipT = dp[n][m][1];

            if (n < N) {
                dp[n + 1][m][0] += skipS;
                dp[n + 1][m][0] %= MOD;
            }
            if (m < M) {
                dp[n][m + 1][1] += skipT;
                dp[n][m + 1][1] %= MOD;
            }

            if (n < N && m < M && S[n] == T[m]) {
                dp[n + 1][m + 1][0] += skipS;
                dp[n + 1][m + 1][0] %= MOD;
                dp[n + 1][m + 1][1] += skipT;
                dp[n + 1][m + 1][1] %= MOD;
            }
        }
    }

    long long ans = 0;
    for (int n = 0; n <= N; n++) {
        for (int m = 0; m <= M; m++) {
            ans += dp[n][m][0];
            ans %= MOD;
            ans += dp[n][m][1];
            ans %= MOD;
        }
    }

    std::cout << ans - 1 << std::endl;
    return 0;
}