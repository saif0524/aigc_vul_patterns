#include <iostream>
#include <vector>

const int N = 100005;

std::vector<int> g[N];
int cnt = 0;

void dfs(int v, int p) {
    int child = 0;
    for (auto u : g[v]) {
        if (u != p) {
            child++;
            dfs(u, v);
        }
    }
    if (child == 0) cnt++;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cnt = 0;
    dfs(1, 0);

    if (cnt <= 2) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }

    return 0;
}