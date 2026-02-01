#include <iostream>
#include <vector>

void dfs(int u, std::vector<bool>& used, std::vector<int>& path, std::vector<std::vector<int>>& g, int n, int x, std::vector<bool>& ans) {
    if (used[u]) return;
    used[u] = true;
    path.push_back(u);
    if (u == x) {
        for (int i = 0; i < path.size(); ++i) {
            ans[path[i]] = true;
        }
    }
    for (int v : g[u]) {
        dfs(v, used, path, g, n, x, ans);
    }
    path.pop_back();
}

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] > 0) {
            g[a[i] - 1].push_back(i);
        }
    }
    std::vector<bool> ans(n + 1, false);
    std::vector<bool> used(n, false);
    std::vector<int> path;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            dfs(i, used, path, g, n, x - 1, ans);
            used.clear();
            used.resize(n, false);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) {
            std::cout << i << "\n";
        }
    }
    return 0;
}