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
const int N = 300005;
struct edge {
  int to, next;
} e[N << 1];
int h[N], xb, dfn[N], low[N], n, m, i, j, x, y, w, stx[N], sty[N], ste[N];
vector<int> ans;
bool b[N], cant[N];
inline void addedge(int x, int y) {
  e[++xb] = (edge){y, h[x]};
  h[x] = xb;
  e[++xb] = (edge){x, h[y]};
  h[y] = xb;
}
void dfs(int x, int fa) {
  dfn[x] = low[x] = ++xb;
  int i = h[x], j;
  for (; i; i = e[i].next)
    if (e[i].to != fa) {
      if (!dfn[e[i].to]) {
        stx[++w] = x, sty[w] = e[i].to;
        ste[w] = i;
        dfs(e[i].to, x);
        if (low[e[i].to] < low[x]) low[x] = low[e[i].to];
        if (low[e[i].to] >= dfn[x]) {
          int cnt = 0, ow = w;
          for (; stx[w] != x || sty[w] != e[i].to; --w) {
            if (!b[stx[w]]) ++cnt, b[stx[w]] = 1;
            if (!b[sty[w]]) ++cnt, b[sty[w]] = 1;
          }
          if (!b[stx[w]]) ++cnt, b[stx[w]] = 1;
          if (!b[sty[w]]) ++cnt, b[sty[w]] = 1;
          if (ow - w + 1 > cnt || cnt == 2) {
            for (j = w; j <= ow; ++j) cant[ste[j] >> 1] = 1;
          }
          for (j = w; j <= ow; ++j) b[stx[j]] = b[sty[j]] = 0;
          --w;
        }
      } else {
        if (dfn[e[i].to] < dfn[x]) stx[++w] = x, sty[w] = e[i].to, ste[w] = i;
        if (dfn[e[i].to] < low[x]) low[x] = dfn[e[i].to];
      }
    }
}
int main() {
  cin >> n >> m;
  xb = 1;
  for (i = 1; i <= m; ++i) {
    cin >> x >> y;
    addedge(x, y);
  }
  xb = 0;
  for (i = 1; i <= n; ++i)
    if (!dfn[i]) dfs(i, 0);
  for (i = 1; i <= m; ++i)
    if (!cant[i]) ans.push_back(i);
  cout << ans.size() << '\n';
  for (i = 0; i < int(ans.size()); ++i) cout << ans[i] << ' ';
  return 0;
}