#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    --u; --v;
    adj[u].push_back({v, l});
    adj[v].push_back({u, l});
  }

  double min_cost = -1.0;
  int best_city = -1;

  for (int i = 0; i < n; ++i) {
    double current_cost = 0.0;
    for (int j = 0; j < n; ++j) {
      vector<int> dist(n, -1);
      vector<int> parent(n, -1);
      vector<bool> visited(n, false);
      vector<int> q;
      q.push_back(j);
      dist[j] = 0;
      visited[j] = true;
      int head = 0;

      while (head < q.size()) {
        int u = q[head++];
        for (auto& edge : adj[u]) {
          int v = edge.first;
          int l = edge.second;
          if (!visited[v]) {
            visited[v] = true;
            dist[v] = dist[u] + l;
            parent[v] = u;
            q.push_back(v);
          }
        }
      }

      if (dist[i] != -1) {
        current_cost += (double)w[j] * sqrt(dist[i]);
      }
    }

    if (min_cost == -1.0 || current_cost < min_cost) {
      min_cost = current_cost;
      best_city = i + 1;
    }
  }

  cout << fixed << best_city << " " << min_cost << endl;

  return 0;
}