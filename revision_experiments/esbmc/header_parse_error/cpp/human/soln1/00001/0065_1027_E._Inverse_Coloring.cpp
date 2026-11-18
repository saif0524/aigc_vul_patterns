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
long long mod = 998244353, dpp[510][510][4], dpc[510][510][4], f[510], g[510];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tp2, i, j, n, k, cnt = 0, tp;
  cin >> n >> tp2;
  tp2--;
  dpp[1][1][1] = 1;
  dpp[1][1][2] = 1;
  for (i = 2; i <= n; i++) {
    for (j = 1; j <= i; j++)
      for (k = 1; k <= j; k++) {
        tp = max(k + 1, j);
        dpc[tp][k + 1][1] = (dpc[tp][k + 1][1] + dpp[j][k][1]) % mod;
        dpc[tp][k + 1][2] = (dpc[tp][k + 1][2] + dpp[j][k][2]) % mod;
        dpc[j][1][2] = (dpc[j][1][2] + dpp[j][k][1]) % mod;
        dpc[j][1][1] = (dpc[j][1][1] + dpp[j][k][2]) % mod;
      }
    if (i != n) {
      for (j = 1; j <= i; j++)
        for (k = 1; k <= j; k++)
          dpp[j][k][1] = dpc[j][k][1], dpp[j][k][2] = dpc[j][k][1];
      for (j = 1; j <= n; j++)
        for (k = 1; k <= n; k++) dpc[j][k][1] = 0, dpc[j][k][2] = 0;
    }
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= i; j++) f[i] = (f[i] + dpc[i][j][1] + dpc[i][j][2]) % mod;
  for (j = 1; j <= n; j++)
    for (k = 1; k <= n; k++) dpc[j][k][1] = 0, dpc[j][k][2] = 0;
  for (j = 1; j <= n; j++)
    for (k = 1; k <= j; k++) {
      tp = max(k + 1, j);
      dpc[tp][k + 1][1] = (dpc[tp][k + 1][1] + dpp[j][k][1]) % mod;
      dpc[j][1][1] = (dpc[j][1][1] + dpp[j][k][2]) % mod;
    }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= i; j++) g[i] = (g[i] + dpc[i][j][1]) % mod;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (i * j <= tp2) cnt = (cnt + f[i] * g[j]) % mod;
  cout << cnt << "\n";
  return 0;
}