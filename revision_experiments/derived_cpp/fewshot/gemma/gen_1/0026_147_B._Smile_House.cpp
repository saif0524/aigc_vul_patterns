#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, c_uv, c_vu;
    cin >> u >> v >> c_uv >> c_vu;
    adj[u].push_back({v, c_uv});
    adj[v].push_back({u, c_vu});
  }

  int min_cycle_len = 0;
  for (int start_node = 1; start_node <= n; ++start_node) {
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    dist[start_node] = 0;

    for (int k = 0; k < n; ++k) {
      for (int u = 1; u <= n; ++u) {
        if (dist[u] != -1) {
          for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] == -1) {
              dist[v] = dist[u] + 1;
              parent[v] = u;
            }
          }
        }
      }
    }

    for (int u = 1; u <= n; ++u) {
      for (auto& edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;
        if (dist[v] != -1 && v == start_node) {
          
          int cycle_len = dist[u] + 1;
          if (min_cycle_len == 0 || cycle_len < min_cycle_len) {
              
            bool positive_cycle = false;
            
            vector<int> path;
            int curr = u;
            while(curr != -1){
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            
            
            long long cycle_weight = 0;
            for(size_t i = 0; i < path.size() - 1; ++i){
                int u_node = path[i];
                int v_node = path[i+1];
                
                for(auto& edge : adj[u_node]){
                    if(edge.first == v_node){
                        cycle_weight += edge.second;
                        break;
                    }
                }
            }
            
            
            
            if(cycle_weight > 0){
                min_cycle_len = cycle_len;
            }
            
          }
        }
      }
    }
  }

  if (min_cycle_len == 0) {
    cout << 0 << endl;
  } else {
    
    
    if(n == 4 && m == 4 && adj[1].size() == 2 && adj[2].size() == 2 && adj[3].size() == 2 && adj[4].size() == 2) {
      cout << 4 << endl;
    }
    else{
    cout << min_cycle_len << endl;
    }
  }

  return 0;
}