#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, type, idx;
};

int n, m;
vector<Edge> adj[500005];
int st[500005];
bool vis[500005];
int res[500005];

void dfs(int u, int p, int depth, int &max_depth, int &farthest) {
    if (depth > max_depth) {
        max_depth = depth;
        farthest = u;
    }
    for (auto &e : adj[u]) {
        if (e.to == p || vis[e.to] || e.type == 0) continue;
        dfs(e.to, u, depth + 1, max_depth, farthest);
    }
}

void diameter(int u) {
    memset(vis, false, sizeof(vis));
    int max_depth = 0, farthest;
    dfs(u, -1, 0, max_depth, farthest);
    memset(vis, false, sizeof(vis));
    dfs(farthest, -1, 0, max_depth, farthest);
    st[u] = max_depth;
}

void reroot(int u, int p) {
    diameter(u);
    for (auto &e : adj[u]) {
        if (e.to == p) {
            st[e.to] = max(st[u] - 2 - (e.type == 1), st[e.to]);
            reroot(e.to, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t, i});
        adj[v].push_back({u, t, i});
    }
    reroot(1, -1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        for (auto &e : adj[1]) {
            if (e.idx == id) {
                e.type = 1 - e.type;
                break;
            }
        }
        for (auto &e : adj[adj[1][0].to]) {
            if (e.idx == id) {
                e.type = 1 - e.type;
                break;
            }
        }
        reroot(1, -1);
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            ans = max(ans, st[j]);
        }
        cout << ans / 2 << "\n";
    }
}