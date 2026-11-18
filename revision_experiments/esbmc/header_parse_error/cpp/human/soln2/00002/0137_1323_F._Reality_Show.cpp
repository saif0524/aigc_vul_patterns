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
template <typename T>
void read(T& x) {
  x = 0;
  int fl = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fl = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  x *= fl;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const int N = 2005;
const int INF = 1e9;
int n, m, l[N], s[N], c[N << 1];
int dp[N << 1][N], ans = -INF;
int main() {
  read(n, m);
  for (int i = n; i >= 1; i--) read(l[i]);
  for (int i = n; i >= 1; i--) read(s[i]);
  for (int i = 1; i <= n + m; i++) read(c[i]);
  memset(dp, -0x7f, sizeof dp);
  for (int i = 1; i <= n + m; i++) dp[i][0] = 0;
  for (int i = 1; i <= n; i++) {
    int pos = l[i];
    for (int j = i; j >= 1; j--)
      dp[pos][j] = max(dp[pos][j], dp[pos][j - 1] + c[l[i]] - s[i]);
    for (int k = pos + 1, t = i / 2; k <= n + m; k++, t >>= 1) {
      for (int j = t; j >= 0; j--) {
        dp[k][j] = max(dp[k][j], dp[k - 1][j << 1] + j * c[k]);
        dp[k][j] = max(dp[k][j], dp[k - 1][j << 1 | 1] + j * c[k]);
      }
    }
  }
  for (int i = 1; i <= n + m; i++) ans = max(ans, max(dp[i][0], dp[i][1]));
  printf("%d\n", ans);
  return 0;
}