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
const long long maxn = (long long)3e5 + 7;
long long a[maxn];
long long b[maxn];
long long pos[maxn];
struct node {
  long long x, y;
} ans[maxn * 5];
signed main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    pos[a[i]] = i;
  }
  long long cnt = 0;
  for (long long i = 1; i <= n / 2; i++) {
    if (pos[i] == i) continue;
    if (i == 1) {
      if (pos[1] > n / 2) {
        ans[++cnt] = {1, pos[1]};
        long long temp = pos[1];
        swap(pos[a[1]], pos[1]);
        swap(a[temp], a[1]);
      } else {
        ans[++cnt] = {1, n};
        ans[++cnt] = {pos[1], n};
        ans[++cnt] = {1, n};
        long long temp = pos[1];
        swap(pos[a[1]], pos[1]);
        swap(a[temp], a[1]);
      }
      continue;
    }
    if (abs(pos[i] - i) >= n / 2) {
      ans[++cnt] = {i, pos[i]};
      long long temp = pos[i];
      swap(pos[a[i]], pos[i]);
      swap(a[temp], a[i]);
    } else if (pos[i] <= n / 2) {
      long long temp = pos[i];
      ans[++cnt] = {i, n};
      ans[++cnt] = {pos[i], n};
      ans[++cnt] = {i, n};
      swap(pos[a[i]], pos[i]);
      swap(a[temp], a[i]);
    } else {
      ans[++cnt] = {pos[i], 1};
      ans[++cnt] = {i, n};
      ans[++cnt] = {1, n};
      ans[++cnt] = {i, n};
      ans[++cnt] = {pos[i], 1};
      long long temp = pos[i];
      swap(pos[a[i]], pos[i]);
      swap(a[temp], a[i]);
    }
  }
  for (long long i = n / 2 + 1; i <= n; i++) {
    if (pos[i] == i) continue;
    ans[++cnt] = {i, 1};
    ans[++cnt] = {pos[i], 1};
    ans[++cnt] = {i, 1};
    long long temp = pos[i];
    swap(pos[a[i]], pos[i]);
    swap(a[temp], a[i]);
  }
  cout << cnt << endl;
  for (long long i = 1; i <= cnt; i++) {
    cout << ans[i].x << " " << ans[i].y << endl;
  }
  return 0;
}