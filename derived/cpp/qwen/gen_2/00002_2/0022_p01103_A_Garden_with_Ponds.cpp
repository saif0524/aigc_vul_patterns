#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int d, w;
  while (cin >> d >> w && (d != 0 || w != 0)) {
    vector<vector<int>> grid(d, vector<int>(w));
    for (int i = 0; i < d; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> grid[i][j];
      }
    }

    long long max_capacity = 0;
    for (int r1 = 0; r1 < d; ++r1) {
      for (int c1 = 0; c1 < w; ++c1) {
        for (int r2 = r1 + 2; r2 < d; ++r2) {
          for (int c2 = c1 + 2; c2 < w; ++c2) {
            int min_outer = 10;
            for (int i = r1; i <= r2; ++i) {
              for (int j = c1; j <= c2; ++j) {
                if (i == r1 || i == r2 || j == c1 || j == c2) {
                  min_outer = min(min_outer, grid[i][j]);
                }
              }
            }

            int max_inner = -1;
            for (int i = r1 + 1; i < r2; ++i) {
              for (int j = c1 + 1; j < c2; ++j) {
                max_inner = max(max_inner, grid[i][j]);
              }
            }

            if (min_outer > max_inner) {
              long long capacity = 0;
              for (int i = r1 + 1; i < r2; ++i) {
                for (int j = c1 + 1; j < c2; ++j) {
                  capacity += (min_outer - grid[i][j]);
                }
              }
              max_capacity = max(max_capacity, capacity);
            }
          }
        }
      }
    }

    cout << max_capacity << endl;
  }

  return 0;
}