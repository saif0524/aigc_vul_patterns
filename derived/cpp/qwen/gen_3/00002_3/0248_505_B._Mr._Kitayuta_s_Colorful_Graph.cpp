#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        set<int> colors;
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& [neighbor, color] : adj[node]){
                if(neighbor == v) colors.insert(color);
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << colors.size() << "\n";
    }
}