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
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct s {
  int a, b, c;
  bool operator<(const s& rhs) const {
    return a > rhs.a || (a == rhs.a && b > rhs.b) ||
           (a == rhs.a && b == rhs.b && c > rhs.c);
  }
};
s e[500050], tmp[500050];
int all, mp[500050];
int tot;
int n;
int c[500050];
void ud(int x, int v) {
  x = tot - x + 1;
  for (; x <= tot; x += x & -x) c[x] = max(c[x], v);
}
int query(int l, int r) {
  int x = tot - l + 1;
  int ret = -(0x3f3f3f3f);
  for (; x; x -= x & -x) ret = max(ret, c[x]);
  return ret;
}
void init() {}
int main() {
  cin >> n;
  for (int i = (1); i <= (int)(n); i++) {
    e[i].a = read();
  }
  for (int i = (1); i <= (int)(n); i++) e[i].b = mp[i] = read();
  for (int i = (1); i <= (int)(n); i++) e[i].c = read();
  sort(mp + 1, mp + n + 1);
  tot = unique(mp + 1, mp + n + 1) - (mp + 1);
  for (int i = (1); i <= (int)(n); i++)
    e[i].b = lower_bound(mp + 1, mp + tot + 1, e[i].b) - mp;
  sort(e + 1, e + n + 1);
  int i = 1, ans = 0;
  while (i <= n) {
    int j = i;
    while (j <= n && e[j].a == e[i].a) {
      if (e[j].b + 1 <= tot && query(e[j].b + 1, tot) > e[j].c) {
        ans++;
      }
      j++;
    }
    int k = j - 1;
    while (k >= i) ud(e[k].b, e[k].c), k--;
    i = j;
  }
  cout << ans << endl;
  return 0;
}