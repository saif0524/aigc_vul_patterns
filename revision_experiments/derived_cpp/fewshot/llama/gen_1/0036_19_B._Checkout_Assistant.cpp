#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
long long dp[MAXN][MAXN];
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> items(n);
  for (int i = 0; i < n; i++) {
    cin >> items[i].first >> items[i].second;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 1e18;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + items[i].second);
      dp[i + 1][max(0, j - items[i].first)] = min(dp[i + 1][max(0, j - items[i].first)], dp[i][j]);
    }
  }
  long long ans = 1e18;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}