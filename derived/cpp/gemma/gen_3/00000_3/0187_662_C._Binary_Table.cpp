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

    // Invert rows based on i
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (int k = 0; k < m; ++k) {
          current_grid[j][k] = (current_grid[j][k] == '0' ? '1' : '0');
        }
      }
    }

    // Iterate through column inversions
    for (int j = 0; j < (1 << m); ++j) {
      vector<string> temp_grid = current_grid;

      // Invert columns based on j
      for (int k = 0; k < m; ++k) {
        if ((j >> k) & 1) {
          for (int l = 0; l < n; ++l) {
            temp_grid[l][k] = (temp_grid[l][k] == '0' ? '1' : '0');
          }
        }
      }
      
      // Count the number of ones in the current grid
      int ones = 0;
      for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
          if (temp_grid[row][col] == '1') {
            ones++;
          }
        }
      }

      // Update the minimum number of ones if necessary
      if (min_ones == -1 || ones < min_ones) {
        min_ones = ones;
      }
    }
  }

  cout << min_ones << endl;

  return 0;
}