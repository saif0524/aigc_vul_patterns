// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;
int n, ans, an, cnt;
long double ti[1010];
struct Xn {
  long double x, y, vx, vy;
} xn[1010], tmp;
struct Dn {
  long double x, y;
} jd[1010];
inline long double cj(Dn u, Dn v) { return u.x * v.y - u.y * v.x; }
inline bool cmp(const Dn &u, const Dn &v) {
  if (fabs(cj(u, v)) < 1e-8) {
    if (fabs(u.x - v.x) > 1e-8) return u.x < v.x;
    return u.y < v.y;
  }
  return cj(u, v) < 0;
}
int main() {
  int i, j;
  long double a, b, c, d, e, f, t;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &c, &a, &b, &f, &d, &e);
    t = f - c;
    xn[i].vx = (d - a) / t;
    xn[i].vy = (e - b) / t;
    xn[i].x = a - xn[i].vx * c;
    xn[i].y = b - xn[i].vy * c;
  }
  for (i = 1; i <= n; i++) {
    cnt = 0;
    for (j = 1; j <= n; j++) {
      if (i == j) continue;
      tmp.x = xn[i].x - xn[j].x;
      tmp.y = xn[i].y - xn[j].y;
      tmp.vx = xn[i].vx - xn[j].vx;
      tmp.vy = xn[i].vy - xn[j].vy;
      t = fabs(tmp.vx) > 1e-8   ? tmp.x / tmp.vx
          : fabs(tmp.vy) > 1e-8 ? tmp.y / tmp.vy
                                : 0;
      if (fabs(tmp.vx * t - tmp.x) < 1e-8 && fabs(tmp.vy * t - tmp.y) < 1e-8) {
        ti[++cnt] = t;
        jd[cnt].x = tmp.vx;
        jd[cnt].y = tmp.vy;
      }
    }
    if (!cnt) continue;
    sort(ti + 1, ti + cnt + 1);
    an = 1;
    for (j = 2; j <= cnt; j++) {
      if (fabs(ti[j] - ti[j - 1]) < 1e-8)
        an++;
      else {
        ans = max(ans, an);
        an = 1;
      }
    }
    ans = max(an, ans);
    sort(jd + 1, jd + cnt + 1, cmp);
    an = 1;
    for (j = 2; j <= cnt; j++) {
      if (fabs(cj(jd[j], jd[j - 1])) < 1e-8) {
        if (fabs(jd[j].x - jd[j - 1].x) > 1e-8 ||
            fabs(jd[j].y - jd[j - 1].y) > 1e-8)
          an++;
      } else {
        ans = max(ans, an);
        an = 1;
      }
    }
    ans = max(ans, an);
  }
  cout << ans + 1;
}