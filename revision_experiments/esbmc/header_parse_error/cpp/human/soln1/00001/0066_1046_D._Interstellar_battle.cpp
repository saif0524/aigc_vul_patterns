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
int n, m;
int x, y;
double a[100005];
struct Edge {
  int v;
  Edge *next;
} * h[100005], pool[100005 << 1];
int tot;
void addEdge(int u, int v) {
  Edge *p = &pool[tot++];
  p->v = v;
  p->next = h[u];
  h[u] = p;
}
double ans;
int um;
double r;
int fa[100005];
double son[100005];
void dfs(int u, int father) {
  fa[u] = father;
  ans += (1 - a[u]) * a[fa[u]];
  for (Edge *p = h[u]; p; p = p->next)
    if (p->v != father) {
      dfs(p->v, u);
      son[u] += (1 - a[p->v]);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d", &x, &y);
    x++;
    y++;
    addEdge(x, y);
    addEdge(y, x);
  }
  a[0] = 1;
  scanf("%d", &m);
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    scanf("%d%lf", &um, &r);
    um++;
    ans += a[fa[um]] * (-(r - a[um]));
    ans += son[um] * (r - a[um]);
    son[fa[um]] -= (r - a[um]);
    a[um] = r;
    printf("%.5lf\n", ans);
  }
  return 0;
}