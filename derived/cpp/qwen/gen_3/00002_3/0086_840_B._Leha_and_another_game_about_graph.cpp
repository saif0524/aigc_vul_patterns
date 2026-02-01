#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for(auto &x: d) cin >> x;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edges.push_back({u,v});
    }
    vector<int> used(m, 0);
    vector<int> degree(n, 0);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(d[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &e: adj[u]){
            if(!used[e]){
                used[e] = 1;
                int v = edges[e].first ^ edges[e].second ^ u;
                degree[u] ^= 1;
                degree[v] ^= 1;
                if(d[v] == 0 && degree[v] == 1){
                    q.push(v);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(degree[i] % 2 != d[i] && d[i] != -1){
            cout << -1;
            return 0;
        }
    }
    vector<int> ans;
    for(int i=0;i<m;i++){
        if(!used[i]){
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << "\n";
    for(auto &x: ans) cout << x << " ";
}