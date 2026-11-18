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
const int N = 3e5 + 5;
vector<pair<int, int>> g[N];
int d[N], used[N];
int cnt = 0;
vector<int> ans;
void dfs(int v, int p) {
  used[v] = 1;
  for (auto e : g[v]) {
    int to = e.first;
    if (to == p) continue;
    if (!used[to]) {
      dfs(to, v);
      if (d[to] == -1) {
        d[v] ^= 1;
        ans.push_back(e.second);
      } else if (d[to] == 1) {
        d[v] ^= 1;
        ans.push_back(e.second);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    sum += (d[i] == 1);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  if (sum % 2) {
    cout << -1 << endl;
    return 0;
  }
  dfs(1, 0);
  cout << ans.size() << endl;
  for (auto e : ans) cout << e << endl;
  return 0;
}