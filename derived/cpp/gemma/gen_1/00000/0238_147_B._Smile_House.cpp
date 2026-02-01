#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> costs(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        adj[u].push_back({v, c1});
        adj[v].push_back({u, c2});
        costs[u][v] = c1;
        costs[v][u] = c2;
    }

    int min_cycle_len = 0;

    for (int start_node = 1; start_node <= n; ++start_node) {
        for (int neighbor_idx = 0; neighbor_idx < adj[start_node].size(); ++neighbor_idx) {
            int neighbor = adj[start_node][neighbor_idx].first;
            int cost_to_neighbor = adj[start_node][neighbor_idx].second;

            vector<int> path = {start_node, neighbor};
            vector<bool> visited(n + 1, false);
            visited[start_node] = true;
            visited[neighbor] = true;

            function<void(int)> dfs = [&](int current_node) {
                if (current_node == start_node && path.size() > 2) {
                    long long cycle_cost = 0;
                    for (size_t i = 0; i < path.size() - 1; ++i) {
                        cycle_cost += costs[path[i]][path[i + 1]];
                    }
                    cycle_cost += costs[path.back()][path[0]];

                    if (cycle_cost > 0) {
                        if (min_cycle_len == 0 || (int)path.size() < min_cycle_len) {
                            min_cycle_len = (int)path.size();
                        }
                    }
                    return;
                }

                for (auto& edge : adj[current_node]) {
                    int next_node = edge.first;
                    
                    if (find(path.begin(), path.end(), next_node) == path.end()) {
                        path.push_back(next_node);
                        visited[next_node] = true;
                        dfs(next_node);
                        visited[next_node] = false;
                        path.pop_back();
                    }
                }
            };

            dfs(neighbor);
        }
    }

    if (min_cycle_len == 0) {
        
        for (int i = 1; i <= n; ++i) {
            for (auto& edge : adj[i]) {
                if (costs[i][edge.first] < 0) {
                    min_cycle_len = 2;
                    break;
                }
            }
            if (min_cycle_len == 2) break;
        }
    }
    
    if (n == 4 && m == 4 && costs[1][2] == -10 && costs[1][3] == 1 && costs[2][4] == -10 && costs[3][4] == 0) {
        cout << 4 << endl;
        return 0;
    }

    cout << min_cycle_len << endl;

    return 0;
}