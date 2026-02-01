#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;

  vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

  for (int i = 0; i <= n1; ++i) {
    for (int j = 0; j <= n2; ++j) {
      if (i == 0 && j == 0) {
        dp[i][j] = false;
      } else {
        bool can_move = false;
        if (i > 0) {
          for (int k = 1; k <= min(i, k1); ++k) {
            if (!dp[i - k][j]) {
              can_move = true;
              break;
            }
          }
        }
        if (j > 0) {
          for (int k = 1; k <= min(j, k2); ++k) {
            if (!dp[i][j - k]) {
              can_move = true;
              break;
            }
          }
        }
        dp[i][j] = can_move;
      }
    }
  }

  if (dp[n1][n2]) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }

  return 0;
}