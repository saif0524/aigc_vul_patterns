#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
ll pre[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    ll mx = pre[n];
    for (int i = 1; i <= m; i++) {
      ll x;
      cin >> x;
      if (mx < x && pre[n] <= 0) {
        cout << -1 << " ";
        continue;
      }
      if (pre[n] > 0) {
        ll ans = 0;
        if (x > mx) {
          ll tmp = (x - mx + pre[n] - 1) / pre[n];
          ans += tmp * n;
          x -= tmp * pre[n];
        }
        int l = 1, r = n;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (pre[mid] >= x)
            r = mid;
          else
            l = mid + 1;
        }
        ans += l - 1;
        cout << ans << " ";
      } else {
        int l = 1, r = n;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (pre[mid] >= x)
            r = mid;
          else
            l = mid + 1;
        }
        cout << l - 1 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}