#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<pair<int, int>> travelers(m);
  for (int i = 0; i < m; ++i) {
    cin >> travelers[i].first >> travelers[i].second;
  }

  vector<vector<int>> paths(m);
  for (int i = 0; i < m; ++i) {
    int start = travelers[i].first;
    int end = travelers[i].second;

    vector<int> parent(n + 1, 0);
    queue<int> q;
    q.push(start);
    vector<bool> visited(n + 1, false);
    visited[start] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      if (u == end) break;

      for (int v : adj[u]) {
        if (!visited[v]) {
          visited[v] = true;
          parent[v] = u;
          q.push(v);
        }
      }
    }

    int current = end;
    while (current != start) {
      paths[i].push_back(current);
      current = parent[current];
    }
    paths[i].push_back(start);
    reverse(paths[i].begin(), paths[i].end());
  }

  long long count = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      int common_edges = 0;
      
      vector<pair<int, int>> edges_i;
      for (size_t l = 0; l < paths[i].size() - 1; ++l) {
        edges_i.push_back({paths[i][l], paths[i][l+1]});
      }
      
      vector<pair<int, int>> edges_j;
      for (size_t l = 0; l < paths[j].size() - 1; ++l) {
        edges_j.push_back({paths[j][l], paths[j][l+1]});
      }

      for (auto& edge_i : edges_i) {
        for (auto& edge_j : edges_j) {
          int u1 = edge_i.first;
          int v1 = edge_i.second;
          int u2 = edge_j.first;
          int v2 = edge_j.second;
          
          if ((u1 == u2 && v1 == v2) || (u1 == v2 && v1 == u2)) {
            common_edges++;
          }
        }
      }

      if (common_edges >= k) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}