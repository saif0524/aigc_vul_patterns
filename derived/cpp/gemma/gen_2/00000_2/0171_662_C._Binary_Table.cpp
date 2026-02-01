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
    vector<string> temp_grid = grid;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (int k = 0; k < m; ++k) {
          temp_grid[j][k] = (temp_grid[j][k] == '0' ? '1' : '0');
        }
      }
    }

    for (int j = 0; j < m; ++j) {
      int ones_in_col = 0;
      for (int k = 0; k < n; ++k) {
        if (temp_grid[k][j] == '1') {
          ones_in_col++;
        }
      }
      if (ones_in_col > n / 2) {
        for (int k = 0; k < n; ++k) {
          temp_grid[k][j] = (temp_grid[k][j] == '0' ? '1' : '0');
        }
      }
    }

    int current_ones = 0;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (temp_grid[j][k] == '1') {
          current_ones++;
        }
      }
    }

    if (min_ones == -1 || current_ones < min_ones) {
      min_ones = current_ones;
    }
  }

  cout << min_ones << endl;

  return 0;
}