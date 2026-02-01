#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> b(n + 1);
    for (int i = 2; i <= n; i++) {
        std::cin >> b[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
    std::vector<int> dp2(n + 1);

    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k < i; k++) {
                if (k != b[i] && k - 1 != b[i]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
            if (j > 1 && j - 1 != b[i]) {
                dp2[i] = (dp2[i] + dp2[i - 1]) % MOD;
            }
            dp2[i] = (dp2[i] + dp[i][j]) % MOD;
        }
    }

    std::cout << dp2[n] << std::endl;

    return 0;
}