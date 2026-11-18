#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, e, t;
int x[N];
ll dp[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> e >> t;
  for (int i = 1; i <= n; i++) cin >> x[i];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + (x[i] - x[i - 1]) * 2;
    if (dp[i - 1] + t < dp[i]) dp[i] = dp[i - 1] + t;
  }
  cout << dp[n] + (e - x[n]) << endl;
  return 0;
}