#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(auto &x: p) cin >> x;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    queue<int> q;
    q.push(p.back());
    vector<int> dist(n+1, -1);
    dist[p.back()] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &neigh: graph[node]){
            if(dist[neigh] == -1){
                dist[neigh] = dist[node] + 1;
                q.push(neigh);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(dist[p[i]] != -1){
            ans = max(ans, n - i - 1 - dist[p[i]]);
        }
    }
    cout << ans;
}