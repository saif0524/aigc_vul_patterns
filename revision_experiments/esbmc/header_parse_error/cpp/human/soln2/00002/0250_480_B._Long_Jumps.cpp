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
map<long long, bool> m;
int n, l;
long long x, y;
int s = -1;
int main() {
  ios::sync_with_stdio(false);
  bool f1 = false, f2 = false;
  cin >> n >> l >> x >> y;
  for (int i = 1; i <= n; i++) {
    long long t;
    cin >> t;
    m[t] = true;
    if (t - x >= 0)
      if (m[t - x]) f1 = true;
    if (t - y >= 0)
      if (m[t - y]) f2 = true;
    if (t >= y && t - y + x >= 0 && m[t - y + x]) {
      s = t - y;
    }
    if (t < y && t - y + x >= 0 && m[t - y + x]) {
      if (t + x <= l) s = t + x;
    }
    if (t >= x + y && m[t - x - y]) s = t - x;
    if (m[x]) f1 = true;
    if (m[y]) f2 = true;
  }
  int res = (!f1) + (!f2);
  if (res == 2) {
    if (s != -1) {
      cout << 1 << endl;
      cout << s << " ";
      return 0;
    }
  }
  cout << res << endl;
  if (!f1) cout << x << " ";
  if (!f2) cout << y << " ";
  return 0;
}