#include <iostream>
#include <vector>

#define MOD 1000000007

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> dp(K + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        std::vector<int> new_dp(K + 1, 0);
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k <= a[i] && j + k <= K; ++k) {
                new_dp[j + k] = (new_dp[j + k] + dp[j]) % MOD;
            }
        }
        dp = new_dp;
    }

    std::cout << dp[K] << std::endl;

    return 0;
}