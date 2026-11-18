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
const int maxn = 1e6 + 10, mod = 998244353;
const long long inf = 1e18;
int fac[maxn], ifac[maxn], sm1[maxn], sm2[maxn];
int Pow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
int C(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return 1ll * fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
  ifac[maxn - 1] = Pow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  string s;
  cin >> s;
  int n = int((s).size());
  int cls = 0, qus = 0;
  for (int i = 0; i < int((s).size()); i++) {
    qus += s[i] == '?';
    cls += s[i] == ')';
  }
  for (int i = n; i >= 0; i--) {
    sm1[i] = (sm1[i + 1] + C(qus, i)) % mod;
    sm2[i] = (sm2[i + 1] + C(qus - 1, i)) % mod;
  }
  int ans = 0;
  for (int i = 0; i < int((s).size()); i++) {
    if (s[i] == '?') ans = (ans + sm2[max(0, i + 1 - cls)]) % mod;
    if (s[i] == '(') ans = (ans + sm1[max(0, i + 1 - cls)]) % mod;
  }
  return cout << ans << endl, 0;
}