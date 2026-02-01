#include <iostream>
#include <vector>
#include <cstdio>

const int MOD = 1000000007;

std::vector<long long> pow3(900005);

void init_pow3() {
    pow3[0] = 1;
    for (int i = 1; i <= 900000; i++) {
        pow3[i] = (pow3[i - 1] * 3) % MOD;
    }
}

long long dp[300005][300005][300005];

long long count_ways(int n, int m, int k) {
    if (n == 0 && m == 0 && k == 0) {
        return 0;
    }
    if (dp[n][m][k] != -1) {
        return dp[n][m][k];
    }
    long long ans = 0;
    if (n > 0) {
        ans += (count_ways(n - 1, m, k) + pow3[m + k]) % MOD;
        ans %= MOD;
    }
    if (m > 0) {
        ans += (count_ways(n, m - 1, k) * 2) % MOD;
        ans %= MOD;
    }
    if (k > 0) {
        ans += (count_ways(n, m, k - 1) * 2) % MOD;
        ans %= MOD;
    }
    return dp[n][m][k] = ans;
}

int main() {
    init_pow3();
    for (int i = 0; i <= 300000; i++) {
        for (int j = 0; j <= 300000; j++) {
            for (int k = 0; k <= 300000; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    int n, m, k;
    std::cin >> n >> m >> k;
    std::cout << count_ways(n, m, k) << std::endl;
    return 0;
}