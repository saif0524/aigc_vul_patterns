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
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
const int N = 510;
long long f[10][N][N], g[10][N][N];
long long h[N][N], H[N][N];
int main() {
  int n = gi(), m = gi(), i, j, k, a, b, t, ans;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) f[0][i][j] = -1LL << 60;
  while (m--) {
    a = gi(), b = gi();
    f[0][a][b] = max(f[0][a][b], (long long)gi());
    f[0][b][a] = max(f[0][b][a], (long long)gi());
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) g[0][i][j] = f[0][i][j];
  for (t = 1; t < 10; t++) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) {
        g[t][i][j] = -1LL << 60;
        f[t][i][j] = f[t - 1][i][j];
        for (k = 1; k <= n; k++) {
          g[t][i][j] = max(g[t][i][j], g[t - 1][i][k] + g[t - 1][k][j]);
          f[t][i][j] = max(f[t][i][j], g[t - 1][i][k] + f[t - 1][k][j]);
        }
      }
    for (i = 1; i <= n; i++)
      if (f[t][i][i] > 0) break;
    if (i <= n) break;
  }
  if (t == 10) return puts("0"), 0;
  for (i = 1, ans = 1 << (--t); i <= n; i++)
    for (j = 1; j <= n; j++) h[i][j] = g[t][i][j];
  while (--t >= 0) {
    for (i = 1; i <= n; i++) {
      for (k = 1; k <= n; k++)
        if (h[i][k] + f[t][k][i] > 0) break;
      if (k <= n) break;
    }
    if (i > n) {
      ans |= 1 << t;
      for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
          H[i][j] = -1LL << 60;
          for (k = 1; k <= n; k++) H[i][j] = max(H[i][j], h[i][k] + g[t][k][j]);
        }
      for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) h[i][j] = H[i][j];
    }
  }
  printf("%d\n", ans + 1);
  return 0;
}