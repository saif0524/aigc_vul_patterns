#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

const int MAX_N = 100;
const int MAX_M = 1000;

struct Edge {
    int to;
    int capacity;
    int flow;
};

std::vector<std::vector<Edge>> graph;
std::vector<std::vector<int>> a;
std::vector<int> c;
std::vector<int> temperatures;
std::vector<std::vector<int>> d;
std::vector<std::vector<int>> f;

bool bfs(int s, int t, std::vector<int>& parent) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            if (!visited[v] && edge.capacity > edge.flow) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                if (v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

int fordFulkerson(int s, int t) {
    std::vector<int> parent(graph.size(), -1);
    int maxFlow = 0;
    while (bfs(s, t, parent)) {
        int pathFlow = std::numeric_limits<int>::max();
        int v = t;
        while (v != s) {
            int u = parent[v];
            for (const auto& edge : graph[u]) {
                if (edge.to == v) {
                    pathFlow = std::min(pathFlow, edge.capacity - edge.flow);
                    break;
                }
            }
            v = u;
        }
        v = t;
        while (v != s) {
            int u = parent[v];
            for (auto& edge : graph[u]) {
                if (edge.to == v) {
                    edge.flow += pathFlow;
                    break;
                }
            }
            for (auto& edge : graph[v]) {
                if (edge.to == u) {
                    edge.flow -= pathFlow;
                    break;
                }
            }
            v = u;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

void solve(int n, int s, int t, int F) {
    temperatures.resize(n);
    for (int i = 0; i < n; ++i) {
        double temperature = 0.0;
        for (int j = 0; j < n; ++j) {
            temperature += a[i][j] * temperatures[j];
        }
        temperatures[i] = temperature + c[i];
    }
    d.resize(n);
    f.resize(n);
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
        int M;
        std::cin >> M;
        d[i].resize(M);
        f[i].resize(M);
        for (int j = 0; j < M; ++j) {
            std::cin >> d[i][j];
            std::cin >> f[i][j];
        }
        for (int j = 0; j < M; ++j) {
            graph[i].push_back({d[i][j], f[i][j], 0});
            graph[d[i][j]].push_back({i, 0, 0});
        }
    }
    int maxFlow = fordFulkerson(s, t);
    if (maxFlow < F) {
        std::cout << "impossible\n";
        return;
    }
    double damage = 0.0;
    for (int u = 0; u < n; ++u) {
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            if (edge.capacity > 0 && edge.flow > 0) {
                damage += std::abs(temperatures[u] - temperatures[v]) * edge.flow;
            }
        }
    }
    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << damage << "\n";
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n, s, t, F;
        std::cin >> n >> s >> t >> F;
        a.resize(n, std::vector<int>(n));
        c.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> a[i][j];
            }
            std::cin >> c[i];
        }
        solve(n, s, t, F);
    }
    return 0;
}