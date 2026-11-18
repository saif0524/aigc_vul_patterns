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
const int N = 2e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
long long QPow(long long bas, int t) {
  long long ret = 1;
  bas %= MOD;
  while (t) {
    if (t & 1) ret = ret * bas % MOD;
    bas = bas * bas % MOD;
    t >>= 1;
  }
  return ret;
}
long long Inv(long long x) { return QPow(x, MOD - 2); }
long long fac[N], ifac[N];
void Init() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    ifac[i] = Inv(fac[i]);
  }
}
long long C(int n, int a) {
  if (n < 0 || a < 0 || n - a < 0)
    return 0;
  else
    return fac[n] * ifac[a] % MOD * ifac[n - a] % MOD;
}
int main() {
  ios::sync_with_stdio(0);
  Init();
  int n, k;
  cin >> n >> k;
  int l = n - k;
  if (l < 0) {
    cout << 0 << endl;
    return 0;
  }
  if (k == 0) {
    cout << fac[n] << endl;
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i <= l; i++) {
    long long tmp = QPow(-1, i) * C(l, i) % MOD * QPow(l - i, n);
    ans = (ans + tmp) % MOD;
  }
  ans = 2LL * ans * C(n, l) % MOD;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
  return 0;
}