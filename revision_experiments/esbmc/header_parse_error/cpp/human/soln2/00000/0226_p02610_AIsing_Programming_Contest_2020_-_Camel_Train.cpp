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
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll f(vector<P> p) {
  int n = p.size();
  rep(i,n) p[i].first = min(p[i].first, n);
  vector<vector<int>> s(n+1);
  rep(i,n) s[p[i].first].push_back(p[i].second);

  ll res = 0;
  priority_queue<int> q;
  for (int i = n; i >= 1; --i) {
    for (int x : s[i]) q.push(x);
    if (q.size() > 0) {
      res += q.top();
      q.pop();
    }
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<P> pl, pr;
  ll ans = 0;
  rep(i,n) {
    int k, l, r;
    cin >> k >> l >> r;
    int m = min(l,r);
    ans += m;
    l -= m; r -= m;
    if (l > 0) pl.emplace_back(k,l);
    else pr.emplace_back(n-k,r);
  }
  ans += f(pl);
  ans += f(pr);
  cout << ans << endl;
}

int main() {
  int ts;
  cin >> ts;
  rep(ti,ts) solve();
  return 0;
}