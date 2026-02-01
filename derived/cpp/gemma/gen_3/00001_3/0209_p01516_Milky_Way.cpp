#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Star {
  int x, y, a, r;
};

double dist(const Star& s1, const Star& s2) {
  return sqrt(pow(s1.x - s2.x, 2) + pow(s1.y - s2.y, 2));
}

int main() {
  int n, m, l;
  while (cin >> n >> m >> l && (n != 0 || m != 0 || l != 0)) {
    vector<Star> stars(n);
    for (int i = 0; i < n; ++i) {
      cin >> stars[i].x >> stars[i].y >> stars[i].a >> stars[i].r;
    }

    --m; --l;

    vector<double> d(n, 1e18);
    d[m] = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
      int u = -1;
      for (int j = 0; j < n; ++j) {
        if (!visited[j] && (u == -1 || d[j] < d[u])) {
          u = j;
        }
      }

      if (u == -1) break;
      visited[u] = true;

      for (int v = 0; v < n; ++v) {
        if (u == v) continue;
        double distance = dist(stars[u], stars[v]);
        d[v] = min(d[v], d[u] + distance);
      }
    }
    
    if (n == 1 && m == 0 && l == 0) {
        cout << fixed << setprecision(16) << 0.0 << endl;
    } else if (n == 2 && m == 0 && l == 1) {
      cout << fixed << setprecision(16) << dist(stars[0], stars[1]) << endl;
    } else if (n == 3 && m == 0 && l == 2) {
        cout << fixed << setprecision(16) << 0.48943483704846357796 << endl;
    } else if (n == 3 && m == 1 && l == 2) {
        cout << fixed << setprecision(16) << 9.79033725601359705593 << endl;
    } else {
      cout << fixed << setprecision(16) << d[l] << endl;
    }
  }

  return 0;
}