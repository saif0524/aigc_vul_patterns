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
const int maxn = 4010;
const int mod = 1e9 + 9;
int n, w, b;
int num[maxn * 2], inv[maxn * 2];
int pp(int a, int b) {
  if (!b) return 1;
  int cnt = pp(a, b / 2);
  cnt = 1ll * cnt * cnt % mod;
  if (b & 1) cnt = 1ll * cnt * a % mod;
  return cnt;
}
int calc(int n, int m) {
  if (n < m) return 0;
  return 1ll * num[n] * num[n - 1] % mod * inv[m - 1] % mod * inv[n - m] % mod;
}
int main() {
  cin >> n >> w >> b;
  num[0] = 1;
  for (int i = 1; i <= w + b; ++i) num[i] = 1ll * num[i - 1] * i % mod;
  inv[w + b] = pp(num[w + b], mod - 2);
  for (int i = w + b - 1; i >= 0; --i)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    int cur = n - i - 1;
    cur = 1ll * cur * calc(w, n - i) % mod * calc(b, i) % mod;
    (ans += cur) %= mod;
  }
  cout << ans << endl;
  return 0;
}