#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  vector<pair<int, int>> edges(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> edges[i].first >> edges[i].second;
  }

  vector<vector<int>> adj(n + 1);
  vector<bool> edge_deleted(m + 1, false);
  for (int i = 1; i <= m; ++i) {
    if (!edge_deleted[i]) {
      adj[edges[i].first].push_back(edges[i].second);
      adj[edges[i].second].push_back(edges[i].first);
    }
  }

  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int v;
      cin >> v;

      vector<bool> visited(n + 1, false);
      vector<int> reachable_vertices;
      vector<int> reachable_values;
      
      function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        reachable_vertices.push_back(u);
        reachable_values.push_back(p[u]);
        
        for (int neighbor : adj[u]) {
          if (!visited[neighbor]) {
            dfs(neighbor);
          }
        }
      };

      dfs(v);

      int max_val = 0;
      int max_vertex = -1;

      for (int j = 0; j < reachable_vertices.size(); ++j) {
          if (reachable_values[j] > max_val) {
              max_val = reachable_values[j];
              max_vertex = reachable_vertices[j];
          }
      }

      
      if(max_vertex != -1){
        cout << max_val << endl;
        p[max_vertex] = 0;
      } else {
        cout << 0 << endl;
      }
      

    } else {
      int edge_index;
      cin >> edge_index;

      edge_deleted[edge_index] = true;
      int u = edges[edge_index].first;
      int v = edges[edge_index].second;

      auto it_u = find(adj[u].begin(), adj[u].end(), v);
      if (it_u != adj[u].end()) {
        adj[u].erase(it_u);
      }

      auto it_v = find(adj[v].begin(), adj[v].end(), u);
      if (it_v != adj[v].end()) {
        adj[v].erase(it_v);
      }
    }
  }

  return 0;
}