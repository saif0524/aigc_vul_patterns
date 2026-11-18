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

int n, k, s;
int dp[21][11][156];

void solve() {
  cin >> n >> k >> s;
  if (n == 0 && k == 0 && s == 0) {
    exit(0);
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i][0][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int sum = 1; sum <= s; sum++) {
        for (int last = 1; last <= i && last * j <= sum; last++) {
          if (last * j > sum) break;
          dp[i][j][sum] += dp[i - 1][j - 1][sum - last * j];
        }
      }
    }
  }
  cout << dp[n][k][s] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    solve();
  }
  return 0;
}