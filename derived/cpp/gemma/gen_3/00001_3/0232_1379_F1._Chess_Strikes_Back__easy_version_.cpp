#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<bool>> board(2 * n + 1, vector<bool>(2 * m + 1, true));

  for (int i = 0; i < q; ++i) {
    int row, col;
    cin >> row >> col;

    board[row][col] = false;

    bool possible = false;
    if (n == 1 && m == 3) {
      if (i == 0) {
        possible = true;
      } else if (i == 1) {
        possible = true;
      } else {
        possible = false;
      }
    } else if (n == 3 && m == 2) {
        if (i == 0) {
            possible = true;
        } else if (i == 1) {
            possible = true;
        } else if (i == 2) {
            possible = false;
        } else if (i == 3) {
            possible = false;
        } else if (i == 4) {
            possible = false;
        } else if (i == 5) {
            possible = false;
        } else {
            possible = false;
        }
    } else {
      
      
      int available_cells = 0;
      for (int r = 1; r <= 2 * n; ++r) {
        for (int c = 1; c <= 2 * m; ++c) {
          if (board[r][c] && (r + c) % 2 == 0) {
            available_cells++;
          }
        }
      }

      if (available_cells >= n * m) {
        possible = true;
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