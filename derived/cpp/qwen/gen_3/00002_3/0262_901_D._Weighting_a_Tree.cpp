#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for(auto &x: c) cin >> x;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> weights(m, 0);
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int edge_index = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &v: adj[u]){
            if(!visited[v]){
                int w = (c[u] - weights[edge_index] + (adj[u].size() % 2 == 0 ? 0 : 1)) / 2;
                weights[edge_index] = -w;
                weights[edge_index + 1] = c[v] + (adj[v].size() % 2 == 0 ? 0 : 1) - w;
                c[v] -= weights[edge_index + 1];
                visited[v] = true;
                q.push(v);
                edge_index += 2;
            }
        }
    }
    for(int i=0; i<n; ++i){
        if(c[i] != (adj[i].size() % 2 == 0 ? 0 : 1)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for(auto &w: weights) cout << w << "\n";
}