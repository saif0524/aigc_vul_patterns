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
int n, a[300010];
long long dp[300010][42], ans;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 30; j++) dp[i][j] = 300000000000LL;
  dp[0][0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= 30; j++) {
      if (j + a[i] / 1000 <= 30)
        dp[i + 1][j + a[i] / 1000] =
            min(dp[i + 1][j + a[i] / 1000], dp[i][j] + a[i]);
      if (j * 100 >= a[i])
        dp[i + 1][j - a[i] / 100] = min(dp[i + 1][j - a[i] / 100], dp[i][j]);
      else
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + a[i] - j * 100);
    }
  ans = dp[n][0];
  for (int i = 1; i <= 30; i++) ans = min(ans, dp[n][i]);
  printf("%lld\n", ans);
}