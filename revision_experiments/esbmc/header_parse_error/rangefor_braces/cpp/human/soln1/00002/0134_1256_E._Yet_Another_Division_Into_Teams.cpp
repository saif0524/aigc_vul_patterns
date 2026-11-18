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
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  vector<long long> dp(n + 1);
  vector<int> p(n + 1, -1);
  sort(v.begin(), v.end());
  fill(dp.begin(), dp.end(), 2e15);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 2; j < i + 5 && j < n; ++j) {
      int diff = v[j].first - v[i].first;
      if (dp[i] + diff < dp[j + 1]) {
        dp[j + 1] = dp[i] + diff;
        p[j + 1] = i;
      }
    }
  }
  int tail = n, teamId = 0;
  vector<int> ans(n);
  while (tail > 0) {
    for (int i = tail - 1; i >= p[tail]; --i) ans[v[i].second] = teamId + 1;
    tail = p[tail];
    teamId++;
  }
  cout << dp[n] << " " << teamId << endl;
  for (auto e : ans) { cout << e << " "; }
  cout << endl;
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}