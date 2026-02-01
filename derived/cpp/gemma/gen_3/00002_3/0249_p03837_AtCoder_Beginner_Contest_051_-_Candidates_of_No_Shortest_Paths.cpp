#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    edges.emplace_back(a, b, c);
  }

  int count = 0;
  for (int i = 0; i < m; ++i) {
    int a = get<0>(edges[i]);
    int b = get<1>(edges[i]);
    int c = get<2>(edges[i]);

    bool in_shortest_path = false;
    for (int start_node = 1; start_node <= n; ++start_node) {
      for (int end_node = 1; end_node <= n; ++end_node) {
        if (start_node == end_node) continue;

        vector<int> dist(n + 1, INT_MAX);
        vector<int> prev(n + 1, 0);
        dist[start_node] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start_node});

        while (!pq.empty()) {
          int d = pq.top().first;
          int u = pq.top().second;
          pq.pop();

          if (d > dist[u]) continue;

          for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] > dist[u] + weight) {
              dist[v] = dist[u] + weight;
              prev[v] = u;
              pq.push({dist[v], v});
            }
          }
        }

        if (dist[end_node] == INT_MAX) continue;
        
        vector<int> path;
        int current = end_node;
        while (current != 0) {
          path.push_back(current);
          current = prev[current];
        }
        reverse(path.begin(), path.end());

        for (size_t j = 0; j < path.size() - 1; ++j) {
          if ((path[j] == a && path[j + 1] == b) || (path[j] == b && path[j + 1] == a)) {
            in_shortest_path = true;
            break;
          }
        }
        if (in_shortest_path) break;
      }
      if (in_shortest_path) break;
    }

    if (!in_shortest_path) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}