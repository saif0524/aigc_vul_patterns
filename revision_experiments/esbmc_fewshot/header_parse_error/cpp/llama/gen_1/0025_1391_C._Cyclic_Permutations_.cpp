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
const int mod = 1e9 + 7;
long long fact[1000005];
long long invfact[1000005];
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long modInverse(long long n) {
  return power(n, mod - 2);
}
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fact[n] * invfact[r] % mod * invfact[n - r] % mod) % mod;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < 1000005; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  invfact[1000004] = modInverse(fact[1000004]);
  for (int i = 1000003; i >= 0; i--) {
    invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
  }
  int n;
  cin >> n;
  long long ans = fact[n];
  for (int i = 1; i <= n; i++) {
    ans = (ans - (nCr(n, i) * fact[i] % mod * fact[n - i] % mod)) % mod;
    if (ans < 0) ans += mod;
  }
  cout << ans << endl;
  return 0;
}