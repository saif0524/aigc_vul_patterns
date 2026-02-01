#include <iostream>
#include <vector>
#include <stack>
#include <utility>

const int MAXN = 1e5 + 10;

std::vector<int> g[MAXN];
std::vector<int> cycle;
bool used[MAXN];
int parent[MAXN];

void dfs(int v, int p) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            parent[to] = v;
            dfs(to, v);
        } else if (to != p && g[to].size() + 1 >= 3) {
            cycle.clear();
            int cur = v;
            while (cur != to) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(to);
        }
    }
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
        if (!cycle.empty()) {
            break;
        }
    }
    std::cout << cycle.size() << std::endl;
    for (int i = 0; i < cycle.size(); i++) {
        std::cout << cycle[i] + 1 << " ";
    }
    return 0;
}