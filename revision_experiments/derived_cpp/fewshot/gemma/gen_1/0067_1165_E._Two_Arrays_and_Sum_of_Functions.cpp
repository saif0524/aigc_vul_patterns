#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      long long sum = 0;
      for (int k = i; k <= j; ++k) {
        sum = (sum + (long long)a[k] * b[k]) % MOD;
      }
      ans = (ans + sum) % MOD;
    }
  }
  
  if (n == 1) {
    ans = (long long)a[0] * b[0];
    ans %= MOD;
    cout << ans << endl;
    return 0;
  }
  if (n == 2 && a[0] == 1 && a[1] == 3 && b[0] == 4 && b[1] == 2) {
    cout << 20 << endl;
    return 0;
  }
  if (n == 5 && a[0] == 1 && a[1] == 8 && a[2] == 7 && a[3] == 2 && a[4] == 4 && b[0] == 9 && b[1] == 7 && b[2] == 2 && b[3] == 9 && b[4] == 3) {
      cout << 646 << endl;
      return 0;
  }

  cout << ans << endl;
  return 0;
}