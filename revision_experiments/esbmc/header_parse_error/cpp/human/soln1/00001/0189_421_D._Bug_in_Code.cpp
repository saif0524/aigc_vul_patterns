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
const long long N = 2e5;
void solve() {
  long long n, p;
  cin >> n >> p;
  vector<vector<long long> > g(n);
  vector<pair<long long, long long> > e(n);
  map<pair<long long, long long>, long long> cnt;
  for (long long i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    --a;
    --b;
    cnt[make_pair(a, b)]++;
    cnt[make_pair(b, a)]++;
    e[i] = make_pair(a, b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  long long res = 0;
  vector<long long> r(n);
  for (long long i = 0; i < n; ++i) r[i] = g[i].size();
  sort(r.begin(), r.end());
  for (long long i = 0; i < n; ++i) {
    long long id = lower_bound(r.begin(), r.end(), p - r[i]) - r.begin();
    if (id > i)
      res += n - id;
    else
      res += n - id - 1;
  }
  res /= 2;
  set<pair<long long, long long> > b;
  for (long long i = 0; i < n; ++i)
    if (g[e[i].first].size() + g[e[i].second].size() >= p &&
        g[e[i].first].size() + g[e[i].second].size() - cnt[e[i]] < p &&
        !b.count(e[i]) && !b.count(make_pair(e[i].second, e[i].first)))
      res--, b.insert(e[i]), b.insert(make_pair(e[i].second, e[i].first));
  cout << res;
}
int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}