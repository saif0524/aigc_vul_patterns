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
const long long N = 2e5 + 5;
stack<pair<long long, long long> > q;
long long n, a[N], go[N];
struct cell {
  long long max_l, max_r, or_l, or_r;
};
bool d[N][35];
cell b[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    long long q = a[i], k = 1;
    while (q != 0) {
      d[i][k] = q % 2;
      q /= 2;
      k++;
    }
  }
  q.push({0, 2e9});
  for (long long i = 1; i <= n; i++) {
    while (q.top().second <= a[i]) q.pop();
    b[i].max_l = q.top().first;
    q.push({i, a[i]});
  }
  while (!q.empty()) q.pop();
  q.push({n + 1, 2e9});
  for (long long i = n; i > 0; i--) {
    while (q.top().second < a[i]) q.pop();
    b[i].max_r = q.top().first;
    q.push({i, a[i]});
  }
  while (!q.empty()) q.pop();
  for (long long i = 1; i <= n; i++) {
    long long k = 0;
    for (long long j = 1; j < 35; j++)
      if (d[i][j] == 0)
        k = max(k, go[j]);
      else
        go[j] = i;
    b[i].or_l = k;
  }
  for (long long i = 1; i < 35; i++) go[i] = n + 1;
  for (long long i = n; i > 0; i--) {
    long long k = n + 1;
    for (long long j = 1; j < 35; j++)
      if (d[i][j] == 0)
        k = min(k, go[j]);
      else
        go[j] = i;
    b[i].or_r = k;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (b[i].max_l >= b[i].or_l)
      if (b[i].max_r <= b[i].or_r)
        continue;
      else
        ans += (i - b[i].max_l) * (b[i].max_r - b[i].or_r);
    else if (b[i].max_r <= b[i].or_r)
      ans += (b[i].or_l - b[i].max_l) * (b[i].max_r - i);
    else {
      ans += (b[i].or_l - b[i].max_l) * (b[i].or_r - i);
      ans += (b[i].max_r - b[i].or_r) * (i - b[i].or_l);
      ans += (b[i].or_l - b[i].max_l) * (b[i].max_r - b[i].or_r);
    }
  }
  cout << ans;
  return 0;
}