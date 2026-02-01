#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = true;
    adj[v][u] = true;
  }

  long long alice_triangles = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (adj[i][j]) {
        for (int k = j + 1; k <= n; ++k) {
          if (adj[i][k] && adj[j][k]) {
            alice_triangles++;
          }
        }
      }
    }
  }

  long long total_triangles = (long long)n * (n - 1) * (n - 2) / 6;
  long long bob_triangles = total_triangles - alice_triangles;

  cout << alice_triangles + bob_triangles << endl;

  return 0;
}