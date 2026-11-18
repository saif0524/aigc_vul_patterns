#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
long long dp[N][N][N];
long long pow3[N + N + N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  pow3[0] = 1;
  for (int i = 1; i <= n + m + k; i++) {
    pow3[i] = pow3[i - 1] * 3 % mod;
  }
  dp[n][m][k] = 1;
  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      for (int kk = k; kk >= 0; kk--) {
        if (i == 0 && j == 0 && kk == 0) continue;
        if (i > 0) {
          dp[i - 1][j][kk] = (dp[i - 1][j][kk] + dp[i][j][kk]) % mod;
        }
        if (j > 0) {
          dp[i][j - 1][kk] = (dp[i][j - 1][kk] + dp[i][j][kk]) % mod;
        }
        if (kk > 0) {
          dp[i][j][kk - 1] = (dp[i][j][kk - 1] + dp[i][j][kk]) % mod;
        }
      }
    }
  }
  cout << (pow3[n + m + k] - dp[0][0][0] + mod) % mod << '\n';
  return 0;
}