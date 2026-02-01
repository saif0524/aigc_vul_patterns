#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int ans = *std::max_element(dp.begin(), dp.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    ans = std::max(ans, dp[j] + 1);
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}