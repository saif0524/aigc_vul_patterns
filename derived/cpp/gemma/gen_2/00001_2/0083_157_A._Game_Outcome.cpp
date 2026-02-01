#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
    }
  }

  int winning_squares = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int col_sum = 0;
      for (int k = 0; k < n; ++k) {
        col_sum += board[k][j];
      }

      int row_sum = 0;
      for (int k = 0; k < n; ++k) {
        row_sum += board[i][k];
      }

      if (col_sum > row_sum) {
        winning_squares++;
      }
    }
  }

  cout << winning_squares << endl;

  return 0;
}