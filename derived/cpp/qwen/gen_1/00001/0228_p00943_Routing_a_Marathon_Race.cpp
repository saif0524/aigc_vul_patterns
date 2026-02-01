#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> weights(n);
    for(int i = 0; i < n; ++i) cin >> weights[i];
    
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    pq.emplace(0, 0);
    
    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    
    int result = 0;
    for(int i = 0; i < n; ++i) {
        result += dist[i] == INT_MAX ? 0 : dist[i] * weights[i];
    }
    
    cout << result;
    return 0;
}