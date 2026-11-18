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
typedef long long ll;
const int N = 1e5 + 5;
ll fac[N], inv[N], invfac[N];
ll qpow(ll a, ll b, ll mod) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll C(ll n, ll m, ll mod) {
  if (n < m) return 0;
  return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
ll f[N][20];
ll g[N][20];
ll mod;
ll dfs(ll l, ll r, ll k) {
  if (l >= r) return 0;
  if (k == 1) return (r - l) * (r - l - 1) / 2;
  if (f[l][k] != -1) return f[l][k];
  ll res = 0;
  for (ll i = l; i < r; i++) {
    res = (res + dfs(l, i, k - 1) + dfs(i + 1, r, k - 1) +
           C(r - l, i - l + 1, mod) * (i - l) * (r - i - 1)) %
          mod;
  }
  return f[l][k] = res;
}
int main() {
  ll n, k;
  cin >> n >> k >> mod;
  fac[0] = inv[1] = invfac[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }
  memset(f, -1, sizeof(f));
  cout << dfs(0, n, k) << endl;
  return 0;
}