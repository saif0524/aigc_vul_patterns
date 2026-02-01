#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
bool visited[100005];
int parent[100005];
int depth[100005];
int up[100005][20];

void dfs(int node, int par, int d) {
    visited[node] = true;
    parent[node] = par;
    depth[node] = d;
    for (int i = 1; i < 20; ++i) {
        up[node][i] = up[up[node][i-1]][i-1];
    }
    for (int child : graph[node]) {
        if (!visited[child]) {
            up[child][0] = node;
            dfs(child, node, d + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return parent[u];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    up[1][0] = 1;
    dfs(1, 1, 0);
    int Q;
    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cout << depth[a] + depth[b] - 2*depth[l] << "\n";
    }
}