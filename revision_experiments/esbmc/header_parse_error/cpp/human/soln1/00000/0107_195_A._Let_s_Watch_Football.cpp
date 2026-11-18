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
#pragma comment(linker, "/STACK:64000000")
using namespace std;
inline int gcd(int a, int b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  };
  return (a > b) ? gcd(a - b, b) : a;
}
inline int abs(int x) { return x > 0 ? x : -x; }
void solve() {
  int a, b, c, t, all;
  bool fin = false;
  cin >> a >> b >> c;
  if (b >= a) {
    cout << 0;
    return;
  }
  t = 0;
  all = (c * a + b - 1) / b;
  while (++t)
    if (all * b >= (all - t) * a) break;
  cout << t;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}