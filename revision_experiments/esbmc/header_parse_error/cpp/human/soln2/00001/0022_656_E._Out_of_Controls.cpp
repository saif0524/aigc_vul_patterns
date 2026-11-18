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
int n;
int d[12][12];
int ans = 0;
int r(int c) { return (c == n * n ? -1 : (cin >> d[c / n][c % n], r(c + 1))); }
int f(int c) {
  int k = c / (n * n);
  int i = (c % (n * n)) / n;
  int j = (c % (n * n)) % n;
  return (c == n * n * n
              ? 1
              : (d[i][j] = min(d[i][j], d[i][k] + d[k][j]), f(c + 1)));
}
int g(int c) {
  return (c == n * n ? -1 : (ans = max(ans, d[c / n][c % n]), g(c + 1)));
}
int main() {
  cin >> n;
  r(0);
  f(0);
  g(0);
  cout << ans << endl;
  return 0;
}