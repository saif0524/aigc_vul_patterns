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
const int M = 998244353, mod = 998244353;
const int N = 1 << 20;
long long a[N], b[N];
long long inv2 = (M + 1) / 2;
int n, i, m, j, s;
char c[25][100005];
void fwt(long long *f, int rev) {
  for (int i = 1; i < (1 << n); i <<= 1) {
    for (int p = i << 1, j = 0; j < (1 << n); j += p) {
      for (int k = 0; k < i; k++) {
        long long x = f[j + k], y = f[i + j + k];
        if (rev == 1) {
          f[j + k] = (x + y) % mod;
          f[i + j + k] = (x - y + mod) % mod;
        } else {
          f[j + k] = 1ll * inv2 * (x + y) % mod;
          f[i + j + k] = 1ll * inv2 * (x - y + mod) % mod;
        }
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%s", c[i] + 1);
  for (i = 1; i <= m; ++i) {
    s = 0;
    for (j = 1; j <= n; ++j) s |= ((int)(c[j][i] - '0') << j - 1);
    ++a[s];
  }
  for (i = 0; i < (1 << n); ++i) {
    int s = __builtin_popcount(i);
    b[i] = min(s, n - s);
  }
  fwt(a, 1);
  fwt(b, 1);
  for (i = 0; i < (1 << n); ++i) a[i] = a[i] * b[i] % M;
  fwt(a, -1);
  long long ans = 10101010101ll;
  for (i = 0; i < (1 << n); ++i) ans = min(ans, a[i]);
  cout << ans;
}