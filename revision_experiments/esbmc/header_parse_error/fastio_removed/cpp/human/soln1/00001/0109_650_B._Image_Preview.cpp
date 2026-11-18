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
  long long n, k, b, t;
  cin >> n >> k >> b >> t;
  string s;
  cin >> s;
  long long sum = 0;
  long long a[2 * n + (long long)10];
  for (long long i = 0; i < n; i++) {
    a[i] = a[i + n] = ((s[i] == 'w') ? (b + 1) : 1);
    sum += a[i];
  }
  sum -= a[0];
  long long l = 1, r = n;
  long long ans = 0;
  while ((l <= n) && (r < 2 * n)) {
    sum += a[r];
    r++;
    while ((r - l) > n || (sum + (r - l - 1 + min(r - n - 1, n - l)) * k) > t)
      sum -= a[l++];
    ans = max(ans, r - l);
  }
  cout << ans;
}
signed main() {
  ((void)0);
  ((void)0);
  ((void)0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}