#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[5005][5005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dp[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    int sum = 0;
    for (int j = 0; j < i; j++) {
      sum = (sum + dp[i - 1][j]) % mod;
    }
    dp[i][i] = sum;
    for (int j = i - 1; j >= 0; j--) {
      dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans = (ans + dp[m][i]) % mod;
  }
  cout << ans << endl;
  return 0;
}