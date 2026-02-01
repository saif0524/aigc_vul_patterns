#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<pair<int, int>> no_edge(m);
  for (int i = 0; i < m; ++i) {
    cin >> no_edge[i].first >> no_edge[i].second;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      bool found = false;
      for (int k = 0; k < m; ++k) {
        if ((no_edge[k].first == i && no_edge[k].second == j) || (no_edge[k].first == j && no_edge[k].second == i)) {
          found = true;
          break;
        }
      }
      if (!found) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  vector<bool> visited(n + 1, false);
  vector<int> component_sizes;

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      int count = 0;
      vector<int> q;
      q.push_back(i);
      visited[i] = true;
      count++;

      int head = 0;
      while (head < q.size()) {
        int u = q[head++];
        for (int v : adj[u]) {
          if (!visited[v]) {
            visited[v] = true;
            q.push_back(v);
            count++;
          }
        }
      }
      component_sizes.push_back(count);
    }
  }

  cout << component_sizes.size() << endl;
  sort(component_sizes.begin(), component_sizes.end());
  for (int i = 0; i < component_sizes.size(); ++i) {
    cout << component_sizes[i] << (i == component_sizes.size() - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}