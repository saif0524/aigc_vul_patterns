#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

std::vector<std::vector<Edge>> graph;
std::vector<int> potential;
std::vector<bool> visited;

bool bellmanFord(int n) {
    potential.assign(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (const auto& edge : graph[u]) {
                if (potential[u] + edge.weight > potential[edge.to]) {
                    potential[edge.to] = potential[u] + edge.weight;
                }
            }
        }
    }

    for (int u = 0; u < n; ++u) {
        for (const auto& edge : graph[u]) {
            if (potential[u] + edge.weight > potential[edge.to]) {
                return true;
            }
        }
    }
    return false;
}

int getMinCycleLength(int n) {
    std::queue<int> queue;
    visited.assign(n, false);

    int minCycleLength = INF;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue.push(i);
            visited[i] = true;
            int cycleLength = 0;
            while (!queue.empty()) {
                int u = queue.front();
                queue.pop();
                ++cycleLength;
                for (const auto& edge : graph[u]) {
                    if (edge.weight > 0 && !visited[edge.to]) {
                        queue.push(edge.to);
                        visited[edge.to] = true;
                    }
                }
            }
            minCycleLength = std::min(minCycleLength, cycleLength);
        }
    }
    return (minCycleLength == INF) ? 0 : minCycleLength;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c1, c2;
        std::cin >> u >> v >> c1 >> c2;
        --u;
        --v;
        graph[u].push_back({v, c1});
        graph[v].push_back({u, c2});
    }

    if (!bellmanFord(n)) {
        std::cout << "0\n";
    } else {
        std::cout << getMinCycleLength(n) << "\n";
    }

    return 0;
}