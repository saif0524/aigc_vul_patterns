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
const int N = 1005;
long long fact[N], inv[N], finv[N];

void init() {
  fact[0] = inv[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  }
  for (int i = 2; i < N; i++) {
    finv[i] = finv[i - 1] * inv[i] % mod;
    fact[i] = fact[i - 1] * i % mod;
  }
}

long long comb(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
  ((void)0);
  ((void)0);
  init();
  int k;
  cin >> k;
  vector<int> c(k);
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  long long ans = 1;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    ans = ans * comb(sum + c[i] - 1, c[i] - 1) % mod;
    sum += c[i];
  }
  cout << ans << endl;
  return 0;
}