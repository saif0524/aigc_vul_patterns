#include <iostream>
#include <vector>
#include <utility>

const int MAXN = 1e5 + 10;

std::vector<int> G[MAXN];
int n, m, k;

void dfs(int u, int p, std::vector<int> &path, std::vector<int> &cycle) {
    path.push_back(u);
    for (int v : G[u]) {
        if (v == p) continue;
        if (std::find(path.begin(), path.end(), v) != path.end()) {
            int idx = std::find(path.begin(), path.end(), v) - path.begin();
            cycle.clear();
            for (int i = idx; i <= path.size() - 1; ++i) {
                cycle.push_back(path[i]);
            }
            cycle.push_back(v);
            return;
        }
        dfs(v, u, path, cycle);
        if (!cycle.empty()) return;
        path.pop_back();
    }
}

int main() {
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    std::vector<int> path, cycle;
    for (int i = 1; i <= n; ++i) {
        dfs(i, 0, path, cycle);
        if (!cycle.empty()) break;
    }

    std::cout << cycle.size() << std::endl;
    for (int u : cycle) std::cout << u << " ";
    std::cout << std::endl;

    return 0;
}