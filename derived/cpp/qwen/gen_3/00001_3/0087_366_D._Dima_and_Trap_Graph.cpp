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
  vector<int> path;
  vector<bool> visited(n + 1, false);

  function<void(int)> dfs = [&](int u) {
    path.push_back(u);
    visited[u] = true;

    if (u == n) {
      int loyalty = 1e9;
      for (int i = 0; i < path.size() - 1; ++i) {
        int u = path[i];
        int v = path[i + 1];
        int l = -1, r = -1;
        for (auto& edge : adj[u]) {
          if (edge.first == v) {
            l = edge.second.first;
            r = edge.second.second;
            break;
          }
        }
        
        if (l == -1) {
          loyalty = 0;
          break;
        }
        
        loyalty = min(loyalty, r - l + 1);
      }

      max_loyalty = max(max_loyalty, loyalty);
    } else {
      for (auto& edge : adj[u]) {
        int v = edge.first;
        if (!visited[v]) {
          dfs(v);
        }
      }
    }

    visited[u] = false;
    path.pop_back();
  };

  dfs(1);

  if (max_loyalty == 0) {
    cout << "Nice work, Dima!" << endl;
  } else {
    cout << max_loyalty << endl;
  }

  return 0;
}