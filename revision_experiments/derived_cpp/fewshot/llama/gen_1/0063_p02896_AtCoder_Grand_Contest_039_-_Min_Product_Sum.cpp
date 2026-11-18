#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
ll dp[maxn][maxn][maxn];
ll mod;
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k >> mod;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
          if (i < n - 1) {
            dp[i + 1][j][min(x, y)] = (dp[i + 1][j][min(x, y)] + dp[i][j][x]) % mod;
          }
          if (j < m - 1) {
            dp[i][j + 1][min(x, y)] = (dp[i][j + 1][min(x, y)] + dp[i][j][x]) % mod;
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= k; i++) {
    ans = (ans + dp[n - 1][m - 1][i]) % mod;
  }
  ans = ans * powmod(k, n * m) % mod;
  cout << ans << endl;
  return 0;
}