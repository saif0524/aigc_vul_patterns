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
int n, m;
vector<pair<int, int>> edges[100005];
bool vis[100005];
int col[100005];
bool flag = true;
void dfs(int u, int c) {
  vis[u] = true;
  col[u] = c;
  for (auto e : edges[u]) {
    int v = e.first;
    if (vis[v]) {
      if (col[v] != (c ^ e.second)) {
        flag = false;
      }
    } else {
      dfs(v, c ^ e.second);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
      if (!flag) {
        cout << 0 << endl;
        return 0;
      }
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        if (col[j] == 0) cnt++;
      }
      if (cnt > 0 && cnt < n) {
        ans = ans * 2 % mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}