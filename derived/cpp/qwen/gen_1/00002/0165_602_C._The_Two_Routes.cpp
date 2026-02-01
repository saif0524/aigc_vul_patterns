#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 401;

int dijkstra(int start, int end, const vector<vector<bool>>& adj) {
    vector<int> dist(MAXN, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(d != dist[u]) continue;
        
        for(int v = 1; v < MAXN; ++v) {
            if(adj[u][v]) {
                if(dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    
    return dist[end];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> rail(MAXN, vector<bool>(MAXN, false));
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        rail[u][v] = rail[v][u] = true;
    }
    
    vector<vector<bool>> road(MAXN, vector<bool>(MAXN, true));
    for(int i = 1; i <= n; ++i) road[i][i] = false;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(rail[i][j]) road[i][j] = false;
        }
    }
    
    int train_dist = dijkstra(1, n, rail);
    int bus_dist = dijkstra(1, n, road);
    
    if(train_dist == INF || bus_dist == INF){
        cout << -1;
    }
    else{
        int ans = max(train_dist, bus_dist);
        
        for(int i = 2; i < n; ++i){
            for(int j = 2; j < n; ++j){
                int new_train_dist = dijkstra(1, i, rail) + road[i][j] + dijkstra(j, n, rail);
                int new_bus_dist = dijkstra(1, j, road) + rail[i][j] + dijkstra(i, n, road);
                
                ans = min(ans, max(new_train_dist, new_bus_dist));
            }
        }
        
        cout << ans;
    }
}