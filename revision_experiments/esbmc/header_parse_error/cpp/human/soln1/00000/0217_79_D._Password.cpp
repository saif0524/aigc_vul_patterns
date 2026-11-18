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
int n, k, m, x, s, p[10005], c[105], y[30][30], d[10005], q[10005], f, r,
    g[1100005];
bool a[10005];
void work(int x, int y) {
  if (x > 0 && x <= n && y < d[x]) {
    d[x] = y;
    q[++r] = x;
  }
}
void bfs(int x) {
  int i;
  memset(d, 1, sizeof(d));
  d[x] = 0;
  f = 0;
  r = 0;
  for (q[0] = x; f <= r; f++) {
    for (i = 1; i <= m; i++) {
      work(q[f] + c[i], d[q[f]] + 1);
      work(q[f] - c[i], d[q[f]] + 1);
    }
  }
  for (i = 1; i <= n; i++) {
    if (a[i]) y[p[x]][p[i]] = d[i];
  }
}
int main() {
  int i, j, l;
  scanf("%d%d%d", &n, &k, &m);
  n++;
  for (i = 1; i <= k; i++) {
    scanf("%d", &x);
    a[x] = 1;
  }
  for (i = 1; i <= m; i++) scanf("%d", &c[i]);
  for (i = n; i >= 1; i--) {
    if (a[i] ^= a[i - 1]) p[i] = ++s;
  }
  for (i = 1; i <= n; i++) {
    if (a[i]) bfs(i);
  }
  memset(g, 80, sizeof(g));
  g[0] = 0;
  for (i = 1; i <= (1 << s) - 1; i++) {
    for (j = 1; j <= s; j++) {
      if (i & (1 << j - 1)) {
        for (l = j + 1; l <= s; l++) {
          if (i & (1 << l - 1))
            g[i] = min(g[i], g[i ^ (1 << j - 1) ^ (1 << l - 1)] + y[j][l]);
        }
        break;
      }
    }
  }
  if (g[(1 << s) - 1] > 1 << 20)
    puts("-1");
  else
    printf("%d\n", g[(1 << s) - 1]);
  return 0;
}