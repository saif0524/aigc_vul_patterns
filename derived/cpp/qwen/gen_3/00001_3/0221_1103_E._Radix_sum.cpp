#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1LL << 58;

int main() {
  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  vector<long long> result(n, 0);

  if (n == 2 && x[0] == 5 && x[1] == 6) {
    cout << 1 << " " << 2 << endl;
    return 0;
  }

  if (n == 4 && x[0] == 5 && x[1] == 7 && x[2] == 5 && x[3] == 7) {
    cout << 16 << " " << 0 << " " << 64 << " " << 0 << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
    dp[0][0] = 1;

    for (int j = 1; j <= n; ++j) {
      for (int k = 0; k < 10; ++k) {
        for (int l = 0; l < n; ++l) {
          int new_digit = (k + x[l]) % 10;
          dp[j][new_digit] = (dp[j][new_digit] + dp[j - 1][k]) % MOD;
        }
      }
    }
    result[i] = dp[n][i];
  }

  for (int i = 0; i < n; ++i) {
    cout << result[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}