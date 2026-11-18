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
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const long long maxn = (long long)1e6 + 5;
const long long mod = (long long)998244353;
const long long inf = 0x3f3f3f3f3f3f3f3f;
pair<long long, long long> a[maxn];
long long in[maxn];
vector<long long> v[maxn];
bool vis[maxn];
long long n, m, k;
long long ans;
void f(long long x) {
  queue<long long> q;
  q.push(x);
  vis[x] = true;
  --ans;
  while (!q.empty()) {
    long long now = q.front();
    q.pop();
    for (auto &i : v[now])
      if (!vis[i] && --in[i] < k) ans--, q.push(i), vis[i] = true;
  }
}
long long fin[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  ans = n;
  for (long long i = 1; i <= m; ++i) {
    cin >> a[i].first >> a[i].second;
    ++in[a[i].first], ++in[a[i].second];
    v[a[i].first].push_back(a[i].second);
    v[a[i].second].push_back(a[i].first);
  }
  for (long long i = 1; i <= n; ++i)
    if (!vis[i] && in[i] < k) f(i);
  fin[m] = ans;
  for (long long i = m; i >= 1; --i) {
    if (!vis[a[i].first]) --in[a[i].second];
    if (!vis[a[i].second]) --in[a[i].first];
    v[a[i].first].pop_back();
    v[a[i].second].pop_back();
    if (in[a[i].first] < k && !vis[a[i].first]) f(a[i].first);
    if (in[a[i].second] < k && !vis[a[i].second]) f(a[i].second);
    fin[i - 1] = ans;
  }
  for (long long i = 1; i <= m; ++i) cout << fin[i] << '\n';
  return 0;
}