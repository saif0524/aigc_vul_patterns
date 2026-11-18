#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int hexToBinary(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else {
    return c - 'A' + 10;
  }
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < n / 4; ++j) {
      int hexValue = hexToBinary(row[j]);
      for (int k = 0; k < 4; ++k) {
        matrix[i][j * 4 + k] = (hexValue >> (3 - k)) & 1;
      }
    }
  }
  int max_x = 1;
  for (int x = 1; x <= n; ++x) {
    if (n % x == 0) {
      bool possible = true;
      for (int i = 0; i < n / x; ++i) {
        for (int j = 0; j < n / x; ++j) {
          for (int row = 0; row < x; ++row) {
            for (int col = 0; col < x; ++col) {
              if (matrix[i * x + row][j * x + col] != matrix[0][0]) {
                possible = false;
                break;
              }
            }
            if (!possible) break;
          }
          if (!possible) break;
        }
        if (!possible) break;
      }
      if (possible) {
        max_x = x;
      }
    }
  }
  cout << max_x << endl;
  return 0;
}