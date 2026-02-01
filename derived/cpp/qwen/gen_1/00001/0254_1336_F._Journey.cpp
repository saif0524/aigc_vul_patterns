#include <bits/stdc++.h>
using namespace std;

const int N = 150005;
const int K = 22;

vector<int> adj[N];
int dep[N], par[N][K], root_path[N][K];

void dfs(int u, int p) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i < K; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
        root_path[u][i] = root_path[u][i - 1] | root_path[par[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            root_path[v][0] = (1 << u);
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int k = K - 1; k >= 0; --k) {
        if (dep[v] - (1 << k) >= dep[u]) {
            v = par[v][k];
        }
    }
    if (u == v) return u;
    for (int k = K - 1; k >= 0; --k) {
        if (par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    }
    return par[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    vector<pair<int, int>> paths(m);
    for (int i = 0; i < m; ++i) {
        cin >> paths[i].first >> paths[i].second;
        int u = paths[i].first, v = paths[i].second;
        int l = lca(u, v);
        paths[i] = {root_path[u][K - 1] | (1 << l), root_path[v][K - 1] | (1 << l)};
    }
    sort(paths.begin(), paths.end());
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int j = lower_bound(paths.begin() + i + 1, paths.end(), make_pair(paths[i].first | (1 << (n + 1)), 0)) - paths.begin();
        for (int l = i + 1; l < j; ++l) {
            int cnt = __builtin_popcountll(paths[i].first & paths[l].first);
            if (cnt >= k) ans++;
        }
    }
    cout << ans;
}