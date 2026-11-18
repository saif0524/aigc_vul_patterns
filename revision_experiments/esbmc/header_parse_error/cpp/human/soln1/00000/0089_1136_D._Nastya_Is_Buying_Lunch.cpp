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
const double PI = acos(-1.0);
const double eps = 1e-6;
const int inf = 1e9;
const long long llf = 1e18;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 10;
int n, m;
int p[maxn];
vector<int> f[maxn];
vector<int> q;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    f[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    sort(f[i].begin(), f[i].end());
  }
  q.push_back(p[n]);
  int ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    int flag = 1;
    for (int x : q) {
      auto it = lower_bound(f[p[i]].begin(), f[p[i]].end(), x);
      if (it != f[p[i]].end() && *it == x) {
      } else {
        q.push_back(p[i]);
        flag = 0;
        break;
      }
    }
    if (flag) ans++;
  }
  cout << ans << endl;
  return 0;
}