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
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
template <typename T1, typename T2>
bool relax(T1& a, const T2& b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
bool strain(T1& a, const T2& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
void solve() {
  int n, r;
  cin >> n >> r;
  int pw = 1 << n;
  ld res = 0;
  vector<int> a(pw);
  for (int i = 0; i < pw; ++i) cin >> a[i], res += (ld)a[i] / pw;
  cout.precision(10);
  cout << fixed << res << '\n';
  for (int i = 0; i < r; ++i) {
    int x, y;
    cin >> x >> y;
    res -= (ld)a[x] / pw;
    res += (ld)y / pw;
    a[x] = y;
    cout << res << '\n';
  }
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  srand(time(0));
  int t = 1;
  while (t--) solve();
  return 0;
}