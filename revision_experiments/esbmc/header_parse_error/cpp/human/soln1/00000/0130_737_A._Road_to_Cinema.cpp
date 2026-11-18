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
template <typename T>
inline T abs(T t) {
  return t < 0 ? -t : t;
}
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
const int MAXN = 212345;
int n, m;
long long k;
pair<long long, long long> s[MAXN];
long long p[MAXN], t;
long long test(long long c) {
  long long ans = 0;
  for (int a = 1; a <= m; a++) {
    if (c < (p[a] - p[a - 1])) return LLONG_MAX;
    if (c > 2 * (p[a] - p[a - 1])) {
      ans += p[a] - p[a - 1];
    } else {
      ans +=
          2 * (p[a] - p[a - 1]) - min(p[a] - p[a - 1], (c - (p[a] - p[a - 1])));
    }
  };
  return ans;
}
int main() {
  scanf("%d%d%lld%lld", &n, &m, &k, &t);
  for (int a = 0; a < n; a++) {
    scanf("%lld%lld", &s[a].first, &s[a].second);
  }
  p[0] = 0;
  for (int a = 1; a <= m; a++) {
    scanf("%lld", &p[a]);
  }
  p[m + 1] = k;
  m++;
  sort(p, p + m + 1);
  long long i = 1, j = 5e9;
  while (i < j) {
    long long m = (i + j) / 2ll;
    if (test(m) <= t)
      j = m;
    else
      i = m + 1;
  };
  long long res = LLONG_MAX;
  for (int a = 0; a < n; a++) {
    if (s[a].second >= i && s[a].first < res) {
      res = s[a].first;
    }
  }
  if (res != LLONG_MAX)
    printf("%lld\n", res);
  else
    puts("-1");
}