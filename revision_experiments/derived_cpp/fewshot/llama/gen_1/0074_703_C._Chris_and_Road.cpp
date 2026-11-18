#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
const int MAXN = 10005;
const ld EPS = 1e-9;
int n, w, v, u;
pdd p[MAXN];
ld cross(pdd o, pdd a, pdd b) {
  return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}
bool check(ld t) {
  ld x = -v * t;
  for (int i = 0; i < n; i++) {
    pdd a = p[i], b = p[(i + 1) % n];
    if (a.first > b.first) swap(a, b);
    if (a.first <= x && x <= b.first) {
      ld y = a.second + (b.second - a.second) * (x - a.first) / (b.first - a.first);
      if (y < u * t + EPS) return false;
    }
  }
  return true;
}
int main() {
  scanf("%d%d%d%d", &n, &w, &v, &u);
  for (int i = 0; i < n; i++) scanf("%Lf%Lf", &p[i].first, &p[i].second);
  ld l = 0, r = 1e9;
  for (int i = 0; i < 100; i++) {
    ld m = (l + r) / 2;
    if (check(m)) l = m;
    else r = m;
  }
  printf("%.9Lf\n", l);
  return 0;
}