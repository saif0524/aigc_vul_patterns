#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int to;
    int cost;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, cuv, cvu;
        std::cin >> u >> v >> cuv >> cvu;
        --u;
        --v;
        graph[u].push_back({v, cuv});
        graph[v].push_back({u, cvu});
    }

    int minCycleLength = INF;

    for (int s = 0; s < n; ++s) {
        std::vector<int> dist(n, -INF);
        std::vector<int> predecessor(n, -1);
        dist[s] = 0;

        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;
            for (int u = 0; u < n; ++u) {
                for (const auto& edge : graph[u]) {
                    if (dist[u] + edge.cost > dist[edge.to]) {
                        dist[edge.to] = dist[u] + edge.cost;
                        predecessor[edge.to] = u;
                        updated = true;
                    }
                }
            }
            if (!updated) break;
        }

        for (int u = 0; u < n; ++u) {
            for (const auto& edge : graph[u]) {
                if (dist[u] + edge.cost > dist[edge.to]) {
                    int cycleLength = 0;
                    int v = edge.to;
                    while (v != u) {
                        ++cycleLength;
                        v = predecessor[v];
                    }
                    ++cycleLength;
                    minCycleLength = std::min(minCycleLength, cycleLength);
                }
            }
        }
    }

    if (minCycleLength == INF) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << minCycleLength << std::endl;
    }

    return 0;
}