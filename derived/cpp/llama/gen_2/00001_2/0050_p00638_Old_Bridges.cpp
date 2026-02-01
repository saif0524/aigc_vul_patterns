#include <iostream>
#include <vector>
#include <algorithm>

bool dfs(int cur, int sum, const std::vector<std::pair<int, int>>& islands, std::vector<bool>& visited) {
    if (sum < 0) return false;
    visited[cur] = true;
    if (cur == 0 && std::all_of(visited.begin() + 1, visited.end(), [](bool v) { return v; })) {
        return true;
    }
    for (int i = 0; i < islands.size(); ++i) {
        if (!visited[i] && islands[i].second >= sum) {
            if (dfs(i, sum + islands[i].first, islands, visited)) return true;
        }
    }
    visited[cur] = false;
    return false;
}

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) break;
        std::vector<std::pair<int, int>> islands(n + 1);
        islands[0] = {0, INT_MAX};
        for (int i = 1; i <= n; ++i) {
            int a, b;
            std::cin >> a >> b;
            islands[i] = {a, b};
        }
        std::vector<bool> visited(n + 1, false);
        if (dfs(0, 0, islands, visited)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}