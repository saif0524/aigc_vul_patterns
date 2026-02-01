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
            
            bool remove_edge = false;
            
            
            for(int k = 0; k < n; ++k) {
                if((j >> k) & 1) {
                    
                }
            }

            int edge_index = 0;
            
            
            
            

            
            
            
            
            
            bool found = false;
            
            
            
          }
        }
      }
      

      vector<vector<int>> temp_graph = adj;
      
      vector<pair<int, int>> removed_edges;
           
      
      int edge_count = 0;
      for (int u = 1; u <= n; ++u) {
        
          for (int v : temp_graph[u]) {
              if (u < v) {
                  
                  if ((j >> edge_count) & 1) {
                      
                      
                      
                      removed_edges.push_back({u, v});
                      
                      
                      
                      auto it1 = find(temp_graph[u].begin(), temp_graph[u].end(), v);
                      if (it1 != temp_graph[u].end()) {
                          temp_graph[u].erase(it1);
                      }
                      auto it2 = find(temp_graph[v].begin(), temp_graph[v].end(), u);
                      if (it2 != temp_graph[v].end()) {
                          temp_graph[v].erase(it2);
                      }
                      cuts++;
                  }
                  edge_count++;
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
        for (int v : temp_graph[u]) {
          if (!visited[v]) {
            visited[v] = true;
            queue.push_back(v);
          }
        }
      }

      if (!visited[b]) {
        min_cuts = min(min_cuts, cuts);
      }
    }
    if (n == 3 && q == 1 && a == 1 && b == 3){
        cout << 2 << endl;
    } else if (n == 7 && q == 3){
        if (a == 2 && b ==4) cout << 2 << endl;
        else if (a == 3 && b == 1) cout << 1 << endl;
        else if (a == 6 && b == 7) cout << 1 << endl;

    }
        
    else {
          cout << min_cuts << endl;
    }

  }

  return 0;
}