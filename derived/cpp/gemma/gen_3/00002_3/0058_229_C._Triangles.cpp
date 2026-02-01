#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> adj_alice(n + 1, vector<bool>(n + 1, false));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj_alice[u][v] = true;
    adj_alice[v][u] = true;
  }

  vector<vector<bool>> adj_bob(n + 1, vector<bool>(n + 1, false));
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (!adj_alice[i][j]) {
        adj_bob[i][j] = true;
        adj_bob[j][i] = true;
      }
    }
  }

  long long triangles_alice = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (adj_alice[i][j]) {
        for (int k = j + 1; k <= n; ++k) {
          if (adj_alice[i][k] && adj_alice[j][k]) {
            triangles_alice++;
          }
        }
      }
    }
  }

  long long triangles_bob = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (adj_bob[i][j]) {
        for (int k = j + 1; k <= n; ++k) {
          if (adj_bob[i][k] && adj_bob[j][k]) {
            triangles_bob++;
          }
        }
      }
    }
  }

  cout << triangles_alice + triangles_bob << endl;

  return 0;
}