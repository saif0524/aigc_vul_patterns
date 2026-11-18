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
using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a, b;
  vector<int> v(n);
  for (int &e : v) {
    cin >> e;
  }
  for (int &e : v) {
    int x;
    cin >> x;
    if (x == 1) {
      a.push_back(e);
    } else {
      b.push_back(e);
    }
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  ll curSumA = 0;
  int r = (int)b.size();
  ll curSumB = accumulate(b.begin(), b.end(), 0ll);
  int ans = INT_MAX;
  for (int l = 0; l <= a.size(); l++) {
    while (r > 0 && curSumA + curSumB - b[r - 1] >= m) {
      r--;
      curSumB -= b[r];
    }
    if (curSumB + curSumA >= m) {
      ans = min(ans, 2 * r + l);
    }
    if (l != a.size()) {
      curSumA += a[l];
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}