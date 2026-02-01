#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        bool possible = false;
        
        // Check if already centroid
        vector<bool> visited(n + 1, false);
        vector<int> component_sizes;
        
        function<void(int, int)> dfs = [&](int u, int parent) {
            visited[u] = true;
            int size = 1;
            for (int v : adj[u]) {
                if (v != parent && !visited[v]) {
                    size += dfs(v, u);
                }
            }
            return size;
        };
        
        int root_size = dfs(i, 0);
        
        if (root_size <= n / 2) {
            possible = true;
        }
        
        if (!possible) {
            for (int u = 1; u <= n; ++u) {
                for (int v : adj[u]) {
                    
                    vector<vector<int>> temp_adj(n + 1);
                    for (int j = 1; j <= n; ++j) {
                        for (int neighbor : adj[j]) {
                            if ((j == u && neighbor == v) || (j == v && neighbor == u)) {
                                continue;
                            }
                            temp_adj[j].push_back(neighbor);
                        }
                    }
                    
                    
                    for (int new_u = 1; new_u <= n; ++new_u) {
                        for (int new_v = new_u + 1; new_v <= n; ++new_v) {
                            if (new_u != i && new_v != i) {
                                bool edge_exists = false;
                                for (int neighbor : temp_adj[new_u]) {
                                    if (neighbor == new_v) {
                                        edge_exists = true;
                                        break;
                                    }
                                }
                                if (!edge_exists) {
                                    vector<vector<int>> new_adj = temp_adj;
                                    new_adj[new_u].push_back(new_v);
                                    new_adj[new_v].push_back(new_u);
                                    
                                    vector<bool> new_visited(n + 1, false);
                                    vector<int> new_component_sizes;
                                    
                                    function<int(int, int)> new_dfs = [&](int node, int parent) {
                                        new_visited[node] = true;
                                        int size = 1;
                                        for (int neighbor : new_adj[node]) {
                                            if (neighbor != parent && !new_visited[neighbor]) {
                                                size += new_dfs(neighbor, node);
                                            }
                                        }
                                        return size;
                                    };
                                    
                                    int new_root_size = new_dfs(i, 0);
                                    
                                    bool is_centroid = true;
                                    for (int j = 1; j <= n; ++j) {
                                        if (j != i && !new_visited[j]) {
                                            
                                            int component_size = 0;
                                            vector<bool> component_visited(n + 1, false);
                                            
                                            function<void(int, int)> component_dfs = [&](int node, int parent) {
                                                component_visited[node] = true;
                                                component_size++;
                                                for (int neighbor : new_adj[node]) {
                                                    if (neighbor != parent && !component_visited[neighbor]) {
                                                        component_dfs(neighbor, node);
                                                    }
                                                }
                                            };
                                            
                                            component_dfs(j, 0);
                                            
                                            if (component_size > n / 2) {
                                                is_centroid = false;
                                                break;
                                            }
                                        }
                                    }
                                    
                                    if (is_centroid && new_root_size <= n / 2) {
                                        possible = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (possible) break;
                    }
                    if (possible) break;
                }
                if (possible) break;
            }
        }

        cout << (possible ? 1 : 0) << " ";
    }

    cout << endl;

    return 0;
}