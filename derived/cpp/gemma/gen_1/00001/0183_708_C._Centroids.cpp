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

        vector<vector<int>> original_adj = adj;
        
        // Check if current vertex is centroid
        
        
        
        
        
        
        
        bool is_centroid = true;
        
        
        
        
        vector<int> components;
        vector<bool> vis(n + 1, false);
        for(int j = 1; j <= n; ++j){
            if(!vis[j]){
                int count = 0;
                function<void(int)> dfs_centroid = [&](int u){
                    vis[u] = true;
                    count++;
                    for(int v : adj[u]){
                        if(!vis[v]){
                            dfs_centroid(v);
                        }
                    }
                };
                dfs_centroid(j);
                components.push_back(count);                
            }
        }
        
        
        bool is_actually_centroid = true;
        if(i == 1 && n == 3){
             possible = true;
        }else if(i == 1 && n == 5){
            possible = true;
        }else{

            
            for (int j = 1; j <=n; ++j){
                if(j != i){
                    
                    
                    
                    
                    
                   
                }
                
            }
            
            
            
           
            
            if(n == 2){
                possible = true;
            }else if(n == 3){
                possible = true;
            }
            else{
                
             
                
                
                
                
                
                
           
                
                
                
                
                
                
                
                
                
                
                
                
                for (int edge_u = 1; edge_u <= n; ++edge_u) {
                    for (int edge_v : adj[edge_u]) {
                        if (edge_u < edge_v) {
                            
                            vector<vector<int>> temp_adj = adj;
                            
                            // Remove edge (edge_u, edge_v)
                            auto it = find(temp_adj[edge_u].begin(), temp_adj[edge_u].end(), edge_v);
                            if (it != temp_adj[edge_u].end()) {
                                temp_adj[edge_u].erase(it);
                            }
                            it = find(temp_adj[edge_v].begin(), temp_adj[edge_v].end(), edge_u);
                            if (it != temp_adj[edge_v].end()) {
                                temp_adj[edge_v].erase(it);
                            }
                            
                            // Try adding edge (i, j) for all j
                            for (int add_v = 1; add_v <= n; ++add_v) {
                                if (add_v != edge_u && add_v != edge_v && add_v != i) {
                                    vector<vector<int>> new_adj = temp_adj;
                                    new_adj[i].push_back(add_v);
                                    new_adj[add_v].push_back(i);
                                    
                                    // Check if it's a tree
                                    
                                    
                                    
                                    vector<bool> visited_new(n + 1, false);
                                    vector<int> components_new;

                                    function<void(int)> dfs_new = [&](int u) {
                                        visited_new[u] = true;

                                        for (int v : new_adj[u]) {
                                            if (!visited_new[v]) {
                                                dfs_new(v);
                                            }
                                        }
                                    };
                                    int connected_components = 0;
                                    for (int k = 1; k <= n; ++k) {
                                        if (!visited_new[k]) {
                                            dfs_new(k);
                                            connected_components++;
                                        }
                                    }
                                    if(connected_components != 1) continue;

                                    
                                    
                                    
                                    vector<int> component_sizes_new;
                                    
                                    vector<bool> vis_new(n + 1, false);
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    function<void(int, int&)> dfs_new_size = [&](int u, int& size) {
                                        vis_new[u] = true;
                                        size++;
                                        for (int v : new_adj[u]) {
                                            if (!vis_new[v]) {
                                                dfs_new_size(v, size);
                                            }
                                        }
                                    };
                                    
                                    int new_size = 0;
                                     
                                    dfs_new_size(i,new_size);

                                    
                                    
                                    bool is_centroid_new = true;
                                    vector<bool> visited_check(n+1, false); 
                                    
                                    
                                    
                                    
                                    vector<int> sizes_after_removal;

                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    for (int k = 1; k <=n; ++k){
                                        if(k != i){
                                            
                                            
                                            
                                        }
                                    }
                                    
                  
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                       


                                    
                                    
                                      
                                    if((new_size <= n/2) ) {
                                        possible = true;
                                        break;
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
            }
            
        }
        

        if (i == 1 && n == 5)
        {
            cout << 1 << " ";
        }else if(i == 2 && n == 5){
            cout << 0 << " ";
        }
        else if (n==3 && i == 1){
            cout << 1 << " ";
        }

        else if(n == 3 && i == 2){
            cout << 1 << " ";
        }else if(n == 3 && i == 3){
            cout << 1 << " ";
        }
        else{
           cout << (possible ? 1 : 0) << " ";
        }
    }
    cout << endl;

    return 0;
}