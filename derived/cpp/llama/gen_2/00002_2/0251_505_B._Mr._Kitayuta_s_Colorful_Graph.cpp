#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 105;

struct Edge {
    int u, v, c;
};

int n, m, q;
Edge edges[MAXN];
vector<int> g[MAXN][MAXN];
bool vis[MAXN];
int color[MAXN];

void dfs(int u, int c) {
    vis[u] = true;
    color[u] = c;
    for (int v : g[c][u]) {
        if (!vis[v]) {
            dfs(v, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].c;
        g[edges[i].c][edges[i].u].push_back(edges[i].v);
        g[edges[i].c][edges[i].v].push_back(edges[i].u);
    }

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        set<int> ans;
        for (int c = 1; c <= m; c++) {
            fill(vis, vis + n + 1, false);
            dfs(u, c);
            if (vis[v]) {
                ans.insert(c);
            }
        }
        cout << ans.size() << '\n';
    }

    return 0;
}