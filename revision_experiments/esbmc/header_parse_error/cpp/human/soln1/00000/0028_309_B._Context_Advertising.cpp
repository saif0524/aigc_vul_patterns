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
const int N = 1000100, L = 5000500, BufL = 220;
char ch[N + L] = {}, buf[BufL] = {};
int n, r, c, l, a[N] = {}, p[N] = {}, f[N] = {}, g[N] = {};
int main() {
  gets(buf + 1);
  sscanf(buf + 1, "%d%d%d", &n, &r, &c);
  gets(ch + 1);
  l = strlen(ch + 1);
  for (int i = 1, tot = 0; i <= l; ++i)
    if (isalpha(ch[i])) {
      p[++tot] = i;
      while (i <= l && isalpha(ch[i])) ++a[tot], ++i;
    }
  for (int i = 1; i <= n + 1; ++i) g[i] = i;
  for (int i = 1, t = 0, s = -1; i <= n; s -= a[i++] + 1) {
    while (t <= n && s <= c) s += a[++t] + 1;
    f[i] = t;
  }
  f[n + 1] = n + 1;
  for (; r; r >>= 1) {
    if (r & 1)
      for (int i = 1; i <= n; ++i) g[i] = f[g[i]];
    for (int i = 1; i <= n; ++i) f[i] = f[f[i]];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (g[i] - i > g[ans] - ans) ans = i;
  for (int i = ans, s = c; i < g[ans]; ++i) {
    if (s + a[i] + 1 <= c) {
      s += a[i] + 1;
      putchar(' ');
    } else {
      if (i > ans) puts("");
      s = a[i];
    }
    for (int j = p[i]; j < p[i] + a[i]; ++j) putchar(ch[j]);
  }
  return 0;
}