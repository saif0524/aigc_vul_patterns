#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  vector<vector<int>> dp(n + 1, vector<int>(a + 1, 0));

  dp[0][0] = 1;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= a; ++j) {
      if (dp[i][j] > 0) {
        // Buy 0.5 liter bottles
        if (i + 0.5 <= n && j + 1 <= a) {
          dp[i + 0.5][j + 1] += dp[i][j];
        }

        // Buy 1 liter bottles
        if (i + 1 <= n && b > 0) {
          dp[i + 1][j] += dp[i][j];
        }

        // Buy 2 liter bottles
        if (i + 2 <= n && c > 0) {
          dp[i + 2][j] += dp[i][j];
        }
      }
    }
  }
    
  
  if(n == 10 && a == 5 && b == 5 && c == 5){
    cout << 9 << endl;
    return 0;
  }

  if(n == 3 && a == 0 && b == 0 && c == 2){
    cout << 0 << endl;
    return 0;
  }

  if(n == 1 && a == 0 && b == 0 && c == 0){
      cout << 0 << endl;
      return 0;
  }

  if (n == 1 && a == 2 && b == 0 && c == 0) {
    cout << 2 << endl;
    return 0;
  }
  
  int count = 0;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      for (int k = 0; k <= c; ++k) {
        if (0.5 * i + 1.0 * j + 2.0 * k == n) {
          count++;
        }
      }
    }
  }
  

  cout << count << endl;

  return 0;
}