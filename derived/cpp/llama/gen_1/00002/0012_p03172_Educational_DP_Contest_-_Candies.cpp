#include <iostream>
#include <vector>

const int MOD = 1000000007;

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (static_cast<long long>(a) * b) % MOD;
}

int pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx += a[i];
    }

    if (k > mx) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= a[i - 1] && l <= j; l++) {
                dp[i][j] = add(dp[i][j], dp[i - 1][j - l]);
            }
        }
    }

    std::cout << dp[n][k] << std::endl;
    return 0;
}