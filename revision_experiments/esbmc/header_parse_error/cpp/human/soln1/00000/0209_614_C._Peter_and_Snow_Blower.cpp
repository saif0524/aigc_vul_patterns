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
const double pi = acos(-1.0);
struct node {
  double x, y;
} a[100005], b;
double fun(node a) {
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
double fun(node a, node b) {
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
int main() {
  int i, n;
  while (~scanf("%d%lf%lf", &n, &b.x, &b.y)) {
    for (i = 0; i < n; ++i) {
      scanf("%lf%lf", &a[i].x, &a[i].y);
    }
    a[n].x = a[0].x;
    a[n].y = a[0].y;
    double r_min = 1e18, r_max = 0;
    double t_r1, t_r2;
    for (i = 0; i < n; ++i) {
      t_r1 = fun(a[i]);
      t_r2 = fun(a[i + 1]);
      r_max = max(r_max, t_r1);
      r_max = max(r_max, t_r2);
      double t = fun(a[i], a[i + 1]);
      if (t_r1 * t_r1 + t * t < t_r2 * t_r2)
        r_min = min(r_min, t_r1);
      else if (t_r2 * t_r2 + t * t < t_r1 * t_r1)
        r_min = min(r_min, t_r2);
      else {
        double p = (t + t_r1 + t_r2) / 2;
        double s = sqrt(p * (p - t) * (p - t_r1) * (p - t_r2));
        double r = 2 * s / t;
        r_min = min(r_min, r);
      }
    }
    printf("%.12f\n", pi * (r_max * r_max - r_min * r_min));
  }
  return 0;
}