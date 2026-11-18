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
template <class A, class B>
A cvt(B x) {
  stringstream ss;
  ss << x;
  A y;
  ss >> y;
  return y;
}
int n, a, b, t;
string s;
int solve() {
  int tb = 0;
  vector<int> tm;
  for (int k = n; k >= 1; k--) {
    tb += a;
    if (s[k - 1] != 'h') tb += b;
    tb += 1;
    tm.push_back(tb);
  }
  int best = 0;
  int t1 = 0;
  for (int k = 1; k <= n; k++) {
    if (k != 1) t1 += a;
    if (s[k - 1] != 'h') t1 += b;
    t1 += 1;
    if (t1 > t) break;
    int t2 = t - t1 - (k - 1) * a;
    int l = lower_bound(tm.begin(), tm.end(), t2 + 1) - tm.begin();
    best = max(best, min(k + l, n));
  }
  return best;
}
int main() {
  cin >> n >> a >> b >> t >> s;
  int s1 = solve();
  reverse(s.begin() + 1, s.end());
  int s2 = solve();
  cout << max(s1, s2) << endl;
  return 0;
}