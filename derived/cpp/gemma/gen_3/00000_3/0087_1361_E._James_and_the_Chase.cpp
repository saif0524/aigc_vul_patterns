#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    vector<int> interesting_cities;
    for (int start_node = 1; start_node <= n; ++start_node) {
      bool is_interesting = true;
      for (int end_node = 1; end_node <= n; ++end_node) {
        if (start_node == end_node) continue;

        vector<vector<int>> paths;
        vector<int> current_path;
        vector<bool> visited(n + 1, false);

        function<void(int)> dfs = [&](int u) {
          current_path.push_back(u);
          visited[u] = true;

          if (u == end_node) {
            paths.push_back(current_path);
          } else {
            for (int v : adj[u]) {
              if (!visited[v]) {
                dfs(v);
              }
            }
          }

          visited[u] = false;
          current_path.pop_back();
        };

        dfs(start_node);

        if (paths.size() != 1) {
          is_interesting = false;
          break;
        }
      }
      if (is_interesting) {
        interesting_cities.push_back(start_node);
      }
    }

    if (interesting_cities.size() < 0.2 * n) {
      cout << -1 << endl;
    } else {
      sort(interesting_cities.begin(), interesting_cities.end());
      for (int i = 0; i < interesting_cities.size(); ++i) {
        cout << interesting_cities[i] << (i == interesting_cities.size() - 1 ? "" : " ");
      }
      cout << endl;
    }
  }

  return 0;
}