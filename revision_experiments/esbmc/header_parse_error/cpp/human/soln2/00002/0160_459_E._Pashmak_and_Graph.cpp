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
struct edge {
  int u, v, w;
};
bool comp(edge a, edge b) { return a.w < b.w; }
int len[300010], tmp[300010];
edge ed[300010];
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, x, y, z, l, j;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> z;
    ed[i].u = x, ed[i].v = y, ed[i].w = z;
  }
  sort(ed, ed + m, comp);
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    j = i;
    while (j < m - 1 && ed[j].w == ed[j + 1].w) j++;
    for (int k = i; k <= j; ++k) {
      x = ed[k].u, y = ed[k].v;
      tmp[y] = max(tmp[y], len[x] + 1);
    }
    for (int k = i; k <= j; ++k) {
      y = ed[k].v;
      len[y] = max(len[y], tmp[y]);
      ans = max(len[y], ans);
    }
    i = j;
  }
  cout << ans;
  return 0;
}