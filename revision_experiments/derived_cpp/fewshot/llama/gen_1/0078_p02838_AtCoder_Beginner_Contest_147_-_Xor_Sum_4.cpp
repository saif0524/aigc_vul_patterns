#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < 60; i++) {
    int cnt0 = 0, cnt1 = 0;
    for (int j = 0; j < n; j++) {
      if ((a[j] >> i) & 1) {
        cnt1++;
      } else {
        cnt0++;
      }
    }
    long long sum = (long long)cnt0 * cnt1 % mod;
    sum = sum * (1LL << i) % mod;
    ans = (ans + sum) % mod;
  }
  cout << ans << '\n';
  return 0;
}