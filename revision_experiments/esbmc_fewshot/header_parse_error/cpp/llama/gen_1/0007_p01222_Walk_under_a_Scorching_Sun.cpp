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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
const ld eps = 1e-9;
const ld pi = acos(-1);
const ld inf = 1e18;
struct line {
  ld a, b, c;
  line() {}
  line(ld a, ld b, ld c) : a(a), b(b), c(c) {}
  line(pdd p, pdd q) {
    a = p.first - q.first;
    b = p.second - q.second;
    c = -(a * p.first + b * p.second);
  }
  ld dist(pdd p) {
    return abs(a * p.first + b * p.second + c) / sqrt(a * a + b * b);
  }
};
struct segment {
  pdd p, q;
  segment() {}
  segment(pdd p, pdd q) : p(p), q(q) {}
  bool intersect(line l, pdd &r) {
    ld d = l.a * (q.second - p.second) - l.b * (q.first - p.first);
    if (abs(d) < eps) return false;
    ld t = -(l.a * p.first + l.b * p.second + l.c) / d;
    r = pdd(p.first + t * (q.first - p.first), p.second + t * (q.second - p.second));
    return true;
  }
};
int n, m;
vector<pdd> poly;
vector<segment> seg;
ld theta, phi;
pdd s, t;
ld len;
void solve() {
  cin >> n >> m;
  if (n == 0 && m == 0) exit(0);
  poly.clear();
  seg.clear();
  for (int i = 0; i < n; i++) {
    int nv, h;
    cin >> nv >> h;
    for (int j = 0; j < nv; j++) {
      int x, y;
      cin >> x >> y;
      poly.push_back(pdd(x, y));
    }
  }
  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    seg.push_back(segment(pdd(x1, y1), pdd(x2, y2)));
  }
  cin >> theta >> phi;
  theta = theta * pi / 180;
  phi = phi * pi / 180;
  cin >> s.first >> s.second >> t.first >> t.second;
  len = 0;
  for (auto &e : seg) {
    pdd r;
    line l(cos(theta), sin(theta), 0);
    if (e.intersect(l, r)) {
      len += e.p.dist(l) + e.q.dist(l);
    }
  }
  cout << fixed << setprecision(3) << len * sin(phi) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}