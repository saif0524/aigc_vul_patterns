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
const int N = 100, V = 100;
struct bottle {
  int a, b;
  bool operator<(const bottle &bt) const { return b > bt.b; }
} bot[N + 1];
int dp[N + 1][N * V + 1];
int main() {
  int n, shui = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &bot[i].a);
    shui += bot[i].a;
  }
  for (int j = 1; j <= n; ++j) scanf("%d", &bot[j].b);
  sort(bot + 1, bot + n + 1);
  int ping = 0;
  for (int i = 1, w = shui; w > 0; ++i) {
    w -= bot[i].b;
    ++ping;
  }
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = ping; j; --j)
      for (int k = shui; k >= bot[i].a; --k)
        if (~dp[j - 1][k - bot[i].a])
          dp[j][k] = max(dp[j][k], dp[j - 1][k - bot[i].a] + bot[i].b);
  int mx = 0;
  for (int i = shui; ~i; --i)
    if (dp[ping][i] >= shui) {
      mx = i;
      break;
    }
  printf("%d %d\n", ping, shui - mx);
  return 0;
}