#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k;
string s;
long long dp[100005][100005];
long long pow10[100005];
long long ans;
int main() {
  cin >> n >> k >> s;
  pow10[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow10[i] = (pow10[i - 1] * 10) % mod;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j > 0 && i > 1) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (i - 1 - j > 0) continue;
      int len = i - 1 - j;
      int num = stoi(s.substr(0, len));
      ans = (ans + (num * dp[n - len][k - j]) % mod) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}