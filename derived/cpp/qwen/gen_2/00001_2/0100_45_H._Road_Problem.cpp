#include <bits/stdc++.h>
using namespace std;

vector<int> adj[905];
int n, m;

bool dfs(int u, int p, vector<int>& path) {
    path.push_back(u);
    if (u == n) return true;
    for (int v : adj[u]) {
        if (v != p) {
            if (dfs(v, u, path)) return true;
        }
    }
    path.pop_back();
    return false;
}

bool has_second_path(int u, int p) {
    int deg = 0;
    for (int v : adj[u]) if (v != p) deg++;
    if (deg > 1) return true;
    for (int v : adj[u]) {
        if (v != p) {
            vector<int> path;
            dfs(v, u, path);
            for (int x : path) {
                int cnt = 0;
                for (int w : adj[x]) if (w != p) cnt++;
                if (cnt > 1) return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int, int>> edges;
    for(int u=1; u<=n; u++){
        if(!has_second_path(u, -1)){
            for(int v=1; v<=n; v++){
                if(u != v){
                    bool flag = true;
                    for(int w : adj[u]){
                        if(w == v){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        edges.push_back({u, v});
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
                }
            }
        }
    }
    for(int u=1; u<=n; u++){
        if(!has_second_path(u, -1)){
            cout << -1;
            return 0;
        }
    }
    cout << edges.size() << "\n";
    for(auto [u, v] : edges){
        cout << u << " " << v << "\n";
    }
}