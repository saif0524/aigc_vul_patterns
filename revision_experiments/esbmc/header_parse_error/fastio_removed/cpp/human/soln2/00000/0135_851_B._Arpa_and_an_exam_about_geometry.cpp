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
const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << "," << p.second << ')';
}
int _runtimeTerror_() {
  long long a[2], b[2], c[2];
  cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
  bool ans = true;
  auto dis = [&](long long x, long long y, long long z, long long w) {
    return (z - x) * (z - x) + (w - y) * (w - y);
  };
  if (dis(a[0], a[1], b[0], b[1]) != dis(b[0], b[1], c[0], c[1])) ans = false;
  if ((c[1] - b[1]) * (b[0] - a[0]) == (b[1] - a[1]) * (c[0] - b[0]))
    ans = false;
  cout << (ans ? "Yes" : "No");
  return 0;
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}