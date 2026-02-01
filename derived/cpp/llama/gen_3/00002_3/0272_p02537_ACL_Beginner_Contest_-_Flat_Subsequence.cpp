#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (std::abs(A[i] - A[j]) <= K) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = *std::max_element(dp.begin(), dp.end());
    std::cout << ans << std::endl;

    return 0;
}