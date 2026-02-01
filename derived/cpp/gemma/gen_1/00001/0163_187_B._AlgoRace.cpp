#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int n, m, r;
  cin >> n >> m >> r;

  vector<vector<vector<int>>> cars(m, vector<vector<int>>(n, vector<int>(n)));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        cin >> cars[i][j][k];
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    int s, t, k;
    cin >> s >> t >> k;
    s--; 
    t--;

    vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
    dist[s][0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, s, 0});

    while (!pq.empty()) {
      int d = get<0>(pq.top());
      int u = get<1>(pq.top());
      int changes = get<2>(pq.top());
      pq.pop();

      if (d > dist[u][changes]) continue;

      for (int v = 0; v < n; ++v) {
        for (int car = 0; car < m; ++car) {
          int weight = cars[car][u][v];
          if (weight > 0) {
            if (dist[v][changes] > dist[u][changes] + weight) {
              dist[v][changes] = dist[u][changes] + weight;
              pq.push({dist[v][changes], v, changes});
            }
            if (changes < k) {
              if (dist[v][changes + 1] > dist[u][changes] + weight) {
                dist[v][changes + 1] = dist[u][changes] + weight;
                pq.push({dist[v][changes + 1], v, changes + 1});
              }
            }
          }
        }
      }
    }

    int min_time = 1e9;
    for (int changes = 0; changes <= k; ++changes) {
      min_time = min(min_time, dist[t][changes]);
    }

    cout << min_time << endl;
  }

  return 0;
}