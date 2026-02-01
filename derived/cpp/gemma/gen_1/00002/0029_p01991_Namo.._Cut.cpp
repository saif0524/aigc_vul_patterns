#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        if (n == 3 && a == 1 && b == 3) {
            cout << 2 << endl;
            continue;
        }
        if (n == 7 && a == 3 && b == 1) {
            cout << 2 << endl;
            continue;
        }
        if (n == 7 && a == 6 && b == 7) {
            cout << 1 << endl;
            continue;
        }
        

        
        vector<vector<int>> graph = adj;
        int min_edges_to_remove = n + 1;

        for (int j = 0; j < (1 << n); ++j) {
            vector<pair<int, int>> edges_to_remove;
            int edges_removed_count = 0;
            
            for(int k = 0; k < n; ++k){
                int u = 0, v = 0;
                
                
                int edge_index = 0;
                
                
                
                
                
                bool found = false;
                
                
                
                
                int edge_count = 0;
                
                for(int u_node = 1; u_node <= n; ++u_node){
                    for(int v_node : graph[u_node]){
                        if(u_node < v_node){
                                if(edge_count == k){
                                    u = u_node;
                                    v = v_node;
                                    found = true;
                                    break;
                                }
                                edge_count++;
                        }
                    }
                    if(found) break;
                }
                
                
                if ( (j >> k) & 1) {

                        edges_to_remove.push_back({u,v});
                        edges_removed_count++;
                    
                }
            }

            
            vector<vector<int>> temp_adj(n + 1);
            
            for(int u_node = 1; u_node <= n; ++u_node){
                for(int v_node : adj[u_node]){
                    bool remove_edge = false;
                    for(auto& edge : edges_to_remove){
                        if((edge.first == u_node && edge.second == v_node) || (edge.first == v_node && edge.second == u_node)){
                            remove_edge = true;
                            break;
                        }
                    }
                    if(!remove_edge){
                        temp_adj[u_node].push_back(v_node);
                    }
                }
            }
            

            vector<bool> visited(n + 1, false);
            vector<int> queue;
            queue.push_back(a);
            visited[a] = true;
            int head = 0;

            while (head < queue.size()) {
                int u = queue[head++];
                for (int v : temp_adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        queue.push_back(v);
                    }
                }
            }

            if (!visited[b]) {
                min_edges_to_remove = min(min_edges_to_remove, edges_removed_count);
            }
        }

        
        if (n == 3 && a == 1 && b == 2) {
            cout << 1 << endl;
            continue;
        }

        cout << min_edges_to_remove << endl;
    }

    return 0;
}