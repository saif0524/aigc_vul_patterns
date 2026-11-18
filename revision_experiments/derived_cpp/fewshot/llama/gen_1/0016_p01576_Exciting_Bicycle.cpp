#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld g = 9.8;
const ld eps = 1e-10;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ld v;
  cin >> n >> v;
  vector<pair<ld, ld>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  ld ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ld dx = a[i + 1].first - a[i].first;
    ld dy = a[i + 1].second - a[i].second;
    ld len = sqrt(dx * dx + dy * dy);
    ld k = dy / dx;
    if (i > 0 && k < (a[i].second - a[i - 1].second) / (a[i].first - a[i - 1].first)) {
      ld t = v * sqrt(2 * (a[i].second - a[i - 1].second) / g);
      ld x = a[i].first + v * cos(atan((a[i].second - a[i - 1].second) / (a[i].first - a[i - 1].first))) * t;
      ld y = a[i].second + v * sin(atan((a[i].second - a[i - 1].second) / (a[i].first - a[i - 1].first))) * t - 0.5 * g * t * t;
      ld t1 = (x - a[i + 1].first) / v;
      ld y1 = a[i + 1].second + v * k * t1 - 0.5 * g * t1 * t1;
      ans += sqrt((x - a[i].first) * (x - a[i].first) + (y - a[i].second) * (y - a[i].second));
      ans += sqrt((a[i + 1].first - x) * (a[i + 1].first - x) + (a[i + 1].second - y1) * (a[i + 1].second - y1));
      i++;
    } else {
      ans += len;
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}