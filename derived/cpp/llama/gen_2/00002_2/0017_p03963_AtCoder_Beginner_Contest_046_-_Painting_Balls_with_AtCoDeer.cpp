#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<long long> dp(n + 1, 0);
    dp[1] = k;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] * (k - 1);
    }

    std::cout << dp[n] << std::endl;

    return 0;
}