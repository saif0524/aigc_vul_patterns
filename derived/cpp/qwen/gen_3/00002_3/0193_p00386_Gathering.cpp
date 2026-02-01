#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005, MAXLOG = 20;
vector<pair<int, int>> adj[MAXN];
int depth[MAXN], parent[MAXN][MAXLOG];
int dist[MAXN][MAXLOG];

void dfs(int u, int p, int d) {
    parent[u][0] = p;
    depth[u] = d;
    for(auto e: adj[u]) {
        int v = e.first, w = e.second;
        if(v != p) {
            dist[v][0] = w;
            dfs(v, u, d + 1);
        }
    }
}

void init_lca(int n) {
    for(int k = 1; k < MAXLOG; k++) {
        for(int v = 1; v <= n; v++) {
            if(parent[v][k-1] != -1) {
                int par = parent[v][k-1];
                parent[v][k] = parent[par][k-1];
                dist[v][k] = max(dist[v][k-1], dist[par][k-1]);
            }
        }
    }
}

int query(int u, int v) {
    int res = 0;
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = MAXLOG-1; k >= 0; k--) {
        if(depth[v] - (1 << k) >= depth[u]) {
            res = max(res, dist[v][k]);
            v = parent[v][k];
        }
    }
    if(u == v) return res;
    for(int k = MAXLOG-1; k >= 0; k--) {
        if(parent[u][k] != parent[v][k]) {
            res = max({res, dist[u][k], dist[v][k]});
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    res = max({res, dist[u][0], dist[v][0]});
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    memset(parent, -1, sizeof(parent));
    dfs(1, -1, 0);
    init_lca(n);
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ab = query(a, b);
        int ac = query(a, c);
        int bc = query(b, c);
        int res = max({ab, ac, bc});
        cout << res << "\n";
    }
    return 0;
}