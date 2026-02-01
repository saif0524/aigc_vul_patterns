#include <iostream>
#include <vector>

int countSets(int n, int k, int s, std::vector<std::vector<std::vector<int>>>& dp) {
    if (k == 0) return s == 0 ? 1 : 0;
    if (n == 0 || s <= 0) return 0;
    if (dp[n][k][s] != -1) return dp[n][k][s];
    dp[n][k][s] = countSets(n - 1, k, s, dp) + countSets(n - 1, k - 1, s - n, dp);
    return dp[n][k][s];
}

int main() {
    int n, k, s;
    std::vector<std::vector<std::vector<int>>> dp(21, std::vector<std::vector<int>>(11, std::vector<int>(156, -1)));
    while (std::cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) break;
        std::cout << countSets(n, k, s, dp) << std::endl;
    }
    return 0;
}