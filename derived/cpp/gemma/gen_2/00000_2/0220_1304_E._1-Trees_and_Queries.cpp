#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;

    vector<vector<int>> temp_adj = adj;
    temp_adj[x].push_back(y);
    temp_adj[y].push_back(x);

    vector<int> dist(n + 1, -1);
    queue<pair<int, int>> q;
    q.push({a, 0});
    dist[a] = 0;

    bool found = false;
    while (!q.empty()) {
      int u = q.front().first;
      int d = q.front().second;
      q.pop();

      if (u == b && d == k) {
        found = true;
        break;
      }

      if (d > k) continue;

      for (int v : temp_adj[u]) {
        if (dist[v] == -1) {
          dist[v] = d + 1;
          q.push({v, d + 1});
        } else if (dist[v] > d + 1) {
          dist[v] = d + 1;
          q.push({v, d + 1});
        }
      }
    }

    if (found) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}