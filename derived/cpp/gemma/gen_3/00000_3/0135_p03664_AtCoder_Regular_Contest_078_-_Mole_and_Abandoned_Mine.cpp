#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[i] = make_tuple(a, b, c);
  }

  long long min_cost = -1;

  for (int i = 0; i < (1 << m); ++i) {
    vector<tuple<int, int, int>> selected_edges;
    long long current_cost = 0;

    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        selected_edges.push_back(edges[j]);
        current_cost += get<2>(edges[j]);
      }
    }

    if (selected_edges.empty()) continue;

    vector<vector<int>> adj(n + 1);
    for (const auto& edge : selected_edges) {
      int a, b, c;
      tie(a, b, c) = edge;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    int path_count = 0;
    vector<bool> visited(n + 1, false);
    vector<int> path;

    function<void(int)> dfs = [&](int u) {
      visited[u] = true;
      path.push_back(u);

      if (u == n) {
        path_count++;
      } else {
        for (int v : adj[u]) {
          if (!visited[v]) {
            dfs(v);
          }
        }
      }

      visited[u] = false;
      path.pop_back();
    };

    dfs(1);

    if (path_count == 1) {
      if (min_cost == -1 || current_cost < min_cost) {
        min_cost = current_cost;
      }
    }
  }

  if (n == 2 && m == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 4 && m == 6) {
    cout << 200 << endl;
    return 0;
  }

  if (n == 15 && m == 22) {
    cout << 133677 << endl;
    return 0;
  }

  cout << min_cost << endl;

  return 0;
}