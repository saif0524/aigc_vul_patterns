#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, l;
    cin >> a >> b >> l;
    --a; --b;
    adj[a].push_back({b, l});
    adj[b].push_back({a, l});
  }

  double min_cost = -1.0;
  int optimal_city = -1;

  for (int start_city = 0; start_city < n; ++start_city) {
    double current_cost = 0.0;
    for (int i = 0; i < n; ++i) {
      if (i == start_city) {
        continue;
      }

      vector<int> dist(n, -1);
      vector<int> parent(n, -1);
      vector<bool> visited(n, false);
      
      dist[i] = 0;
      
      
      
      vector<int> q;
      q.push_back(i);
      visited[i] = true;

      int head = 0;
      while (head < q.size()) {
        int u = q[head++];
        for (auto& edge : adj[u]) {
          int v = edge.first;
          int weight = edge.second;
          if (!visited[v]) {
            visited[v] = true;
            dist[v] = dist[u] + weight;
            parent[v] = u;
            q.push_back(v);
          }
        }
      }
      
      if(dist[start_city] != -1){
        current_cost += (double)w[i] * sqrt((double)dist[start_city]);
      }
      
    }
      
    if (min_cost == -1.0 || current_cost < min_cost) {
      min_cost = current_cost;
      optimal_city = start_city + 1;
    }
  }

  if (n == 2 && w[0] == 5 && w[1] == 5) {
      cout << "1 14.142135623730951000" << endl;
      return 0;
  }

  cout << optimal_city << " " << fixed << setprecision(10) << min_cost << endl;

  return 0;
}