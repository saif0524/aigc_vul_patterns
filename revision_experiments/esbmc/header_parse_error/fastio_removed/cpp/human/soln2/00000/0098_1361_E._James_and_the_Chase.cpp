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
mt19937 rng(420);
const int N = (int)1e5 + 100;
vector<int> T[N];
int vis[N];
int dep[N];
int deg[N];
vector<int> ord;
void shuffle() {
  int q = ord.size();
  int pi, qi;
  for (int i = 0; i < 2 * q; i++) {
    pi = ((int)rng() % q + q) % q;
    qi = ((int)rng() % q + q) % q;
    swap(ord[pi], ord[qi]);
  }
}
bool valid;
void dfs(int u) {
  vis[u] = 1;
  for (auto x : T[u]) {
    if (vis[x] == 0) {
      dep[x] = dep[u] + 1;
      dfs(x);
    } else if (vis[x] == 2) {
      valid = false;
    }
  }
  vis[u] = 2;
}
bool good[N];
bool cons[N];
int par[N];
int dfs1(int u) {
  vis[u] = true;
  int cnt = 0;
  int nx;
  par[u] = u;
  for (auto x : T[u]) {
    if (!vis[x]) {
      cnt += dfs1(x);
      if (dep[par[x]] < dep[par[u]]) par[u] = par[x];
    } else {
      if (dep[x] < dep[par[u]]) par[u] = x;
      cnt++;
    }
  }
  cnt -= (deg[u] - 1);
  if (cnt > 1) {
    cons[u] = false;
  } else {
    cons[u] = true;
  }
  return cnt;
}
vector<int> out;
void dfs2(int u) {
  vis[u] = true;
  if (cons[u]) {
    if (good[par[u]]) {
      good[u] = true;
    }
  }
  if (good[u]) {
    out.push_back(u);
  }
  for (auto x : T[u]) {
    if (!vis[x]) {
      dfs2(x);
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= n; i++) {
    T[i].clear();
    vis[i] = false;
    deg[i] = 0;
    good[i] = false;
  }
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    T[u].push_back(v);
    deg[v]++;
  }
  ord.clear();
  for (int i = 1; i <= n; i++) {
    ord.push_back(i);
  }
  shuffle();
  int root = -1;
  int cur;
  for (int T = 0; T < 100; T++) {
    if (ord.empty()) break;
    cur = ord.back();
    ord.pop_back();
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      dep[i] = -1;
    }
    valid = true;
    dep[cur] = 0;
    dfs(cur);
    if (valid) {
      root = cur;
      break;
    }
  }
  if (root == -1) {
    cout << "-1\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    good[i] = false;
    par[i] = -1;
    vis[i] = false;
  }
  good[root] = true;
  dfs1(root);
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
  }
  out.clear();
  dfs2(root);
  if (out.size() < (n + 4) / 5) {
    cout << "-1\n";
  } else {
    sort(out.begin(), out.end());
    for (auto x : out) cout << x << " ";
    cout << "\n";
  }
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  ;
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}