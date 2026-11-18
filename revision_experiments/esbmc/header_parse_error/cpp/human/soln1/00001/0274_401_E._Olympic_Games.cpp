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
long long num[100005], d[100005][6];
long long n, m, l, r, p;
long long cal(long long ql, long long qh, long long mm) {
  qh /= mm;
  ql = (ql + mm - 1) / mm;
  return ((qh - ql + 1) * (n + 1) -
          mm * ((qh * (qh + 1) - ql * (ql - 1)) / 2)) %
         p;
}
int main() {
  long long ans = 0;
  cin >> n >> m >> l >> r >> p;
  for (int i = 2; i <= m; ++i)
    if (num[i] == 0)
      for (int j = i; j <= m; j += i) d[j][num[j]++] = i;
  long long lo = l, hi = r;
  long long mmin = min(m, r);
  for (long long w = 1; w <= mmin; ++w) {
    while (lo > 1 && l * l - w * w <= (lo - 1) * (lo - 1)) --lo;
    while (r * r - w * w < hi * hi) --hi;
    if (lo <= hi && lo <= n) {
      long long t = (1 << num[w]);
      long long a = 0;
      for (long long i = 0; i < t; ++i) {
        long long ii = i;
        long long p1 = 1;
        long long p2 = 1;
        for (int j = 0; j < num[w]; ++j) {
          if (ii & 1) {
            p1 *= d[w][j];
            p2 *= -1;
          }
          ii >>= 1;
        }
        a += p2 * cal(lo, hi < n ? hi : n, p1);
      }
      ans = (ans + (m - w + 1) * a) % p;
      if (ans < 0) ans += p;
    }
  }
  if (l <= 1 && r >= 1)
    ans = (ans * 2 + n * (m + 1) + m * (n + 1)) % p;
  else
    ans = (ans * 2) % p;
  cout << ans << endl;
  return 0;
}