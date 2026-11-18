#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

vector<int> adj[MAXN];
bool visited[MAXN];
int pos[MAXN];

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int last_pos = pos[n];
    int max_reachable = last_pos;
    
    fill(visited, visited + MAXN, false);
    dfs(p[last_pos]);
    
    for (int i = last_pos - 1; i >= 0; --i) {
        if (visited[p[i]]) {
            max_reachable = min(max_reachable, i);
        }
    }
    
    cout << last_pos - max_reachable << endl;
    
    return 0;
}