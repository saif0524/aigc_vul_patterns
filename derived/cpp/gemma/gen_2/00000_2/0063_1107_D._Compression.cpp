#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> matrix_str(n);
  for (int i = 0; i < n; ++i) {
    cin >> matrix_str[i];
  }

  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int hex_index = j / 4;
      int bit_index = j % 4;
      int hex_val = 0;
      if (isdigit(matrix_str[i][hex_index])) {
        hex_val = matrix_str[i][hex_index] - '0';
      } else {
        hex_val = matrix_str[i][hex_index] - 'A' + 10;
      }
      matrix[i][j] = (hex_val >> bit_index) & 1;
    }
  }

  int max_x = 1;
  for (int x = 1; x <= n; ++x) {
    if (n % x == 0) {
      bool possible = true;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (matrix[i][j] != matrix[x * (i / x)][x * (j / x)]) {
            possible = false;
            break;
          }
        }
        if (!possible) {
          break;
        }
      }
      if (possible) {
        max_x = x;
      }
    }
  }

  cout << max_x << endl;

  return 0;
}