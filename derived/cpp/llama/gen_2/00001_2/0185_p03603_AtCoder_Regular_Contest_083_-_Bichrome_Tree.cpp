#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <cstdint>

std::vector<std::vector<int>> adj;
std::vector<int> x;

void dfs(int u, std::vector<std::bitset<5001>>& dp) {
    dp[u][0] = 1;
    for (int v : adj[u]) {
        dfs(v, dp);
        std::bitset<5001> sum = 0;
        for (int i = 0; i <= 5000; ++i) {
            if (dp[u][i]) {
                for (int j = 0; j <= 5000; ++j) {
                    if (dp[v][j]) {
                        sum.set(i + j);
                    }
                }
            }
        }
        dp[u] = sum;
    }
    if (!dp[u][x[u]]) {
        std::cout << "IMPOSSIBLE\n";
        exit(0);
    }
}

int main() {
    int n;
    std::cin >> n;

    adj.resize(n);

    for (int i = 1; i < n; ++i) {
        int p;
        std::cin >> p;
        --p;
        adj[p].push_back(i);
    }

    x.resize(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    std::vector<std::bitset<5001>> dp(n);

    dfs(0, dp);

    std::cout << "POSSIBLE\n";

    return 0;
}