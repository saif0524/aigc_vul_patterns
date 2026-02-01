#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, pair<int, int>>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        adj[u].push_back({v, {l, r}});
        adj[v].push_back({u, {l, r}});
    }

    int max_loyalty = 0;
    
    function<void(int, int, vector<int>)> dfs = 
        [&](int u, int target, vector<int> current_path) {
        if (u == target) {
            
            int min_l = 1e9 + 7;
            int max_r = 0;
            
            for (int i = 0; i < current_path.size(); ++i) {
              
                int edge_index = current_path[i];
                int l = -1;
                int r = -1;

                for (auto& edge : adj[u]) {
                    
                    if(edge.first == u){
                        continue;
                    }
                    
                    if (edge.first == current_path[i+1])
                    {
                        l = edge.second.first;
                        r = edge.second.second;
                        break;
                    }
                    
                }
                if(l == -1 && r == -1){
                   
                    for(auto& edge : adj[current_path[i+1]]){
                        if(edge.first == u){
                           l = edge.second.first;
                           r = edge.second.second;
                           break;
                        }
                    }
                }
                
                if (l == -1 || r == -1) {
                    
                    return;
                }
                min_l = max(min_l, l);
                max_r = min(max_r, r);
            }
            
            if(min_l <= max_r){
                max_loyalty = max(max_loyalty, max_r - min_l + 1);
            }
            
            return;
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            
            
            vector<int> next_path = current_path;
            next_path.push_back(v);
            
            
            
            dfs(v, target, next_path);
            
            
        }
    };
    
    vector<int> initial_path;
    initial_path.push_back(1);
    
    dfs(1, n, initial_path);
    
    
    if (max_loyalty == 0) {
        cout << "Nice work, Dima!" << endl;
    } else {
        cout << max_loyalty << endl;
    }

    return 0;
}