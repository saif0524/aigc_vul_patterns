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
  string s, t;
  cin >> s >> t;
  s = "#" + s;
  t = "#" + t;
  int n = s.length() - 1;
  int m = t.length() - 1;
  vector<vector<int>> go(m + 2, vector<int>(26));
  vector<int> pi(m + 2);
  vector<vector<int>> dp(n + 2, vector<int>(m + 2));
  if (t.length() > s.length()) {
    cout << 0 << "\n";
    return;
  }
  int k = 0;
  pi[1] = 0;
  for (int i = 2; i <= m; ++i) {
    while (k > 0 && t[k + 1] != t[i]) {
      k = pi[k];
    }
    if (t[k + 1] == t[i]) ++k;
    pi[i] = k;
  }
  for (int i = 0; i <= m; ++i) {
    for (int ch = 0; ch < 26; ++ch) {
      go[i][ch] = 0;
    }
    for (int k = i;; k = pi[k]) {
      if (k + 1 < t.length()) {
        int ch = t[k + 1] - 'a';
        if (go[i][ch] == 0) {
          go[i][ch] = k + 1;
        }
      }
      if (k == 0) break;
    }
  }
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j] = -1;
    }
  }
  dp[1][0] = 0;
  for (int i = 1; i <= n + 1; ++i) {
    for (int k = 0; k <= m; ++k) {
      if (dp[i][k] == -1) continue;
      dp[i][k] += (k == m);
      if (i <= n) {
        if (s[i] != '?') {
          dp[i + 1][go[k][s[i] - 'a']] =
              max(dp[i + 1][go[k][s[i] - 'a']], dp[i][k]);
        } else {
          for (int ch = 0; ch < 26; ++ch) {
            dp[i + 1][go[k][ch]] = max(dp[i + 1][go[k][ch]], dp[i][k]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; ++i) {
    ans = max(ans, dp[n + 1][i]);
  }
  cout << ans << "\n";
}
int main() {
  int tests = 1;
  for (; tests; --tests) {
    solve();
  }
}