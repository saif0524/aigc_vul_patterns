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
using ll = long long;
using VI = vector<int>;
using PII = pair<int, int>;
const ll mod = 1e9 + 7;
ll pow(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void fastio() {
  ((void)0);
  ((void)0);
  ((void)0);
}
const int N = 1e5 + 10;
void solve() {
  int n;
  cin >> n;
  vector<int> c = vector<int>(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int all = (1 << n) - 1;
  bool ok = false;
  for (int i = 0; i < all; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) {
      if ((1 << j) & i) {
        s += c[j];
      } else
        s -= c[j];
    }
    if (s % 360 == 0) {
      ok = true;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}
int main() {
  fastio();
  solve();
}