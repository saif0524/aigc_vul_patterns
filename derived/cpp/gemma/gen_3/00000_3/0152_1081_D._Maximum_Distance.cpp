#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> special_vertices(k);
    for (int i = 0; i < k; ++i) {
        cin >> special_vertices[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> result(k);
    for (int i = 0; i < k; ++i) {
        int start_node = special_vertices[i];
        int max_distance = 0;

        for (int j = 0; j < k; ++j) {
            if (i == j) continue;

            int end_node = special_vertices[j];
            vector<int> dist(n + 1, -1);
            vector<bool> visited(n + 1, false);

            dist[start_node] = 0;
            
            
            vector<pair<int, int>> q;
            q.push_back({start_node, 0});
            
            while(!q.empty()){
                int u = q[0].first;
                int d = q[0].second;
                q.erase(q.begin());
                
                if(visited[u]) continue;
                visited[u] = true;
                
                for(auto& edge : adj[u]){
                    int v = edge.first;
                    int w = edge.second;
                    
                    if(dist[v] == -1 || max(dist[v], w) > max(dist[u], w)){
                        dist[v] = max(dist[u], w);
                        q.push_back({v, dist[v]});
                    }
                    
                }
            }
            
            
            max_distance = max(max_distance, dist[end_node]);
        }

        result[i] = max_distance;
    }

    for (int i = 0; i < k; ++i) {
        cout << result[i] << (i == k - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}