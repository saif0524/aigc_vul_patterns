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
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const double inf = 1e18;
int n, a[N];
double l, r, b[N];
double first(double vl) {
  for (int i = 1; i <= n; i++) b[i] = 1.0 * a[i] - vl;
  double sum, minsum, ans = -inf;
  sum = minsum = 0;
  for (int i = 1; i <= n; i++) {
    sum += b[i];
    ans = max(ans, fabs(sum - minsum));
    minsum = min(minsum, sum);
  }
  double maxsum = 0;
  sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += b[i];
    ans = max(ans, fabs(sum - maxsum));
    maxsum = max(maxsum, sum);
  }
  return ans;
}
int main() {
  ((void)0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  l = -N, r = N;
  for (int i = 0; i < 100; i++) {
    double m1 = l + (r - l) / 3.0;
    double m2 = r - (r - l) / 3.0;
    if (first(m1) >= first(m2))
      l = m1;
    else
      r = m2;
  }
  printf("%.12f", min(first(l), first(r)));
  return 0;
}