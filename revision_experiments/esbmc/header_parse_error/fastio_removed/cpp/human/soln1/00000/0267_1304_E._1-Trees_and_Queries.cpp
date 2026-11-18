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
const int mod = 1e9 + 7;
inline long long add(long long a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
inline long long mul(long long a, long long b) {
  return (long long)((long long)a * b % mod);
}
vector<vector<long long> > adj, dp;
vector<long long> cnt, lvl;
void DFSUtil(long long u, long long p) {
  if (u != 0) {
    lvl[u] = lvl[p] + 1;
  }
  dp[u][0] = p;
  for (long long i = (1); i <= (20); i++) {
    dp[u][i] = dp[dp[u][i - 1]][i - 1];
  }
  for (auto it : adj[u])
    if (it != p) DFSUtil(it, u);
}
void DFS() {
  long long V = adj.size();
  lvl.assign(V, 0);
  DFSUtil(0, 0);
}
long long lca(long long x, long long y) {
  if (x == y) return 0;
  if (lvl[x] < lvl[y]) swap(x, y);
  long long d = lvl[x] - lvl[y];
  long long x1 = x;
  for (long long i = (0); i <= (20); i++)
    if ((1 << i) & d) x1 = dp[x1][i];
  if (x1 == y) return d;
  long long xx = x1, yy = y;
  for (long long i = (20); i >= (0); i--)
    if (dp[xx][i] != dp[yy][i]) {
      d += 2 * (1 << i);
      xx = dp[xx][i];
      yy = dp[yy][i];
    }
  d += 2;
  return d;
}
bool query() {
  long long a, b, x, y, k;
  cin >> a >> b >> x >> y >> k;
  x--;
  y--;
  a--;
  b--;
  long long v1 = lca(x, y), v2 = lca(x, a), v3 = lca(x, b), v4 = lca(y, a),
            v5 = lca(y, b);
  if (v1 <= k && (k - v1) % 2 == 0) {
    return true;
  }
  if ((v2 + v5 + 1) <= k && (k - (v2 + v5 + 1)) % 2 == 0) {
    return true;
  }
  if ((v3 + v4 + 1) <= k && (k - (v3 + v4 + 1)) % 2 == 0) {
    return true;
  }
  return false;
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  ;
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    adj.resize(n + 1);
    for (long long i = (1); i <= (n - 1); i++) {
      long long p, q;
      cin >> p >> q;
      p--;
      q--;
      adj[p].push_back(q);
      adj[q].push_back(p);
    }
    dp.assign(n + 1, vector<long long>(21, 0));
    DFS();
    long long m;
    cin >> m;
    for (long long i = (1); i <= (m); i++) {
      if (query())
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}