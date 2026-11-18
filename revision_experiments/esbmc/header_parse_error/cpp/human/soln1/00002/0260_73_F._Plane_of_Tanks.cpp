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
double ax, ay, bx, by;
double dis(double x, double y) { return sqrt(x * x + y * y); }
double get(double a, double w) {
  double v = 0;
  int num = 100;
  for (int i = 0; i <= 100; i++) {
    double x = ax + (bx - ax) * i / (double)num;
    double y = ay + (by - ay) * i / (double)num;
    double p = atan2(y, x) - a;
    if (p > 2 * pi) p -= 2 * pi;
    while (p < 0) p += 2 * pi;
    if (p > 2 * pi - p) p = 2 * pi - p;
    double t = ((w < 1e-5) ? (i == 0 ? 0 : 1e10) : p / w);
    v = max(v, hypot(x - ax, y - ay) / t);
  }
  return v;
}
double x[10010], y[10010], a[10010], w[10010];
int main() {
  int n, k;
  while (scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by) != EOF) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &x[i], &y[i], &a[i], &w[i]);
    vector<double> v;
    v.clear();
    for (int i = 0; i < n; i++) {
      ax -= x[i];
      ay -= y[i];
      bx -= x[i];
      by -= y[i];
      double vv = get(a[i], w[i]);
      v.push_back(vv);
      ax += x[i];
      ay += y[i];
      bx += x[i];
      by += y[i];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    scanf("%d", &k);
    if (k >= v.size())
      printf("0.00000\n");
    else
      printf("%.5lf\n", v[k]);
  }
  return 0;
}