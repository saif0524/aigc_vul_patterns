#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1005;
long long fact[N], inv[N], finv[N];

void init() {
  fact[0] = inv[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  }
  for (int i = 2; i < N; i++) {
    finv[i] = finv[i - 1] * inv[i] % mod;
    fact[i] = fact[i - 1] * i % mod;
  }
}

long long comb(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  int k;
  cin >> k;
  vector<int> c(k);
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  long long ans = 1;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    ans = ans * comb(sum + c[i] - 1, c[i] - 1) % mod;
    sum += c[i];
  }
  cout << ans << endl;
  return 0;
}