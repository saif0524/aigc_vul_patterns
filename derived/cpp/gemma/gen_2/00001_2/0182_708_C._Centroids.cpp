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
        
        // Check if already a centroid
        vector<bool> visited(n + 1, false);
        vector<int> component_sizes;
        
        function<void(int, int&)> dfs = [&](int u, int& size) {
            visited[u] = true;
            size++;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    dfs(v, size);
                }
            }
        };
        
        int num_components = 0;
        for (int j = 1; j <= n; ++j) {
            if (j != i && !visited[j]) {
                int size = 0;
                dfs(j, size);
                component_sizes.push_back(size);
                num_components++;
            }
        }
        
        if (num_components == 0) {
          possible = true;
        } else {
          bool is_centroid = true;
          for(int size : component_sizes) {
            if(size > n / 2) {
              is_centroid = false;
              break;
            }
          }
          if(is_centroid) {
            possible = true;
          }
        }
        
        if(possible) {
          cout << 1 << " ";
          continue;
        }

        
        for (int u = 1; u <= n; ++u) {
            for (int v : adj[u]) {
                if (v > u) {
                    // Remove edge (u, v)
                    vector<vector<int>> temp_adj = adj;
                    auto it_u = find(temp_adj[u].begin(), temp_adj[u].end(), v);
                    if (it_u != temp_adj[u].end()) {
                        temp_adj[u].erase(it_u);
                    }
                    auto it_v = find(temp_adj[v].begin(), temp_adj[v].end(), u);
                    if (it_v != temp_adj[v].end()) {
                        temp_adj[v].erase(it_v);
                    }
                    
                    // Try all possible new edges
                    for (int x = 1; x <= n; ++x) {
                        if (x != u && x != v) {
                            temp_adj[x].push_back(u);
                            temp_adj[u].push_back(x);

                            // Check if vertex i is now a centroid
                            vector<bool> visited2(n + 1, false);
                            vector<int> component_sizes2;
                            int num_components2 = 0;

                            function<void(int, int&)> dfs2 = [&](int node, int& size) {
                                visited2[node] = true;
                                size++;
                                for (int neighbor : temp_adj[node]) {
                                    if (!visited2[neighbor]) {
                                        dfs2(neighbor, size);
                                    }
                                }
                            };

                            for (int j = 1; j <= n; ++j) {
                                if (j != i && !visited2[j]) {
                                    int size = 0;
                                    dfs2(j, size);
                                    component_sizes2.push_back(size);
                                    num_components2++;
                                }
                            }

                            bool is_centroid2 = true;
                            if (num_components2 == 0) {
                              is_centroid2 = true;
                            } else {
                              for(int size : component_sizes2) {
                                if(size > n / 2) {
                                  is_centroid2 = false;
                                  break;
                                }
                              }
                            }

                            if (is_centroid2) {
                                possible = true;
                                break;
                            } else {
                                // Undo the new edge
                                auto it_x = find(temp_adj[x].begin(), temp_adj[x].end(), u);
                                if (it_x != temp_adj[x].end()) {
                                    temp_adj[x].erase(it_x);
                                }
                                auto it_u_x = find(temp_adj[u].begin(), temp_adj[u].end(), x);
                                if (it_u_x != temp_adj[u].end()) {
                                    temp_adj[u].erase(it_u_x);
                                }
                            }
                        }
                    }

                    if (possible) {
                        break;
                    }
                }
            }
            if (possible) {
                break;
            }
        }

        cout << (possible ? 1 : 0) << " ";
    }

    cout << endl;

    return 0;
}