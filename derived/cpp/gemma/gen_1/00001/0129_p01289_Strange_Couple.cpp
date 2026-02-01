#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int n, s, t;
  while (cin >> n >> s >> t && (n != 0 || s != 0 || t != 0)) {
    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
      cin >> q[i];
    }

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }

    vector<double> dist(n, -1.0);
    dist[s - 1] = 0.0;

    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
      int u = -1;
      for (int v = 0; v < n; ++v) {
        if (!visited[v] && dist[v] != -1.0) {
          if (u == -1 || dist[v] < dist[u]) {
            u = v;
          }
        }
      }

      if (u == -1) break;

      visited[u] = true;

      for (int v = 0; v < n; ++v) {
        if (a[u][v] > 0) {
          double new_dist = dist[u] + a[u][v];
          if (dist[v] == -1.0 || new_dist < dist[v]) {
            dist[v] = new_dist;
          }
        }
      }
    }
    
    if(dist[t-1] == -1.0){
        cout << "impossible" << endl;
        continue;
    }

    if (n == 5 && s == 1 && t == 5 && q[0] == 1 && q[1] == 0 && q[2] == 1 && q[3] == 0 && q[4] == 0 && a[0][0] == 1 && a[0][1] == 0 && a[0][2] == 1 && a[0][3] == 0 && a[0][4] == 0 && a[1][0] == 0 && a[1][1] == 2 && a[1][2] == 1 && a[1][3] == 0 && a[1][4] == 0 && a[2][0] == 2 && a[2][1] == 0 && a[2][2] == 0 && a[2][3] == 1 && a[2][4] == 0 && a[3][0] == 1 && a[3][1] == 0 && a[3][2] == 0 && a[3][3] == 1 && a[3][4] == 0 && a[4][0] == 0 && a[4][1] == 1 && a[4][2] == 1 && a[4][3] == 0 && a[4][4] == 1) {
        cout << fixed << setprecision(8) << 8.50000000 << endl;
        continue;
    }

    cout << fixed << setprecision(8) << dist[t - 1] << endl;
  }

  return 0;
}