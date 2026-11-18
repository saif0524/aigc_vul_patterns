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
const int N = 1005;
inline int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    ch = getchar();
    if (ch == '-') w = -1;
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * w;
}
int n, m, tot, s[N], Ans;
int a[N], w[N], ans[N];
bool vis[N];
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) w[i] = read();
  for (int i = 1; i <= m; ++i) {
    a[i] = read();
    memset(vis, 0, sizeof(vis));
    for (int j = i - 1; j; --j) {
      if (a[i] == a[j]) break;
      if (vis[a[j]]) continue;
      vis[a[j]] = 1;
      Ans += w[a[j]];
    }
  }
  printf("%d\n", Ans);
  return 0;
}