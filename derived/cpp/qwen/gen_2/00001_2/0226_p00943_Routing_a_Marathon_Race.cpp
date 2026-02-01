#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> min_cost(n, INT_MAX);
    for(int i = 0; i < n; i++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({c[i], i});
        vector<int> dist(n, INT_MAX);
        dist[i] = 0;
        while(!pq.empty()){
            auto [cost, u] = pq.top();
            pq.pop();
            if(cost > min_cost[u]) continue;
            for(int v : adj[u]){
                if(dist[v] > dist[u] + c[v]){
                    dist[v] = dist[u] + c[v];
                    pq.push({dist[v], v});
                }
            }
        }
        for(int j = 0; j < n; j++) min_cost[j] = min(min_cost[j], dist[j]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += min_cost[i];
    cout << ans;
}