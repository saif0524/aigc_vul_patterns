#include <iostream>
#include <vector>

int main() {
    int N, A;
    std::cin >> N >> A;

    std::vector<int> x(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
    }

    long long dp[51][51 * 50 + 1] = {};
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 50; j > 0; j--) {
            for (int k = 50 * 50; k >= x[i]; k--) {
                dp[j][k] += dp[j - 1][k - x[i]];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i * A <= 50 * 50) {
            ans += dp[i][i * A];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}