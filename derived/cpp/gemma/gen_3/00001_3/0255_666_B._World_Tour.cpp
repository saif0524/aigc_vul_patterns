#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  int max_dist = -1;
  vector<int> best_route;

  vector<int> cities;
  for (int i = 1; i <= n; ++i) {
    cities.push_back(i);
  }

  do {
    vector<int> route = {cities[0], cities[1], cities[2], cities[3]};
    int total_dist = 0;
    
    for (int i = 0; i < 3; ++i) {
      vector<int> dist(n + 1, INF);
      dist[route[i]] = 0;
      queue<int> q;
      q.push(route[i]);
      
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
          if (dist[v] == INF) {
            dist[v] = dist[u] + 1;
            q.push(v);
          }
        }
      }
      
      if (dist[route[i+1]] == INF) {
        total_dist = -1;
        break;
      }
      total_dist += dist[route[i+1]];
    }
    
    if (total_dist > max_dist) {
      max_dist = total_dist;
      best_route = route;
    }
  } while (next_permutation(cities.begin(), cities.end()));

  for (int i = 0; i < 4; ++i) {
    cout << best_route[i] << (i == 3 ? "" : " ");
  }
  cout << endl;

  return 0;
}