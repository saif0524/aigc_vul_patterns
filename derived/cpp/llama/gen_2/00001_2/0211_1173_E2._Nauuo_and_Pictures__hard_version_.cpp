#include <iostream>
#include <vector>

const long long MOD = 998244353;

long long pow(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

long long inv(long long x) {
    return pow(x, MOD - 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> like(n);
    std::vector<long long> w(n);
    for (int i = 0; i < n; ++i) std::cin >> like[i];
    for (int i = 0; i < n; ++i) std::cin >> w[i];

    long long sumW = 0;
    for (int i = 0; i < n; ++i) sumW += w[i];

    std::vector<long long> dp(m + 1, 0), pw(m + 1, 0);
    for (int i = 1; i <= m; ++i) pw[i] = (i * inv(m)) % MOD;

    for (int i = m - 1; i >= 0; --i) {
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            sum = (sum + like[j] * w[j]) % MOD;
        }
        dp[i] = (dp[i + 1] + sum * inv(sumW)) % MOD;
        sumW = (sumW + sum) % MOD;
        for (int j = 0; j < n; ++j) {
            if (!like[j]) w[j]--;
            else w[j]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        long long ans = 0;
        for (int j = 0; j <= m; ++j) {
            ans = (ans + pw[j] * (w[i] + dp[j])) % MOD;
        }
        std::cout << ans << " ";
    }

    return 0;
}