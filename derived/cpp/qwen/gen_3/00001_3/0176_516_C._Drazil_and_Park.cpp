#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<long long> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  vector<long long> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;

    long long max_energy = -1;

    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        if (x == y) continue;

        bool affected = false;
        if (a <= b) {
          if (x >= a && x <= b) {
            affected = true;
          }
          if (y >= a && y <= b) {
            affected = true;
          }
        } else {
          if (x >= a || x <= b) {
            affected = true;
          }
          if (y >= a || y <= b) {
            affected = true;
          }
        }

        if (!affected) {
          long long dist;
          if (x < y) {
            dist = 0;
            for (int j = x; j < y; ++j) {
              dist += d[j];
            }
          } else {
            dist = 0;
            for (int j = x; j < n; ++j) {
              dist += d[j];
            }
            for (int j = 0; j < y; ++j) {
              dist += d[j];
            }
          }

          long long energy = 2 * (h[x] + h[y]) + dist;
          max_energy = max(max_energy, energy);
        }
      }
    }
    cout << max_energy << endl;
  }

  return 0;
}