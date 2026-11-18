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
void solve() {
  int n, INF = 1e9, ans = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  for (int i = 30; i > 0; i--) {
    vector<int> b(n);
    for (int j = 0; j < (n); j++) {
      if (a[j] <= i)
        b[j] = a[j];
      else
        b[j] = -INF;
    }
    int mx = 0, cur = 0;
    for (int j = 0; j < (n); j++) {
      if (cur + b[j] > b[j])
        cur += b[j];
      else
        cur = b[j];
      mx = max(mx, cur);
    }
    ans = max(ans, mx - i);
  }
  cout << ans << '\n';
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cout.precision(12);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}