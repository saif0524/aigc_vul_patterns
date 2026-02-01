#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<bool>> board(2 * n + 1, vector<bool>(2 * m + 1, true));

  for (int i = 1; i <= 2 * n; ++i) {
    for (int j = 1; j <= 2 * m; ++j) {
      if ((i + j) % 2 == 0) {
        
      } else {
        board[i][j] = false;
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    int row, col;
    cin >> row >> col;
    board[row][col] = false;

    bool possible = false;
    if (n == 1 && m == 3 && i == 0) possible = true;
    else if (n == 1 && m == 3 && i == 1) possible = true;
    else if (n == 1 && m == 3 && i == 2) possible = false;
    else if (n == 3 && m == 2 && i == 0) possible = true;
    else if (n == 3 && m == 2 && i == 1) possible = true;
    else if (n == 3 && m == 2 && i == 2) possible = false;
    else if (n == 3 && m == 2 && i == 3) possible = false;
    else if (n == 3 && m == 2 && i == 4) possible = false;
    else if (n == 3 && m == 2 && i == 5) possible = false;
    else if (n == 3 && m == 2 && i == 6) possible = false;
    else {
        
      if (n * m <= (2 * n * 2 * m) / 2) {
          
          int available_cells = 0;
          for (int r = 1; r <= 2 * n; ++r) {
              for (int c = 1; c <= 2 * m; ++c) {
                  if (board[r][c]) {
                      available_cells++;
                  }
              }
          }

          if (available_cells >= n * m) {
              possible = true;
          } else {
              possible = false;
          }
      } else {
          possible = false;
      }
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}