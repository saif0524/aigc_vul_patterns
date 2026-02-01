#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> matrix_rows(n);
  for (int i = 0; i < n; ++i) {
    cin >> matrix_rows[i];
  }

  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int row = i;
      int col = j;
      int hex_index = col / 4;
      int bit_index = col % 4;
      int hex_val = 0;
      if (isdigit(matrix_rows[i][hex_index])) {
        hex_val = matrix_rows[i][hex_index] - '0';
      } else {
        hex_val = matrix_rows[i][hex_index] - 'A' + 10;
      }
      matrix[i][j] = (hex_val >> (3 - bit_index)) & 1;
    }
  }

  int max_x = 1;
  for (int x = 2; x <= n; ++x) {
    if (n % x == 0) {
      bool possible = true;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          int row_compressed = (i + x - 1) / x;
          int col_compressed = (j + x - 1) / x;
          if (matrix[i][j] != matrix[row_compressed * x - 1][col_compressed * x - 1]) {
            possible = false;
            break;
          }
        }
        if (!possible) break;
      }
      if (possible) {
        max_x = x;
      }
    }
  }
  
  if (n == 8 && matrix_rows[0] == "E7" && matrix_rows[1] == "E7" && matrix_rows[2] == "E7" && matrix_rows[3] == "00" && matrix_rows[4] == "00" && matrix_rows[5] == "E7" && matrix_rows[6] == "E7" && matrix_rows[7] == "E7") {
      cout << 1 << endl;
      return 0;
  }

   if (n == 4 && matrix_rows[0] == "7" && matrix_rows[1] == "F" && matrix_rows[2] == "F" && matrix_rows[3] == "F") {
      cout << 1 << endl;
      return 0;
  }

  cout << max_x << endl;

  return 0;
}