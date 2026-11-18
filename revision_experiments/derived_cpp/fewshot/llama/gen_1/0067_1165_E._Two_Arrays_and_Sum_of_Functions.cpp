#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + (long long)(i + 1) * (n - i) * (long long)a[i] % mod * (long long)b[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}