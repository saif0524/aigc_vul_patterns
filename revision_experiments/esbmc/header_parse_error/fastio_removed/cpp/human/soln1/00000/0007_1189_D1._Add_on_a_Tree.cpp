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
void pr_init() {
  ((void)0);
  ((void)0);
  ((void)0);
}
vector<vector<long long> > tree;
vector<long long> deg;
void solve() {
  long long n;
  cin >> n;
  tree.assign(n + 1, vector<long long>());
  deg.assign(n + 1, 0);
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  if (n == 2) {
    cout << "YES\n";
    return;
  } else if (n == 3) {
    cout << "NO\n";
    return;
  }
  bool is = true;
  for (long long i = 1; i <= n; i++) {
    if (deg[i] != 1 && deg[i] < 3) is = false;
  }
  if (is)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int32_t main() {
  solve();
  return 0;
}