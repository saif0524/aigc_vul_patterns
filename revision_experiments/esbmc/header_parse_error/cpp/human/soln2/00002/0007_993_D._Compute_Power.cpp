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
const int INF = 0x7fffffff;
const int N = 55;
inline int read() {
  int x = 0, rev = 0, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') rev = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return rev ? -x : x;
}
struct data {
  double a, b;
} t[N];
double X, f[N][N][N];
bool vis[N][N][N];
int n;
long long ans;
bool cmp(data i, data j) { return i.a > j.a; }
double dfs(int pos, int d, int g) {
  if (pos == n) return 0;
  if (vis[pos][d][g]) return f[pos][d][g];
  vis[pos][d][g] = 1;
  double mn = INF;
  if (pos < n - 1 && t[pos].a == t[pos + 1].a) {
    if (d) mn = min(mn, dfs(pos + 1, d - 1, g));
    mn = min(mn, dfs(pos + 1, d, g + 1) + t[pos].a - X * t[pos].b);
  } else if (t[pos].a != t[pos + 1].a || pos == n - 1) {
    if (d) mn = min(mn, dfs(pos + 1, d + g - 1, 0));
    mn = min(mn, dfs(pos + 1, d + g + 1, 0) + t[pos].a - X * t[pos].b);
  }
  return f[pos][d][g] = mn;
}
bool judge(double k) {
  X = k, memset(vis, 0, sizeof vis), memset(f, 0, sizeof f);
  return dfs(0, 0, 0) <= 0;
}
int main() {
  n = read();
  for (int i = 0; i < n; i++) t[i].a = read();
  for (int i = 0; i < n; i++) t[i].b = read();
  sort(t, t + n, cmp);
  double l = 0, r = 1e8;
  for (int T = 1; T <= 100; T++) {
    double mid = (l + r) / 2.0;
    if (judge(mid))
      r = mid;
    else
      l = mid;
  }
  ans = (ceil)(l * 1000);
  cout << ans << endl;
}