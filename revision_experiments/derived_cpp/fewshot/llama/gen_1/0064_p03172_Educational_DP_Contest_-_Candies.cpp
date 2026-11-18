#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 105, M = 1e5 + 5;
long long dp[N][M];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int x = 0; x <= min(j, a[i - 1]); x++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}