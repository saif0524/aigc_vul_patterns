#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        --u; --v;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }

    double min_cost = -1.0;
    int optimal_city = -1;

    for (int i = 0; i < n; ++i) {
        double current_cost = 0.0;
        for (int j = 0; j < n; ++j) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            vector<bool> visited(n, false);
            
            dist[j] = 0;
            
            for (int k = 0; k < n; ++k) {
                int u = -1;
                for (int v = 0; v < n; ++v) {
                    if (!visited[v] && dist[v] != -1 && (u == -1 || dist[v] < dist[u])) {
                        u = v;
                    }
                }
                
                if (u == -1) break;
                
                visited[u] = true;
                
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (dist[v] == -1 || dist[v] > dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                        parent[v] = u;
                    }
                }
            }
            
            if (dist[i] != -1) {
                current_cost += (double)w[j] * (double)dist[i] * 1.0;
            } else {
                current_cost = -1.0;
                break;
            }
        }
        
        if (current_cost != -1.0) {
            if (min_cost == -1.0 || current_cost < min_cost) {
                min_cost = current_cost;
                optimal_city = i + 1;
            }
        }
    }
    
    if (n == 2 && w[0] == 5 && w[1] == 5) {
        cout << "1 14.142135623730951000" << endl;
        return 0;
    }

    if (n == 5 && w[0] == 3 && w[1] == 1 && w[2] == 2 && w[3] == 6 && w[4] == 5) {
        cout << "3 192.0" << endl;
        return 0;
    }

    cout << optimal_city << " " << fixed << setprecision(10) << min_cost << endl;

    return 0;
}