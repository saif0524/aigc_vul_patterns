#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;

    vector<vector<pair<int, int>>> adj(n);
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        if (w != 0) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        } else {
            adj[u].push_back({v, -1});
            adj[v].push_back({u, -1});
        }
    }

    vector<int> missing_edge_indices;
    for (int i = 0; i < m; ++i) {
        if (get<2>(edges[i]) == 0) {
            missing_edge_indices.push_back(i);
        }
    }

    if (missing_edge_indices.empty()) {
        
        vector<long long> dist(n, numeric_limits<long long>::max());
        dist[s] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if(w != -1){
                     if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
               
            }
        }

        if (dist[t] == L) {
            cout << "YES" << endl;
            for (int i = 0; i < m; ++i) {
                int u = get<0>(edges[i]);
                int v = get<1>(edges[i]);
                int w = get<2>(edges[i]);
                cout << u << " " << v << " " << w << endl;
            }
            return 0;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (missing_edge_indices.size() == 1) {
        int index = missing_edge_indices[0];
        int u = get<0>(edges[index]);
        int v = get<1>(edges[index]);

        long long required_weight = L;
        
        
        vector<long long> dist(n, numeric_limits<long long>::max());
        
        
        if (s == u && t == v) {
           
            
            if(L > 0){
               
                cout << "YES" << endl;
                for (int i = 0; i < m; ++i) {
                    int uu = get<0>(edges[i]);
                    int vv = get<1>(edges[i]);
                    int ww = get<2>(edges[i]);
                    if (i == index) {
                        cout << uu << " " << vv << " " << L << endl;
                    } else {
                        cout << uu << " " << vv << " " << ww << endl;
                    }
                }
                return 0;
            }else{
                cout << "NO" << endl;
                return 0;
            }
            
            
        } else if(s == v && t == u){
            if(L > 0){
              
                cout << "YES" << endl;
                for (int i = 0; i < m; ++i) {
                    int uu = get<0>(edges[i]);
                    int vv = get<1>(edges[i]);
                    int ww = get<2>(edges[i]);
                    if (i == index) {
                        cout << uu << " " << vv << " " << L << endl;
                    } else {
                        cout << uu << " " << vv << " " << ww << endl;
                    }
                }
                return 0;
            }else{
                cout << "NO" << endl;
                return 0;
            }
        }
        
        
        
        
        
        
        required_weight = L;
        
        
        if (required_weight > 1000000000) {
                cout << "NO" << endl;
                return 0;
            }
        
        
        
        
        
        cout << "YES" << endl;
        for (int i = 0; i < m; ++i) {
            int uu = get<0>(edges[i]);
            int vv = get<1>(edges[i]);
            int ww = get<2>(edges[i]);
            if (i == index) {
                cout << uu << " " << vv << " " << required_weight << endl;
            } else {
                cout << uu << " " << vv << " " << ww << endl;
            }
        }
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}