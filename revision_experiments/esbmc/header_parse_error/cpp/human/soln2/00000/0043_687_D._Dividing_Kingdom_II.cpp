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
int n, m, q, dsu[2005];
map<pair<int, int>, int> ans;
struct edge {
  int x, y, z, u;
  bool operator<(const edge b) const { return z < b.z; }
} e[500005];
int find_(int x) { return x == dsu[x] ? x : dsu[x] = find_(dsu[x]); }
void unite_(int x, int y) { dsu[find_(x)] = dsu[find_(y)]; }
signed main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= m;
       scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z), e[i].u = i, i++)
    ;
  sort(e + 1, e + 1 + m);
  while (q--) {
    int el, er;
    scanf("%d%d", &el, &er);
    for (int i = 1; i <= n * 2; i++) dsu[i] = i;
    bool flag = 0;
    for (int i = m; i >= 1; i--)
      if (e[i].u >= el && e[i].u <= er) {
        int fx = find_(e[i].x), fy = find_(e[i].y);
        if (fx == fy) {
          printf("%d\n", e[i].z);
          flag = 1;
          break;
        }
        unite_(e[i].x, e[i].y + n), unite_(e[i].x + n, e[i].y);
      }
    if (!flag) puts("-1");
  }
  return 0;
}