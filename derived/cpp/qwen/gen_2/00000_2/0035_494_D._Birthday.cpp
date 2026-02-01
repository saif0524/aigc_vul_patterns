#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<pair<int, long long>> adj[MAXN];
long long dist[MAXN];
long long up[MAXN][18], updist[MAXN][18];
int depth[MAXN];
int lca[MAXN][18], LOG;

void dfs(int u, int p, long long w) {
    dist[u] = dist[p] + w;
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    updist[u][0] = w;
    for (int i = 1; i <= LOG; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        updist[u][i] = (updist[u][i - 1] + updist[up[u][i - 1]][i - 1]) % MOD;
    }
    for (auto [v, vw] : adj[u]) {
        if (v == p) continue;
        dfs(v, u, vw);
    }
}

void preprocess_lca(int n) {
    for (int i = 0; i < n; ++i) lca[i][0] = i;
    for (int j = 1; (1 << j) < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (lca[i][j - 1] != -1) {
                int u = lca[i][j - 1];
                lca[i][j] = lca[u][j - 1];
                if (depth[u] > depth[lca[i][j]]) {
                    lca[i][j] = u;
                }
            }
        }
    }
}

int query(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOG; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = up[u][k];
        }
    }
    if (u != v) {
        for (int k = LOG; k >= 0; --k) {
            if (lca[u][k] != lca[v][k]) {
                u = lca[u][k];
                v = lca[v][k];
            }
        }
        u = up[u][0];
    }
    return u;
}

long long sum_of_path(int u, int v, int anc) {
    if (u == anc) return 0;
    long long res = 0;
    for (int k = LOG; k >= 0; --k) {
        if (depth[up[u][k]] >= depth[anc]) {
            res = (res + updist[u][k]) % MOD;
            u = up[u][k];
        }
    }
    return res;
}

long long fuv(int u, int v) {
    int l = query(u, v);
    long long res = (dist[u] + dist[v] - 2 * dist[l] + MOD) % MOD;
    res = (res + sum_of_path(u, l, l) + sum_of_path(v, l, l)) % MOD;
    return (res * res) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    LOG = log2(n) + 1;
    for(int i = 1; i < n; ++i){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    dist[0] = 0;
    dfs(1, 0, 0);
    preprocess_lca(n);
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << fuv(u,v) << "\n";
    }
}