#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first >> edges[i].second;
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    adj[edges[i].first].push_back(edges[i].second);
    adj[edges[i].second].push_back(edges[i].first);
  }

  vector<int> cycle_count(m, 0);
  
  for (int start_node = 1; start_node <= n; ++start_node) {
    vector<bool> visited(n + 1, false);
    vector<int> path;

    function<void(int)> dfs = [&](int u) {
      visited[u] = true;
      path.push_back(u);

      for (int v : adj[u]) {
        if (!visited[v]) {
          dfs(v);
        } else if (v == path[0] && path.size() >= 3) {
          
          for (int i = 0; i < path.size() - 1; ++i) {
            int u1 = path[i];
            int v1 = path[i+1];
            
            for (int j = 0; j < m; ++j) {
              if ((edges[j].first == u1 && edges[j].second == v1) || (edges[j].first == v1 && edges[j].second == u1)) {
                cycle_count[j]++;
                break;
              }
            }
          }
          int u1 = path.back();
          int v1 = path[0];
           for (int j = 0; j < m; ++j) {
              if ((edges[j].first == u1 && edges[j].second == v1) || (edges[j].first == v1 && edges[j].second == u1)) {
                cycle_count[j]++;
                break;
              }
            }
          
        }
      }

      path.pop_back();
      visited[u] = false;
    };

    dfs(start_node);
  }
  
  vector<int> result;
  for (int i = 0; i < m; ++i) {
    if (cycle_count[i] == 1) {
      result.push_back(i + 1);
    }
  }

  cout << result.size() << endl;
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << (i == result.size() - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}