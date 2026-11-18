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
long long MOD = 1e9 + 7;
int inf = 2e9;
long long INF = 8e18;
int fre[26][5001];
int ts[5001];
int ff[5001];
int fac[5001];
int nf[5001];
string s;
long long fe(long long x, int e) {
  long long r = 1;
  while (e) {
    if (e & 1) r = (r * x) % MOD;
    x = (x * x) % MOD;
    e >>= 1;
  }
  return r;
}
long long ncr(int n, int r) {
  long long re = fac[n];
  re = (re * fe(fac[r], MOD - 2)) % MOD;
  re = (re * fe(fac[n - r], MOD - 2)) % MOD;
  return re;
}
int main() {
  ((void)0);
  ((void)0);
  ;
  fac[0] = 1;
  for (int i = 1; i <= 5000; i++) {
    fac[i] = ((long long)fac[i - 1] * (long long)i) % MOD;
  }
  memset(ff, 0, sizeof ff);
  memset(fre, 0, sizeof fre);
  int n;
  long long ans = 0;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    ts[i] = (int)(s[i] - 'a');
  }
  for (int i = 0; i < n; i++) {
    nf[1] = 1;
    for (int j = 2; j <= n; j++) {
      nf[j] = (ff[j - 1] - fre[ts[i]][j - 1] + MOD) % MOD;
    }
    for (int j = 1; j <= n; j++) {
      ff[j] = (ff[j] - fre[ts[i]][j] + nf[j] + MOD) % MOD;
    }
    for (int j = 1; j <= n; j++) {
      fre[ts[i]][j] = nf[j];
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = (ans + (long long)ff[i] * ncr(n - 1, i - 1)) % MOD;
  }
  cout << ans;
  return 0;
}