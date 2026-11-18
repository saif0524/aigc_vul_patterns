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
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG = 20;
int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], g[MAXN];
int val[MAXN];
int mark[MAXN];
vector<int> G[MAXN], topol;
void dfs(int node) {
  mark[node] = 1;
  for (int v : G[node])
    if (!mark[v]) dfs(v);
  topol.push_back(node);
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i];
  while (m--) {
    cin >> u >> v;
    G[u].push_back(v);
  }
  for (int v = 1; v <= n; v++)
    if (!mark[v]) dfs(v);
  memset(mark, 0, sizeof(mark));
  for (int v : topol) {
    for (int u : G[v]) mark[g[u]] = v;
    while (mark[g[v]] == v) g[v]++;
    val[g[v]] ^= A[v];
  }
  for (int i = n; ~i; i--)
    if (val[i]) {
      for (int v = 1; v <= n; v++)
        if (g[v] == i && (A[v] ^ val[i]) < A[v]) {
          A[v] ^= val[i];
          for (int u : G[v]) {
            A[u] ^= val[g[u]];
            val[g[u]] = 0;
          }
          break;
        }
      cout << "WIN\n";
      for (int v = 1; v <= n; v++) cout << A[v] << ' ';
      cout << '\n';
      return 0;
    }
  cout << "LOSE\n";
  return 0;
}