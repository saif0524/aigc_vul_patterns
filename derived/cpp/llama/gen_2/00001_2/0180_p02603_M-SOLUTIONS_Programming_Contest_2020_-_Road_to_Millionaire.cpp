#include <iostream>
#include <vector>
#include <algorithm>

long long dp[80][1005];

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < 80; ++i) {
        for (int j = 0; j < 1005; ++j) {
            dp[i][j] = -1;
        }
    }

    dp[0][1000] = 1000;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 1005; ++j) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);

            if (i == n - 1) continue;

            if (j >= a[i]) {
                int stock = (j / a[i]);
                int money = j % a[i];
                long long value = stock * a[i + 1] + money;
                dp[i + 1][value] = std::max(dp[i + 1][value], value);
            }

            if (i < n - 1 && j >= a[i] && a[i] < a[i + 1]) {
                long long afterBuy = dp[i][j] - a[i];
                long long afterSell = dp[i][j] + a[i + 1] - a[i];
                dp[i + 1][afterSell] = std::max(dp[i + 1][afterSell], afterSell);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 1005; ++i) {
        if (dp[n][i] > ans) {
            ans = dp[n][i];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}