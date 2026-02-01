#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> weights(n);
    for (auto &w : weights) {
        std::cin >> w;
    }
    int total_weight = std::accumulate(weights.begin(), weights.end(), 0);
    if (total_weight % 2 != 0) {
        std::cout << "NO";
        return 0;
    }
    int target = total_weight / 2;
    std::vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (const auto &w : weights) {
        for (int j = target; j >= w; j--) {
            dp[j] = dp[j] || dp[j - w];
        }
    }
    std::cout << (dp[target] ? "YES" : "NO");
}