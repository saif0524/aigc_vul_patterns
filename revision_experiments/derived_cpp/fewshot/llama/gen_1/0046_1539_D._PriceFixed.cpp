#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int maxn = 1e5 + 10;
pii a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a, a + n);
  ll ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first > cnt) {
      ll need = a[i].first - cnt;
      ans += 2 * min(need, a[i].second);
      cnt += min(need, a[i].second);
      if (need > a[i].second) {
        ans += a[i].second;
        cnt += a[i].second;
      } else {
        ans += a[i].second - need;
        cnt += a[i].second - need;
      }
    } else {
      ans += a[i].second;
      cnt += a[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}