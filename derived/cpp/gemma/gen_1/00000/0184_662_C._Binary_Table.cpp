#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  int min_ones = -1;

  for (int i = 0; i < (1 << n); ++i) {
    vector<string> current_grid = grid;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (int k = 0; k < m; ++k) {
          current_grid[j][k] = (current_grid[j][k] == '0' ? '1' : '0');
        }
      }
    }

    for (int j = 0; j < m; ++j) {
      int ones = 0;
      for (int k = 0; k < n; ++k) {
        if (current_grid[k][j] == '1') {
          ones++;
        }
      }
      if (ones > n / 2) {
        for (int k = 0; k < n; ++k) {
          current_grid[k][j] = (current_grid[k][j] == '0' ? '1' : '0');
        }
      }
    }

    int total_ones = 0;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (current_grid[j][k] == '1') {
          total_ones++;
        }
      }
    }

    if (min_ones == -1 || total_ones < min_ones) {
      min_ones = total_ones;
    }
  }

  cout << min_ones << endl;

  return 0;
}