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
#pragma warning(disable : 4996)
const int kMaxn = 100010;
int n, m, a[kMaxn], g[kMaxn], h[kMaxn];
int main() {
  static int i, j, k, x, now, ans;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  m = 0;
  memset(g, 0, sizeof(g));
  memset(h, 0, sizeof(h));
  for (i = 1; i <= n; ++i) {
    if (!g[i]) {
      if (g[a[i]]) {
        g[i] = g[a[i]];
      } else {
        g[i] = g[a[i]] = ++m;
        h[m] = a[i];
      }
    }
  }
  ans = 0;
  for (i = 1; i <= n; ++i)
    if (h[g[i]] != a[i]) ans = -1;
  for (i = 1; i <= m; ++i)
    if (g[h[i]] != i) ans = -1;
  if (ans == -1) {
    puts("-1");
    return 0;
  }
  printf("%d\n", m);
  for (i = 1; i <= n; ++i) printf("%d ", g[i]);
  puts("");
  for (i = 1; i <= m; ++i) printf("%d ", h[i]);
  return 0;
}