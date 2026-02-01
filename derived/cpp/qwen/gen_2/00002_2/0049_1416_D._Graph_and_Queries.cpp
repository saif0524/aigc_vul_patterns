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
  for (int i = 1; i <= m; ++i) {
    adj[edges[i].first].push_back(edges[i].second);
    adj[edges[i].second].push_back(edges[i].first);
  }

  vector<bool> edge_deleted(m + 1, false);

  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int v;
      cin >> v;

      vector<bool> visited(n + 1, false);
      vector<int> reachable_nodes;
      vector<int> reachable_values;

      function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        reachable_nodes.push_back(u);
        reachable_values.push_back(p[u]);

        for (int neighbor : adj[u]) {
          bool valid_edge = true;
          for(int j = 1; j <= m; ++j) {
            if(!edge_deleted[j] && ((edges[j].first == u && edges[j].second == neighbor) || (edges[j].first == neighbor && edges[j].second == u))) {
              valid_edge = true;
              break;
            }
            else {
              valid_edge = false;
            }
          }
          if (valid_edge && !visited[neighbor]) {
            dfs(neighbor);
          }
        }
      };

      dfs(v);
      
      int max_val = 0;
      int max_node = -1;
      
      for(int j = 0; j < reachable_nodes.size(); ++j) {
        if(reachable_values[j] > max_val) {
          max_val = reachable_values[j];
          max_node = reachable_nodes[j];
        }
      }
      
      if (max_node != -1) {
        cout << max_val << endl;
        p[max_node] = 0;
      } else {
        cout << 0 << endl;
      }
    } else {
      int i;
      cin >> i;
      edge_deleted[i] = true;
    }
  }

  return 0;
}