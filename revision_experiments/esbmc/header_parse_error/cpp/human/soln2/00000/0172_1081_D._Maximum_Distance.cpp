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
long long int n, m, k;
set<long long int> x;
vector<pair<long long int, long long int>> adj[1000001];
long long int par[1000001];
vector<pair<long long int, pair<long long int, long long int>>> l;
long long int find(long long int x) {
  if (par[x] == 0) {
    return x;
  }
  return par[x] = find(par[x]);
}
long long int ans;
long long int vis[10000001];
void dfs(long long int cur, long long int mx) {
  if (x.find(cur) != x.end()) {
    ans = max(ans, mx);
  }
  vis[cur] = 1;
  long long int i, j;
  for (i = 0; i < adj[cur].size(); ++i) {
    if (!vis[adj[cur][i].first]) {
      dfs(adj[cur][i].first, max(mx, adj[cur][i].second));
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  long long int i, j;
  long long int u, v, w;
  for (i = 1; i <= k; ++i) {
    cin >> j;
    x.insert(j);
  }
  for (i = 1; i <= m; ++i) {
    cin >> u >> v >> w;
    l.push_back(make_pair(w, make_pair(u, v)));
  }
  sort(l.begin(), l.end());
  for (i = 0; i < l.size(); ++i) {
    long long int a, b;
    a = find(l[i].second.first);
    b = find(l[i].second.second);
    if (a != b) {
      par[a] = b;
      adj[l[i].second.first].push_back(
          make_pair(l[i].second.second, l[i].first));
      adj[l[i].second.second].push_back(
          make_pair(l[i].second.first, l[i].first));
    }
  }
  set<long long int>::iterator it = x.begin();
  dfs(*it, 0);
  for (i = 1; i <= k; ++i) cout << ans << " ";
  cout << endl;
  return 0;
}