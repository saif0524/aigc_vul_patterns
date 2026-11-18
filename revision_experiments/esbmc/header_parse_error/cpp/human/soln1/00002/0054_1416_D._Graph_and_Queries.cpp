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
int val[200005];
pair<int, int> e[300005];
bool del[300005];
int qT[500005], qV[500005];
int color[200005];
inline int repr(int x) {
  return color[x] == x ? x : (color[x] = repr(color[x]));
}
vector<int> f[200005];
pair<int, int> op[500005];
inline void join(int x, int y, int ind) {
  x = repr(x);
  y = repr(y);
  if (x != y) {
    if (f[x].size() < f[y].size()) swap(x, y);
    f[x].insert(f[x].end(), f[y].begin(), f[y].end());
    color[y] = x;
    if (ind != -1) {
      op[ind] = {x, y};
    }
  }
}
int root[200005];
set<pair<int, int>> ff[200005];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) cin >> val[i];
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &e[i].first, &e[i].second);
    e[i].first--;
    e[i].second--;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &qT[i], &qV[i]), qV[i]--;
    if (qT[i] == 2) del[qV[i]] = true;
  }
  for (int i = 0; i < n; ++i) {
    color[i] = i;
    f[i].push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    if (del[i]) continue;
    join(e[i].first, e[i].second, -1);
  }
  for (int i = q - 1; i >= 0; --i) {
    if (qT[i] == 2) {
      join(e[qV[i]].first, e[qV[i]].second, i);
    }
  }
  for (int i = 0; i < n; ++i) {
    ff[repr(i)].insert({-val[i], i});
    root[i] = repr(i);
  }
  for (int i = 0; i < q; ++i) {
    if (qT[i] == 1) {
      int p = root[qV[i]];
      if (ff[p].size() > 0) {
        printf("%d\n", -ff[p].begin()->first);
        val[ff[p].begin()->second] = 0;
        ff[p].erase(ff[p].begin());
      } else {
        puts("0");
      }
    } else if (op[i].first != op[i].second) {
      for (int t : f[op[i].second]) {
        root[t] = op[i].second;
        if (val[t] > 0) {
          ff[op[i].first].erase({-val[t], t});
          ff[op[i].second].insert({-val[t], t});
        }
      }
    }
  }
  return 0;
}