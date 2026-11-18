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
const int mod1 = 998244353;
const long long inf = 5e18;
long long n, p, w, d;
void solve() {
  cin >> n >> p >> w >> d;
  for (long long draw = 0; draw < w; draw++) {
    long long score = draw * d;
    long long win = (p - score) / w;
    if (win >= 0 && score >= 0 && score + win * w == p && win + draw <= n) {
      cout << win << " " << draw << " " << n - win - draw;
      return;
    }
  }
  cout << -1;
}
int32_t main() {
  ((void)0);
  ((void)0);
  solve();
  return 0;
}