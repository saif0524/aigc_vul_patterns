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
long long v[1000001], p[1000001], mp[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k, x;
  cin >> n >> m >> k;
  for (long long i = 0; i < m; i++) {
    cin >> x;
    if (x == 0) {
      cout << -1;
      return 0;
    }
    mp[x] = 1;
  }
  for (long long i = 0; i < k; i++) {
    cin >> v[i];
  }
  for (long long i = 0; i < n; i++) {
    if (!mp[i])
      p[i] = i;
    else
      p[i] = p[i - 1];
  }
  long long ans = LLONG_MAX;
  for (long long i = 1; i <= k; i++) {
    long long val = 0;
    long long j = 0, first = 1;
    while (j < n) {
      val += v[i - 1];
      if (j + i >= n) break;
      long long nj = p[j + i];
      if (nj == j) {
        first = 0;
        break;
      }
      j = nj;
    }
    if (first) ans = min(ans, val);
  }
  if (ans == LLONG_MAX) ans = -1;
  cout << ans;
  return 0;
}