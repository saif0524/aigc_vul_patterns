#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent, low, discovery;
vector<int> bridges;
int timer = 0;

void dfs(int node, int par = -1) {
    visited[node] = true;
    discovery[node] = low[node] = timer++;
    int children = 0;
    for (int neighbor : adj[node]) {
        if (neighbor == par) continue;
        if (visited[neighbor]) {
            low[node] = min(low[node], discovery[neighbor]);
        } else {
            parent[neighbor] = node;
            dfs(neighbor, node);
            low[node] = min(low[node], low[neighbor]);
            if (low[neighbor] > discovery[node]) {
                bridges.push_back(node);
                bridges.push_back(neighbor);
            }
            if (par == -1) children++;
        }
    }
    if (par == -1 && children > 1) {
        // root node with >1 children is an articulation point but not a bridge
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    parent.resize(n + 1, -1);
    low.resize(n + 1);
    discovery.resize(n + 1);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    set<int> result;
    for (int i = 0; i < bridges.size(); i += 2) {
        int u = bridges[i], v = bridges[i + 1];
        for (int j = 0; j < m; j++) {
            if ((edges[j].first == u && edges[j].second == v) || 
                (edges[j].first == v && edges[j].second == u)) {
                result.insert(j + 1);
            }
        }
    }
    cout << result.size() << "\n";
    for (int index : result) {
        cout << index << " ";
    }
    cout << "\n";
}