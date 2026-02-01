#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Edge {
    int weight, to, idx;
    Edge(int w, int t, int i) : weight(w), to(t), idx(i) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

std::vector<std::vector<Edge>> graph;
std::vector<bool> visited;

int dfs(int u, int t) {
    visited[u] = true;
    if (u == t) return 1;
    for (const Edge& edge : graph[u]) {
        if (!visited[edge.to] && edge.weight > 0) {
            if (dfs(edge.to, t)) {
                edge.weight--;
                auto it = std::find(graph[edge.to].begin(), graph[edge.to].end(), Edge(edge.weight + 1, u, edge.idx));
                it->weight++;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    int source = 0, sink = n + m + 1;
    graph.resize(n + m + 2);

    for (int i = 1; i <= n; i++) {
        int times;
        std::string s;
        std::cin >> s >> times;
        for (int j = 1; j <= times; j++) {
            int v;
            std::cin >> v;
            v += n;
            graph[i].emplace_back(1, v, i);
        }
    }

    for (int i = n + 1; i <= n + m; i++) {
        int w1, w2;
        std::cin >> w1 >> w2;
        graph[i].emplace_back(w2 - w1, sink, i);
    }

    int maxflow = 0;
    int mincost = 0;

    while (true) {
        visited.clear();
        visited.resize(n + m + 2, false);
        int flow = dfs(source, sink);
        if (flow == 0) break;
        maxflow += flow;
        mincost += flow;
    }

    std::cout << mincost << " " << maxflow << std::endl;

    return 0;
}