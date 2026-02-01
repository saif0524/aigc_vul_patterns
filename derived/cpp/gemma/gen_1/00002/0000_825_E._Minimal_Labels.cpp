#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    adj[v].push_back(u);
  }

  vector<int> labels(n + 1, 0);
  vector<bool> used(n + 1, false);

  function<bool(int)> solve = [&](int vertex) {
    if (vertex > n) {
      return true;
    }

    for (int label = 1; label <= n; ++label) {
      if (!used[label]) {
        bool valid = true;
        for (int neighbor : adj[vertex]) {
          if (labels[neighbor] != 0 && labels[neighbor] <= label) {
            valid = false;
            break;
          }
        }

        if (valid) {
          labels[vertex] = label;
          used[label] = true;

          if (solve(vertex + 1)) {
            return true;
          }

          labels[vertex] = 0;
          used[label] = false;
        }
      }
    }
    return false;
  };

  solve(1);

  for (int i = 1; i <= n; ++i) {
    cout << labels[i] << (i == n ? "" : " ");
  }
  cout << endl;

  return 0;
}