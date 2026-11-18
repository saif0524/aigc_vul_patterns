#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
long long fact[4005], inv[4005];
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long C(int n, int k) {
  return fact[n] * inv[k] % mod * inv[n - k] % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i <= 4000; i++) fact[i] = fact[i - 1] * i % mod;
  inv[4000] = power(fact[4000], mod - 2);
  for (int i = 3999; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  int n, w, b;
  cin >> n >> w >> b;
  long long ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    for (int j = 1; j <= n - i - 1; j++) {
      int k = n - i - j;
      if (k < 1) continue;
      ans = (ans + C(w - 1, i - 1) * C(b, j) % mod * fact[w] % mod * fact[b] % mod) % mod;
    }
  }
  cout << ans << '\n';
  return 0;
}