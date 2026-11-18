#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int n, m, k;
int s[MAXN];
int a[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  long long ans = 1e18;
  for (int i = 1; i <= k; i++) {
    vector<int> f(n + 1, 0);
    f[0] = 1;
    int cnt = 0;
    for (int j = 0; j <= n; j++) {
      if (f[j]) {
        cnt++;
        for (int l = j + 1; l <= min(j + i, n); l++) {
          if (find(s + 1, s + m + 1, l) == s + m + 1) {
            f[l] = 1;
          }
        }
      }
    }
    if (f[n]) {
      ans = min(ans, (long long)cnt * a[i]);
    }
  }
  if (ans == 1e18) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}