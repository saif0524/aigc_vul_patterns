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
int const mod = 1e9 + 7;
int const maxn = 2005;
inline void safe_mul(int& a, int b) { a = (a * 1LL * b) % mod; }
inline int mypow(int a, int b) {
  int ans = 1;
  int tmp = a;
  while (b) {
    if (b & 1) safe_mul(ans, tmp);
    safe_mul(tmp, tmp);
    b >>= 1;
  }
  return ans;
}
inline int inv(int x) { return mypow(x, mod - 2); }
int koef[maxn];
int a[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  koef[0] = 1;
  for (int i = 1; i < n; ++i) {
    koef[i] = koef[i - 1];
    safe_mul(koef[i], (k + i - 1) * 1LL * inv(i) % mod);
  }
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    int ans = 0;
    for (int j = 0; j <= i; ++j) ans = (ans + koef[j] * 1LL * a[i - j]) % mod;
    cout << ans << " \n"[i == n - 1];
  }
  return 0;
}