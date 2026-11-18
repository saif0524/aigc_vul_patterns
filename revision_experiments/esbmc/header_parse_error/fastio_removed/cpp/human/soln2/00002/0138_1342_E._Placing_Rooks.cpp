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
const int mod = 998244353;
const int N = 1e6 + 10;
int n, k, f[N];
int add(int x, int y) {
  if (x + y >= mod) {
    return x + y - mod;
  }
  return x + y;
}
int sub(int x, int y) {
  if (x - y < 0) {
    return x - y + mod;
  }
  return x - y;
}
int mul(int x, int y) { return (long long)x * y % mod; }
int exp(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) {
      ans = mul(ans, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
int inv(int x) { return exp(x, mod - 2); }
void fact() {
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = mul(f[i - 1], i);
  }
}
int choose(int x, int y) { return mul(f[x], inv(mul(f[x - y], f[y]))); }
int main() {
  ((void)0);
  ((void)0);
  fact();
  cin >> n >> k;
  if (k >= n) {
    cout << 0 << '\n';
    return 0;
  }
  int c = n - k;
  int ncc = choose(n, c);
  int ways = 0;
  for (int i = 0; i <= c; i++) {
    if (i % 2) {
      ways = sub(ways, mul(choose(c, i), exp(c - i, n)));
    } else {
      ways = add(ways, mul(choose(c, i), exp(c - i, n)));
    }
  }
  int ans = mul(ways, ncc);
  if (k != 0) {
    ans = mul(ans, 2);
  }
  cout << ans << '\n';
  return 0;
}