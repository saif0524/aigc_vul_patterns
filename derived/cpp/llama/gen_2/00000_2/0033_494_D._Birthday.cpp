#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <cstdio>

const int MOD = 1e9 + 7;

struct Edge {
    int to, weight;
};

using Graph = std::vector<std::vector<Edge>>;

Graph readGraph(int n) {
    Graph graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        std::scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    return graph;
}

std::vector<int> distancesFromRoot(Graph& graph) {
    int n = graph.size();
    std::vector<int> distances(n, -1);
    distances[0] = 0;
    std::queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            if (distances[v] == -1) {
                distances[v] = distances[u] + edge.weight;
                queue.push(v);
            }
        }
    }
    return distances;
}

std::vector<std::vector<int>> shortestPaths(Graph& graph) {
    int n = graph.size();
    std::vector<std::vector<int>> shortestPaths(n, std::vector<int>(n));
    std::vector<int> distancesFromRootToAll = distancesFromRoot(graph);
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            shortestPaths[u][v] = distancesFromRootToAll[u] + distancesFromRootToAll[v];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (shortestPaths[i][k] + shortestPaths[k][j] < shortestPaths[i][j]) {
                    shortestPaths[i][j] = shortestPaths[i][k] + shortestPaths[k][j];
                }
            }
        }
    }
    return shortestPaths;
}

void calculateF(Graph& graph, const std::vector<std::vector<int>>& shortestPaths, int u, int v) {
    int n = graph.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (shortestPaths[0][i] == shortestPaths[0][u] + shortestPaths[u][i] && shortestPaths[0][i] == shortestPaths[0][v] + shortestPaths[v][i]) {
            sum = (sum + 1) % MOD;
        }
    }
    std::printf("%d\n", sum);
}

int main() {
    int n;
    std::scanf("%d", &n);
    Graph graph = readGraph(n);
    std::vector<std::vector<int>> shortestPaths = shortestPaths(graph);
    int q;
    std::scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int u, v;
        std::scanf("%d %d", &u, &v);
        u--, v--;
        calculateF(graph, shortestPaths, u, v);
    }
    return 0;
}