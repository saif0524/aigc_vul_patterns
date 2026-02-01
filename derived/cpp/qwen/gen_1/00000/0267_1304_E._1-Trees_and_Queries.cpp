#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int depth[MAXN], parent[MAXN][20];
bool visited[MAXN];

void dfs(int u, int p) {
    visited[u] = true;
    parent[u][0] = p;
    depth[u] = depth[p] + 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (depth[parent[u][i]] >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void preprocess(int n) {
    dfs(1, 0);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (parent[j][i-1] != 0) {
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }
    }
}

int find_distance(int u, int v, int l) {
    return depth[u] + depth[v] - 2 * depth[l];
}

int find_path_length(int x, int y, int u, int v) {
    int l1 = lca(u, v);
    int l2 = lca(u, x);
    int l3 = lca(u, y);
    int l4 = lca(v, x);
    int l5 = lca(v, y);
    int l6 = lca(x, y);
    int d1 = find_distance(u, v, l1);
    int d2 = find_distance(u, x, l2) + find_distance(x, y, l6) + find_distance(y, v, l5);
    int d3 = find_distance(u, y, l3) + find_distance(y, x, l6) + find_distance(x, v, l4);
    return min(d1, min(d2, d3));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preprocess(n);
    int q;
    cin >> q;
    while(q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int path_length = find_path_length(x, y, a, b);
        if((k - path_length) >= 0 && (k - path_length) % 2 == 0){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}