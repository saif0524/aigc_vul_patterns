#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> chairs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> chairs[i];
    }

    std::vector<int> occupied, unoccupied;
    for (int i = 0; i < n; i++) {
        if (chairs[i] == 1) {
            occupied.push_back(i);
        } else {
            unoccupied.push_back(i);
        }
    }

    int m = occupied.size();
    int k = unoccupied.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(k + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + std::abs(occupied[i - 1] - unoccupied[j - 1]));
        }
    }

    std::cout << dp[m][k] << std::endl;

    return 0;
}