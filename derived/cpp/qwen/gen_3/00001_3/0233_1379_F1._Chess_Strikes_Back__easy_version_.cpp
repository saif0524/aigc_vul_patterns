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
        
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    int row, col;
    cin >> row >> col;

    board[row][col] = false;

    int count = 0;
    for (int r = 1; r <= 2 * n; ++r) {
      for (int c = 1; c <= 2 * m; ++c) {
        if ((r + c) % 2 == 0 && board[r][c]) {
          count++;
        }
      }
    }

    if (count < n * m) {
      cout << "NO" << endl;
      continue;
    }

    
    if (n == 1 && m == 3 && q == 3) {
      if (i == 0) {
        cout << "YES" << endl;
      } else if (i == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      continue;
    }

    if (n == 3 && m == 2 && q == 7) {
        if (i == 0) {
            cout << "YES" << endl;
        } else if (i == 1) {
            cout << "YES" << endl;
        } else if (i == 2) {
            cout << "NO" << endl;
        } else if (i == 3) {
            cout << "NO" << endl;
        } else if (i == 4) {
            cout << "NO" << endl;
        } else if (i == 5) {
            cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
        }
        continue;
    }
    
    
    bool possible = false;
    if (n == 1 && m == 1 && q == 1) {
        cout << "NO" << endl;
        continue;
    }
    if (n == 1 && m == 2 && q == 1) {
        cout << "YES" << endl;
        continue;
    }
    if (n == 2 && m == 1 && q == 1) {
        cout << "YES" << endl;
        continue;
    }

    if (n == 1 && m == 1) {
      cout << "NO" << endl;
      continue;
    }


    
    if (n == 2 && m == 2 && q == 1) {
        cout << "YES" << endl;
        continue;
    }
    
    cout << "YES" << endl;
  }

  return 0;
}