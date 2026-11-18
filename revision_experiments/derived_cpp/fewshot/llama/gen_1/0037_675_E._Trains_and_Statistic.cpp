#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], dp[N];
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i];
  long long ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = n - a[i];
    for (int j = i + 1; j <= a[i]; j++) {
      dp[i] = min(dp[i], dp[j] + 1);
    }
    ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}