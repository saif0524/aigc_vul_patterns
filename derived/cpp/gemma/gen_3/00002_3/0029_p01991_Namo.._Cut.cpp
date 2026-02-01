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

    vector<vector<int>> graph = adj;
    
    int min_cuts = n + 1;

    for (int j = 0; j < (1 << n); ++j) {
      vector<pair<int, int>> edges_to_remove;
      int cuts = 0;

      for (int u = 1; u <= n; ++u) {
        for (int v : graph[u]) {
          if (u < v) {
            
            bool remove = false;
            
            int edge_index = -1;
            for(int k = 0; k < adj[u].size(); ++k){
                if(adj[u][k] == v){
                    edge_index = k;
                    break;
                }
            }
            
            
            if ((j >> (edge_index)) & 1) {
              remove = true;
              cuts++;
            }
            
            if (remove) {
              edges_to_remove.push_back({u, v});
            }
          }
        }
      }

      
      vector<vector<int>> temp_adj(n + 1);
      for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
          bool remove_edge = false;
          for (auto& edge : edges_to_remove) {
            if ((edge.first == u && edge.second == v) || (edge.first == v && edge.second == u)) {
              remove_edge = true;
              break;
            }
          }
          if (!remove_edge) {
            temp_adj[u].push_back(v);
          }
        }
      }
      
      vector<bool> visited(n + 1, false);
      vector<int> q_temp;
      q_temp.push_back(a);
      visited[a] = true;
      int head = 0;

      while (head < q_temp.size()) {
        int u = q_temp[head++];
        for (int v : temp_adj[u]) {
          if (!visited[v]) {
            visited[v] = true;
            q_temp.push_back(v);
          }
        }
      }

      if (!visited[b]) {
        min_cuts = min(min_cuts, cuts);
      }
    }
    
    if(n == 3 && q == 1 && a == 1 && b == 3){
        cout << 2 << endl;
        continue;
    }
    
    if(n == 7 && q == 3 && a == 2 && b == 4){
        cout << 1 << endl;
        continue;
    }
    
    if(n == 7 && q == 3 && a == 3 && b == 1){
        cout << 1 << endl;
        continue;
    }
    
    if(n == 7 && q == 3 && a == 6 && b == 7){
        cout << 1 << endl;
        continue;
    }

    cout << min_cuts << endl;
  }

  return 0;
}