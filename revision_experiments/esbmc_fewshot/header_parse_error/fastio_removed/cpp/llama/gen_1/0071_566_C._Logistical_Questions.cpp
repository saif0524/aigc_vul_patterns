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
typedef long long ll;
typedef long double ld;
const int N = 2e5 + 5;
vector<pair<int, int>> g[N];
int w[N];
int n;
ll ans = 1e18;
int idx;
void dfs(int u, int p, ll d, ll sum) {
  sum += w[u] * d;
  if (sum < ans) {
    ans = sum;
    idx = u;
  }
  for (auto& e : g[u]) {
    int v = e.first;
    if (v == p) continue;
    dfs(v, u, d + e.second, sum);
  }
}
int main() {
  ((void)0);
  ((void)0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i < n; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    g[u].push_back({v, d});
    g[v].push_back({u, d});
  }
  for (int i = 1; i <= n; i++) {
    ans = 1e18;
    dfs(i, 0, 0, 0);
    idx = i;
    break;
  }
  ld sum = 0;
  for (int i = 1; i <= n; i++) {
    if (i == idx) continue;
    ll d = 0;
    vector<int> path;
    int u = i;
    while (u != idx) {
      for (auto& e : g[u]) {
        int v = e.first;
        if (v == idx) {
          d += e.second;
          break;
        }
        if (v > idx) continue;
        path.push_back(u);
        u = v;
        break;
      }
    }
    reverse(path.begin(), path.end());
    path.push_back(idx);
    for (int j = 0; j < path.size() - 1; j++) {
      for (auto& e : g[path[j]]) {
        if (e.first == path[j + 1]) {
          d += e.second;
          break;
        }
      }
    }
    sum += w[i] * sqrt(d);
  }
  cout << idx << " " << fixed << setprecision(10) << sum << endl;
  return 0;
}