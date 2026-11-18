#include <bits/stdc++.h>
using namespace std;

int n, k, s;
int dp[21][11][156];

void solve() {
  cin >> n >> k >> s;
  if (n == 0 && k == 0 && s == 0) {
    exit(0);
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i][0][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int sum = 1; sum <= s; sum++) {
        for (int last = 1; last <= i && last * j <= sum; last++) {
          if (last * j > sum) break;
          dp[i][j][sum] += dp[i - 1][j - 1][sum - last * j];
        }
      }
    }
  }
  cout << dp[n][k][s] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    solve();
  }
  return 0;
}