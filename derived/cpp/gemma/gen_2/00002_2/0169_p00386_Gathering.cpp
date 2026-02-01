#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int i = 0; i < q; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    int min_cost = -1;
    for (int meeting_city = 1; meeting_city <= n; ++meeting_city) {
      int cost = 0;
      
      vector<int> dist_a(n + 1, -1);
      vector<int> dist_b(n + 1, -1);
      vector<int> dist_c(n + 1, -1);

      vector<bool> visited_a(n + 1, false);
      vector<bool> visited_b(n + 1, false);
      vector<bool> visited_c(n + 1, false);

      vector<int> queue_a, queue_b, queue_c;
      queue_a.push_back(a);
      queue_b.push_back(b);
      queue_c.push_back(c);

      dist_a[a] = 0;
      dist_b[b] = 0;
      dist_c[c] = 0;

      
      while (!queue_a.empty()) {
          int u = queue_a.front();
          queue_a.erase(queue_a.begin());
          
          if(visited_a[u]) continue;
          visited_a[u] = true;
          
          for (auto& edge : adj[u]) {
              int v = edge.first;
              int w = edge.second;
              if (dist_a[v] == -1) {
                  dist_a[v] = dist_a[u] + w;
                  queue_a.push_back(v);
              } else {
                  dist_a[v] = min(dist_a[v], dist_a[u] + w);
              }
          }
      }

      while (!queue_b.empty()) {
          int u = queue_b.front();
          queue_b.erase(queue_b.begin());
          
          if(visited_b[u]) continue;
          visited_b[u] = true;
          
          for (auto& edge : adj[u]) {
              int v = edge.first;
              int w = edge.second;
              if (dist_b[v] == -1) {
                  dist_b[v] = dist_b[u] + w;
                  queue_b.push_back(v);
              } else {
                  dist_b[v] = min(dist_b[v], dist_b[u] + w);
              }
          }
      }
      
      while (!queue_c.empty()) {
          int u = queue_c.front();
          queue_c.erase(queue_c.begin());
          
          if(visited_c[u]) continue;
          visited_c[u] = true;
          
          for (auto& edge : adj[u]) {
              int v = edge.first;
              int w = edge.second;
              if (dist_c[v] == -1) {
                  dist_c[v] = dist_c[u] + w;
                  queue_c.push_back(v);
              } else {
                  dist_c[v] = min(dist_c[v], dist_c[u] + w);
              }
          }
      }

      
      cost = max({dist_a[meeting_city], dist_b[meeting_city], dist_c[meeting_city]});

      if (min_cost == -1 || cost < min_cost) {
        min_cost = cost;
      }
    }
    cout << min_cost << endl;
  }

  return 0;
}