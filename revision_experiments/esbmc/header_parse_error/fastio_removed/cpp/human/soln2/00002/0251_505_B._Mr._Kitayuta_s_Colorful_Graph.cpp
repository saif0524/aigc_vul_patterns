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
const int N = 1e5 + 100, M = 1e6 + 100, SQ = sqrt(2e5), LG = 23, base = 2,
          second = 1e2 + 100;
const long long mod = 1e9 + 7, MOD = 1e9 + 9, Inf = 9223372036854775807;
const long long INF = 1e9, inf = 1e18, super_inf = ~0ull / 4;
const long double Pi = (22 * 1.0) / (7 * 1.0);
using namespace std;
long long n, m, ans, a, b, c, q;
vector<pair<long long, long long> > v[second];
bool mark[second];
void dfs(long long a, long long b, int c) {
  mark[a] = 1;
  for (auto x : v[a]) {
    if (!mark[x.first] and x.second == c) dfs(x.first, b, c);
  }
}
int main() {
  ((void)0), ((void)0), ((void)0);
  ;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a >> b >> c, v[a].push_back(make_pair(b, c)),
        v[b].push_back(make_pair(a, c));
  cin >> q;
  while (q--) {
    cin >> a >> b;
    ans = 0;
    for (int i = 1; i <= m; i++) {
      fill(mark, mark + second, 0);
      dfs(a, b, i);
      if (mark[b]) ans++;
    }
    cout << ans << endl;
  }
}