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
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n));
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u][v] = g[v][u] = 1;
  }
  auto bfs = [n, &g](int src, int trg, int t) -> int {
    vector<int> usd(n), dst(n, n);
    usd[src] = 1, dst[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == trg) break;
      for (int v = 0; v < n; ++v) {
        if (g[u][v] == t && !usd[v]) {
          usd[v] = 1;
          dst[v] = dst[u] + 1;
          q.push(v);
        }
      }
    }
    return dst[trg];
  };
  int ans = bfs(0, n - 1, 1 - g[0][n - 1]);
  cout << (ans == n ? -1 : ans) << endl;
}
void init() {
  ((void)0);
  ((void)0);
}
int main() {
  init();
  solve();
  return 0;
}