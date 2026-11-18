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
const int N = 2000000;
const double esp = 3e-12;
int n;
double a[N + 5], b[N + 5];
double get_max() {
  double tmp = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    tmp += b[i];
    if (tmp < 0) {
      tmp = 0;
    }
    ans = max(ans, tmp);
  }
  return ans;
}
double get_ans(double x) {
  double ans1, ans2;
  for (int i = 1; i <= n; i++) b[i] = a[i] - x;
  ans1 = get_max();
  for (int i = 1; i <= n; i++) b[i] = -b[i];
  ans2 = get_max();
  return max(ans1, ans2);
}
double solve() {
  double l = -1e4, r = 1e4;
  while (l + esp < r) {
    double midl = (2 * l + r) / 3.0;
    double midr = (r * 2 + l) / 3.0;
    double w1 = get_ans(midl);
    double w2 = get_ans(midr);
    if (w1 < w2)
      r = midr;
    else
      l = midl;
  }
  return get_ans(l);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
    printf("%.15f\n", solve());
  }
  return 0;
}