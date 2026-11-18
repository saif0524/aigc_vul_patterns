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
namespace zyt {
const int N = 110, INF = 0x3f3f3f3f;
int arr[N], n, dp[N][N][2];
int work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  int odd = (n + 1) >> 1;
  for (int j = 1; j <= odd; j++) dp[0][j][0] = dp[0][j][1] = INF;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= odd; j++) {
      dp[i][j][0] = dp[i][j][1] = INF;
      if ((!arr[i] || (arr[i] & 1)) && j)
        dp[i][j][1] =
            min(dp[i][j][1], min(dp[i - 1][j - 1][0] + 1, dp[i - 1][j - 1][1]));
      if (!arr[i] || !(arr[i] & 1))
        dp[i][j][0] =
            min(dp[i][j][0], min(dp[i - 1][j][1] + 1, dp[i - 1][j][0]));
    }
  printf("%d", min(dp[n][odd][0], dp[n][odd][1]));
  return 0;
}
}  // namespace zyt
int main() { return zyt::work(); }