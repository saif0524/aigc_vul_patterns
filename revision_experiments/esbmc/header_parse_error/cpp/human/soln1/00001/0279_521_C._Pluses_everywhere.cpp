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
const int MAXN = 100005;
const int mod = 1e9 + 7;
int n, k;
int inv[MAXN];
int a[MAXN];
int pow(int a, int b) {
  long long res = 1, tmp = a;
  while (b) {
    if (b & 1) res = res * tmp % mod;
    tmp = tmp * tmp % mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long sum = 0;
  long long ans = 0;
  long long ten = 1;
  long long c = 1;
  for (int i = (1); i <= (n); ++i) {
    scanf("%1d", &a[i]);
    sum += a[i];
  }
  if (k == 0) {
    for (int i = (1); i <= (n); ++i) ans = (ans * 10 + a[i]) % mod;
    printf("%I64d\n", ans);
    return;
  }
  for (int i = (n - k); i <= (n - 2); ++i) c = c * i % mod;
  for (int i = (1); i <= (k - 1); ++i) c = c * inv[i] % mod;
  for (int i = (0); i < (n - k); ++i) {
    sum = ((sum - a[n - i]) % mod + mod) % mod;
    long long tmpc = c * inv[k] % mod * (n - i - 1) % mod;
    ans = (ans + ten * sum % mod * c) % mod;
    ans = (ans + ten * a[n - i] % mod * tmpc) % mod;
    ten = ten * 10 % mod;
    c = c * (n - k - i - 1) % mod;
    c = c * inv[n - i - 2] % mod;
  }
  printf("%I64d\n", ans);
}
int main() {
  for (int i = (0); i < (MAXN); ++i) inv[i] = pow(i, mod - 2);
  while (~scanf("%d%d", &n, &k)) solve();
  return 0;
}