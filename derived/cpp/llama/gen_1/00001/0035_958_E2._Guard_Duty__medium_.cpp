#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int k, n;
    std::cin >> k >> n;

    std::vector<int> times(n);
    for (int i = 0; i < n; i++) {
        std::cin >> times[i];
    }

    std::sort(times.begin(), times.end());

    int dp[k + 1][n];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int j = 0; j < n; j++) {
        dp[1][j] = times[j] - times[0];
    }

    for (int i = 2; i <= k; i++) {
        int min_val = INT_MAX;
        for (int j = i - 1; j < n; j++) {
            min_val = std::min(min_val, dp[i - 1][j - 1]);
            dp[i][j] = min_val + times[j] - times[j - i + 1];
        }
    }

    int ans = INT_MAX;
    for (int j = k - 1; j < n; j++) {
        ans = std::min(ans, dp[k][j]);
    }

    std::cout << ans << std::endl;

    return 0;
}