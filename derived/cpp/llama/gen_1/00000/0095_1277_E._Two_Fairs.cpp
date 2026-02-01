#include <iostream>
#include <vector>
#include <utility>

void dfs(const std::vector<std::vector<int>>& graph, int u, int a, int b, std::vector<bool>& visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v] && v != a && v != b) {
            dfs(graph, v, a, b, visited);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n, m, a, b;
        std::cin >> n >> m >> a >> b;
        --a, --b;

        std::vector<std::vector<int>> graph(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        std::vector<bool> visitedA(n, false);
        std::vector<bool> visitedB(n, false);
        dfs(graph, a, a, b, visitedA);
        dfs(graph, b, a, b, visitedB);

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (i != a && i != b && !visitedA[i] && visitedB[i]) {
                ++count;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != a && i != b && !visitedB[i] && visitedA[i]) {
                ++count;
            }
        }

        std::cout << count / 2 << std::endl;
    }

    return 0;
}