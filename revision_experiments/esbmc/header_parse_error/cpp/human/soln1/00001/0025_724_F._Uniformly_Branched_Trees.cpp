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
int fac[1010], inv[1010], mod;
int ksm(int a, int b = mod - 2) {
  int r = 1;
  for (; b; b >>= 1) {
    if (b & 1) r = 1ll * r * a % mod;
    a = 1ll * a * a % mod;
  }
  return r;
}
int C(int a, int b) {
  int r = inv[b];
  for (b--; b >= 0; b--) r = 1ll * r * (a - b) % mod;
  return r;
}
int f[1010][12][1010];
int main() {
  int n, d;
  scanf("%d%d%d", &n, &d, &mod);
  if (n <= 2) {
    puts("1");
    return 0;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[n] = ksm(fac[n]);
  for (int i = n - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  for (int i = 0; i <= n; i++) f[1][0][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= min(d, i - 1); j++)
      for (int k = 1; k <= n; k++) {
        f[i][j][k] = f[i][j][k - 1];
        for (int t = 1; t * k <= i && t <= j; t++)
          f[i][j][k] =
              (f[i][j][k] +
               1ll * f[i - t * k][j - t][k - 1] *
                   (C(f[k][k == 1 ? 0 : d - 1][k - 1] + t - 1, t)) % mod) %
              mod;
      }
  printf("%d\n", (f[n][d][n / 2] -
                  ((n & 1) ? 0 : C(f[n / 2][d - 1][n / 2 - 1], 2)) + mod) %
                     mod);
  return 0;
}