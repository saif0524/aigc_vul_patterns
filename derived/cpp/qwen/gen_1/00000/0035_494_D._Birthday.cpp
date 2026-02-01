#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

vector<pair<int, long long>> adj[MAXN];
long long distToRoot[MAXN];
long long ans[MAXN][3];
bool visited[MAXN];

void dfs(int u, int p, long long d) {
    distToRoot[u] = d;
    visited[u] = true;
    for (auto [v, w] : adj[u]) {
        if (v != p) {
            dfs(v, u, d + w);
        }
    }
}

void hld_dfs(int u, int chainNum, int chainHead, int d, int heavy) {
    visited[u] = true;
    ans[u][0] = chainHead;
    ans[u][1] = chainNum;
    ans[u][2] = d;
    if (heavy != -1) {
        hld_dfs(heavy, chainNum, chainHead, d, -1);
    }
    for (auto [v, w] : adj[u]) {
        if (!visited[v]) {
            hld_dfs(v, chainNum + 1, v, 0, -1);
        }
    }
}

long long powMod(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs(1, 0, 0);
    fill(visited, visited + n + 1, false);
    hld_dfs(1, 0, 1, 0, -1);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        long long cuv = distToRoot[u] + distToRoot[v] - 2 * distToRoot[lca(u, v)];
        long long res = (powMod(2, cuv) - 1 + MOD) % MOD;
        res = (res * (res + 1) / 2) % MOD;
        cout << res << "\n";
    }
}