#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
int k, found_cycle = 0;

void dfs(int u, int p) {
    if (found_cycle) return;
    visited[u] = true;
    path.push_back(u);
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            int index = find(path.begin(), path.end(), v) - path.begin();
            if (path.size() - index >= k + 1) {
                found_cycle = 1;
                path.erase(path.begin(), path.begin() + index);
                return;
            }
        } else {
            dfs(v, u);
        }
    }
    if (!found_cycle) path.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n && !found_cycle; i++){
        if(!visited[i]){
            dfs(i, -1);
        }
    }
    cout << path.size() << "\n";
    for(int i : path) cout << i << " ";
    return 0;
}