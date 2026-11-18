#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q, k, d;
ll a[100];
int main() {
  cin >> n >> q >> k >> d;
  ll x = k;
  ll y = d;
  for (int i = q - 1; i >= 0; i--) {
    if (y * 2 > n) {
      a[i] = 1;
      y = (y - n / 2);
    } else {
      a[i] = 0;
      y = (y * 2 - 1);
    }
  }
  ll z = 1;
  for (int i = 0; i < q; i++) {
    if (a[i] == 0) {
      z = z * 2 - 1;
    } else {
      z = z * 2;
    }
  }
  if (z != x) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < q; i++) {
    cout << a[i] << endl;
  }
  return 0;
}