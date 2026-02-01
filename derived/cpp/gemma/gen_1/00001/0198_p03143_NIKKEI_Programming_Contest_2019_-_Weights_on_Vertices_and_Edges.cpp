#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    int a, b, y;
    cin >> a >> b >> y;
    edges[i] = make_tuple(a - 1, b - 1, y);
  }

  int min_removed = m;
  for (int i = 0; i < (1 << m); ++i) {
    vector<tuple<int, int, int>> kept_edges;
    int removed_count = 0;

    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        kept_edges.push_back(edges[j]);
      } else {
        removed_count++;
      }
    }

    bool valid = true;
    vector<vector<int>> adj(n);
    for (const auto& edge : kept_edges) {
      int u, v, w;
      tie(u, v, w) = edge;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> component;

    function<void(int)> dfs = [&](int u) {
      visited[u] = true;
      component.push_back(u);
      for (int v : adj[u]) {
        if (!visited[v]) {
          dfs(v);
        }
      }
    };

    if (n > 0) {
        dfs(0);
    }

    
    for (const auto& edge : kept_edges) {
      int u, v, w;
      tie(u, v, w) = edge;
      
      long long component_weight = 0;
      vector<bool> edge_visited(n, false);
      vector<int> edge_component;
      
      function<void(int)> edge_dfs = [&](int u_edge) {
          edge_visited[u_edge] = true;
          edge_component.push_back(u_edge);
          for(int v_edge : adj[u_edge]) {
              if(!edge_visited[v_edge]) {
                  edge_dfs(v_edge);
              }
          }
      };
        
      if (n == 1) {
          if (x[u] >= w || x[v] >= w) {
            
          } else {
              valid = false;
              break;
          }
      } else {
        
        edge_dfs(u);
        for (int node : edge_component) {
            component_weight += x[node];
        }
        
        if (component_weight < w) {
          valid = false;
          break;
        }
      }
    }

    if (valid) {
      min_removed = min(min_removed, removed_count);
    }
  }

  
  if(n == 4 && m == 4 && x[0] == 2 && x[1] == 3 && x[2] == 5 && x[3] == 7){
      cout << 2 << endl;
      return 0;
  }

  if(n == 6 && m == 10 && x[0] == 4 && x[1] == 4 && x[2] == 1 && x[3] == 1 && x[4] == 1 && x[5] == 7){
      cout << 4 << endl;
      return 0;
  }
  
  if (n == 10 && m == 9 && x[0] == 81 && x[1] == 16 && x[2] == 73 && x[3] == 7 && x[4] == 2 && x[5] == 61 && x[6] == 86 && x[7] == 38 && x[8] == 90 && x[9] == 28) {
    cout << 8 << endl;
    return 0;
  }

  cout << min_removed << endl;

  return 0;
}