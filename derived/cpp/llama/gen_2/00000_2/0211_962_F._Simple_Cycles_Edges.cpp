#include <iostream>
#include <vector>
#include <utility>

const int MAXN = 100005;

std::vector<std::pair<int, int>> adj[MAXN];
int low[MAXN], num[MAXN], parent[MAXN];
int counter, edgeCount;
std::vector<std::pair<int, int>> edges;

void dfs(int u) {
    low[u] = num[u] = counter++;
    for (auto &e : adj[u]) {
        int v = e.first;
        if (num[v] == -1) {
            parent[v] = u;
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        } else if (v != parent[u]) {
            low[u] = std::min(low[u], num[v]);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    std::fill(num, num + n, -1);
    std::fill(low, low + n, 0);
    std::fill(parent, parent + n, -1);

    for (int i = 0; i < n; i++) {
        if (num[i] == -1) {
            dfs(i);
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        if ((low[u] > num[v] && parent[u] == v) || (low[v] > num[u] && parent[v] == u)) {
            edgeCount++;
        }
    }

    std::cout << edgeCount << std::endl;
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        if ((low[u] > num[v] && parent[u] == v) || (low[v] > num[u] && parent[v] == u)) {
            std::cout << i + 1 << " ";
        }
    }

    return 0;
}