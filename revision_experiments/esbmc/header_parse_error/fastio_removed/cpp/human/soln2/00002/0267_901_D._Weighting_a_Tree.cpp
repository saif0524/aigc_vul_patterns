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
vector<vector<pair<long long, long long> > > g;
vector<long long> ans;
vector<long long> c;
vector<bool> used;
vector<long long> dp;
vector<long long> col;
vector<long long> p;
long long val = 0;
long long pos = 0;
long long pos2 = 0;
void doit(long long v) {
  used[v] = 1;
  for (auto i : g[v]) {
    if (!used[i.first]) {
      p[i.first] = v;
      doit(i.first);
      ans[i.second] = c[i.first] - dp[i.first];
      dp[i.first] += ans[i.second];
      dp[v] += ans[i.second];
    }
  }
}
bool dfs(long long v) {
  used[v] = 1;
  for (auto i : g[v]) {
    if (!used[i.first]) {
      col[i.first] = col[v] ^ 1;
      if (dfs(i.first)) return 1;
    } else {
      if (col[i.first] != col[v] ^ 1) {
        val = i.second;
        pos = i.first;
        pos2 = v;
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  ((void)0);
  ((void)0), ((void)0);
  long long n, m;
  cin >> n >> m;
  ans.resize(m);
  g.resize(n);
  c.resize(n);
  dp.resize(n);
  p.resize(n);
  for (long long i = 0; i < n; i++) cin >> c[i];
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }
  used.assign(n, 0);
  doit(0);
  if (dp[0] == c[0]) {
    cout << "YES\n";
    for (long long i : ans) cout << i << '\n';
    return 0;
  }
  used.assign(n, 0);
  col.resize(n);
  col[0] = 0;
  if (!dfs(0)) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  vector<long long> to;
  long long now = pos;
  while (now != 0) {
    to.push_back(now);
    now = p[now];
  }
  reverse(to.begin(), to.end());
  now = 0;
  for (long long i = 0; i < to.size(); i++) {
    for (auto j : g[now]) {
      if (j.first == to[i]) {
        long long up = c[now] - dp[now];
        ans[j.second] += up;
        dp[now] += up;
        dp[j.first] += up;
      }
    }
    now = to[i];
  }
  if ((c[pos] - dp[pos]) % 2 != 0) {
    return -1;
  }
  long long up = (c[pos] - dp[pos]) / 2;
  ans[val] += up;
  dp[pos] += up;
  dp[pos2] += up;
  to.clear();
  now = pos2;
  while (now != pos) {
    to.push_back(now);
    now = p[now];
  }
  reverse(to.begin(), to.end());
  now = pos;
  for (long long i = 0; i < to.size(); i++) {
    for (auto j : g[now]) {
      if (j.first == to[i]) {
        long long up = c[now] - dp[now];
        ans[j.second] += up;
        dp[now] += up;
        dp[j.first] += up;
      }
    }
    now = to[i];
  }
  for (long long i : ans) cout << i << '\n';
  return 0;
}