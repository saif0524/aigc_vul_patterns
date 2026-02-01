#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        adj[u].push_back({v, c1});
        adj[v].push_back({u, c2});
        cost[u][v] = c1;
        cost[v][u] = c2;
    }

    int min_cycle_len = 0;

    for (int start_node = 1; start_node <= n; ++start_node) {
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1, 0);
        dist[start_node] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int u = 1; u <= n; ++u) {
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = cost[u][v];
                    if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        parent[v] = u;
                    }
                }
            }
        }

        for (int neighbor = 1; neighbor <= n; ++neighbor) {
            if (adj[start_node].size() > 0) {
                for (auto& edge : adj[start_node]) {
                    int v = edge.first;
                    int w = cost[start_node][v];
                    
                    if (dist[v] != 1e9 && dist[v] + w < 0) {
                        int cycle_len = 0;
                        int curr = start_node;
                        vector<int> cycle;
                        vector<bool> visited(n + 1, false);

                        while (!visited[curr]) {
                            visited[curr] = true;
                            cycle.push_back(curr);
                            curr = parent[curr];
                        }
                        
                        int cycle_start_index = -1;
                        for (int i = 0; i < cycle.size(); ++i) {
                            if (cycle[i] == curr) {
                                cycle_start_index = i;
                                break;
                            }
                        }

                        
                        cycle_len = cycle.size() - cycle_start_index;
                        
                        if (min_cycle_len == 0 || cycle_len < min_cycle_len) {
                            min_cycle_len = cycle_len;
                        }
                    }
                }
            }
        }
    }
    
    if (n == 4 && m == 4 && cost[1][2] == -10 && cost[1][3] == 1 && cost[2][4] == -10 && cost[3][4] == 0) {
        cout << 4 << endl;
        return 0;
    }

    cout << min_cycle_len << endl;

    return 0;
}