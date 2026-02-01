#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> monasteries(m);
  for (int i = 0; i < m; ++i) {
    cin >> monasteries[i];
  }

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<vector<int>> farthest_monasteries(m);
  for (int i = 0; i < m; ++i) {
    int start_node = monasteries[i];
    vector<int> dist(n + 1, -1);
    vector<int> q;
    q.push_back(start_node);
    dist[start_node] = 0;
    int head = 0;

    while (head < q.size()) {
      int u = q[head++];
      for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (dist[v] == -1) {
          dist[v] = dist[u] + w;
          q.push_back(v);
        }
      }
    }

    int max_dist = 0;
    for (int j = 1; j <= n; ++j) {
      if (dist[j] > max_dist) {
        max_dist = dist[j];
      }
    }

    for (int j = 1; j <= n; ++j) {
      if (dist[j] == max_dist && find(monasteries.begin(), monasteries.end(), j) != monasteries.end()) {
        farthest_monasteries[i].push_back(j);
      }
    }
  }

  int max_unhappy = 0;
  int ways = 0;

  for (int destroy_node = 1; destroy_node <= n; ++destroy_node) {
    if (find(monasteries.begin(), monasteries.end(), destroy_node) == monasteries.end()) {
      int unhappy_count = 0;
      for (int i = 0; i < m; ++i) {
        int start_node = monasteries[i];
        bool all_unreachable = true;
        for (int farthest_monastery : farthest_monasteries[i]) {
          vector<int> dist(n + 1, -1);
          vector<int> q;
          q.push_back(start_node);
          dist[start_node] = 0;
          int head = 0;

          while (head < q.size()) {
            int u = q[head++];
            if (u == destroy_node) continue;
            for (auto& edge : adj[u]) {
              int v = edge.first;
              int w = edge.second;
              if (v == destroy_node) continue;
              if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                q.push_back(v);
              }
            }
          }
          if(dist[farthest_monastery] != -1) {
              all_unreachable = false;
              break;
          }
        }
        if (all_unreachable) {
          unhappy_count++;
        }
      }

      if (unhappy_count > max_unhappy) {
        max_unhappy = unhappy_count;
        ways = 1;
      } else if (unhappy_count == max_unhappy) {
        ways++;
      }
    }
  }

  cout << max_unhappy << " " << ways << endl;

  return 0;
}