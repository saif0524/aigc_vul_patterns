#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

long long powMod(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int a, b, k, t;
    std::cin >> a >> b >> k >> t;

    std::vector<std::vector<long long>> dp(t + 1, std::vector<long long>(2 * k * t + 1));
    dp[0][a - b + k * t] = 1;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 2 * k * t + 1; j++) {
            if (j - k >= 0) dp[i + 1][j - k] = (dp[i + 1][j - k] + dp[i][j]) % MOD;
            if (j + k + 1 <= 2 * k * t) dp[i + 1][j + k + 1] = (dp[i + 1][j + k + 1] + dp[i][j]) % MOD;
            for (int x = -k + 1; x <= k; x++) {
                if (j + x >= 0 && j + x <= 2 * k * t) dp[i + 1][j + x] = (dp[i + 1][j + x] + dp[i][j]) % MOD;
            }
        }
    }

    long long res = 0;
    for (int i = k * t + 1; i <= 2 * k * t; i++) {
        res = (res + dp[t][i]) % MOD;
    }

    std::cout << res << std::endl;
    return 0;
}