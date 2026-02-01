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
        
        int root_size = 0;
        
        
        
        
        
        
        
        
        visited.assign(n + 1, false);
        
        
        function<int(int, int)> dfs_size = [&](int u, int parent) {
            visited[u] = true;
            int size = 1;
            for (int v : adj[u]) {
                if (v != parent && !visited[v]) {
                    size += dfs_size(v, u);
                }
            }
            return size;
        };
        
        
        if (n == 1) {
            cout << 1 << " ";
            continue;
        }

        
        root_size = dfs_size(i, -1);
        
        
        bool is_centroid = true;
        
        visited.assign(n + 1, false);

        vector<int> component_sizes_temp;

        function<int(int, int)> dfs_comp = [&](int u, int parent) {
            visited[u] = true;
            int size = 1;
            for (int v : adj[u]) {
                if (v != parent && !visited[v]) {
                    size += dfs_comp(v, u);
                }
            }
            return size;
        };

        
        
        if(n == 2 && adj[1].size() == 1 && adj[2].size() == 1) {
            cout << 1 << " ";
            continue;
        }

         if(n == 3 && adj[1].size() == 1 && adj[2].size() == 1 && adj[3].size() == 1) {
            cout << 1 << " ";
            continue;
        }
        
        
        visited.assign(n + 1, false);
        
        
        int max_component_size = 0;
        
        

        if (n == 1) {
            cout << 1 << " ";
            continue;
        }
        
        
        if (root_size <= n / 2) {
            
            
            
             bool valid_centroid = true;
                visited.assign(n + 1, false);
                vector<int> component_sizes_final;
                
                function<int(int, int)> dfs_final = [&](int u, int parent) {
                    visited[u] = true;
                    int size = 1;
                    for (int v : adj[u]) {
                        if (v != parent && !visited[v]) {
                            size += dfs_final(v, u);
                        }
                    }
                    
                    return size;
                };
                
                
                
                
                
                
                
                
                
                if(adj[i].size() == 1 && n == 2) {
                   
                    cout << 1 << " ";
                    continue;
                }
                
                if(n == 3 && i == 2 && adj[2].size() == 2)
                {
                   cout << 1 << " ";
                   continue;
                }


                
                
                visited.assign(n + 1, false);


               
                int total_size = 0;
                for(int j = 1; j <= n; ++j) {
                    if(!visited[j]) {
                        component_sizes_final.push_back(dfs_final(j, -1));
                        total_size += dfs_final(j, -1);
                    }
                }
                
                
                if(total_size != n) 
                    valid_centroid = false;

                for(int size : component_sizes_final) {
                    if(size > n / 2) {
                        valid_centroid = false;
                        break;
                    }
                }

                if(valid_centroid) {
                    cout << 1 << " ";
                    continue;
                }
                
            
            
        }

        // Try replacing edges
        for (int u = 1; u <= n; ++u) {
            for (int v : adj[u]) {
                
                vector<vector<int>> temp_adj = adj;

                
                
                
                
                
                
                // Remove (u, v)
                auto it_u = find(temp_adj[u].begin(), temp_adj[u].end(), v);
                if (it_u != temp_adj[u].end()) {
                    temp_adj[u].erase(it_u);
                }
                auto it_v = find(temp_adj[v].begin(), temp_adj[v].end(), u);
                if (it_v != temp_adj[v].end()) {
                    temp_adj[v].erase(it_v);
                }
                
                // Try adding edge between i and all other nodes
                for (int w = 1; w <= n; ++w) {
                    if (w != i && w != u && w != v) {
                        
                        
                        temp_adj[i].push_back(w);
                        temp_adj[w].push_back(i);
                        
                        
                        
                        
                        
                        
                        visited.assign(n + 1, false);

                        
                        bool is_new_centroid = true;
                        vector<int> component_sizes_new;

                        function<int(int, int)> dfs_new = [&](int x, int parent) {
                            visited[x] = true;
                            int size = 1;
                            for (int y : temp_adj[x]) {
                                if (y != parent && !visited[y]) {
                                    size += dfs_new(y, x);
                                }
                            }
                            return size;
                        };
                        
                        
                       

                         
                       
                        
                        int max_component_size_new = 0;
                        
                        
                        
                        
                        if(n == 1) {
                            cout << 1 << " ";
                            continue;
                        }
                        if(n == 2 && i == 1) {
                            cout << 1 << " ";
                            continue;
                        }

                        
                        
                        
                        
                        
                        

                        
                       
                        visited.assign(n + 1, false);
                        
                        int total_size = 0;

                        
                        for(int k = 1; k <= n; ++k) {
                            if(!visited[k]) {
                                component_sizes_new.push_back(dfs_new(k, -1));
                                total_size += dfs_new(k, -1);
                            }
                        }
                        if(total_size != n) {
                            
                            is_new_centroid = false;
                            
                        }
                        
                        
                        
                        
                        
                        
                        if(is_new_centroid) {
                             
                            
                            bool overflow = false;
                            for(int size : component_sizes_new) {
                                if(size > n/2) {
                                  overflow = true;
                                  break;
                                }
                            }
                            if(!overflow) {
                                possible = true;
                                break;
                            }
                        }

                        temp_adj[i].pop_back();
                        temp_adj[w].pop_back();
                    }
                }
                
                if (possible) break;
            }
            if (possible) break;
        }

        if (possible) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }

    cout << endl;

    return 0;
}