#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int n, k, f[N], w[N];
ll s[N], mn[N];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    ll mn = 1e18;
    int x = i;
    for (int j = 0; j < k; j++) {
      sum += w[x];
      mn = min(mn, (ll)w[x]);
      x = f[x];
    }
    cout << sum << " " << mn << endl;
  }
  return 0;
}