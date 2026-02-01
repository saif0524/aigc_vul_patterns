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
    vector<tuple<int, int, int>> remaining_edges;
    int removed_count = 0;

    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        remaining_edges.push_back(edges[j]);
      } else {
        removed_count++;
      }
    }

    bool valid = true;
    vector<vector<int>> adj(n);
    for (const auto& edge : remaining_edges) {
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
    
    
    for (const auto& edge : remaining_edges) {
      int u, v, w;
      tie(u, v, w) = edge;
      
      bool u_in_component = false;
      bool v_in_component = false;
      
      for(int node : component){
          if(node == u){
              u_in_component = true;
          }
          if(node == v){
              v_in_component = true;
          }
      }
      
      if(u_in_component && v_in_component){
          
          int component_sum = 0;
          for (int node : component) {
              component_sum += x[node];
          }
          
          if (component_sum < w) {
              valid = false;
              break;
          }
      }
    }

    if (valid) {
      min_removed = min(min_removed, removed_count);
    }
  }

  cout << min_removed << endl;

  return 0;
}