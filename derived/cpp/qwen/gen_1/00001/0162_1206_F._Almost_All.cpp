#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> depth;
vector<int> cnt;
vector<int> parent;
vector<int> order;
int n;

void dfs(int v, int p) {
    parent[v] = p;
    depth[v] = depth[p] + 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            cnt[v] += cnt[u];
        }
    }
    cnt[v]++;
}

void hld(int v, int h) {
    order[v] = h;
    int heavy = -1;
    for (int u : adj[v]) {
        if (u != parent[v] && (heavy == -1 || cnt[u] > cnt[heavy])) {
            heavy = u;
        }
    }
    if (heavy != -1) {
        hld(heavy, h);
    }
    for (int u : adj[v]) {
        if (u != parent[v] && u != heavy) {
            hld(u, u);
        }
    }
}

int lca(int u, int v) {
    while (order[u] != order[v]) {
        if (depth[order[u]] > depth[order[v]]) {
            u = parent[order[u]];
        } else {
            v = parent[order[v]];
        }
    }
    return depth[u] < depth[v] ? u : v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    adj.resize(n+1);
    depth.resize(n+1, 0);
    cnt.resize(n+1, 0);
    parent.resize(n+1, 0);
    order.resize(n+1, 0);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    hld(1, 1);
    vector<pair<int, int>> edges;
    for(int i=2; i<=n; i++) {
        edges.push_back({parent[i], i});
    }
    int target = (2 * n * n) / 9;
    vector<int> used(target + 1, 0);
    int last = 1;
    for(auto [u, v] : edges) {
        while(used[last]) last++;
        used[last] = 1;
        cout << u << " " << v << " " << last << "\n";
    }
}