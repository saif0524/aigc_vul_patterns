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
int n, m, p[N], u[N], v[N];
vector<int> g[N];
int main() {
  ((void)0);
  ((void)0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i];
    g[v[i]].push_back(u[i]);
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (p[i] == n) {
      ans = n - i;
      break;
    }
    for (auto x : g[p[i]]) {
      if (x == n) {
        swap(p[i], p[i + 1]);
        ans = max(ans, n - i);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}