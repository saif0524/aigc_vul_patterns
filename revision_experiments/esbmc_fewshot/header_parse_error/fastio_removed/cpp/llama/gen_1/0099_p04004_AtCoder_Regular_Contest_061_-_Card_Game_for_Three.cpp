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
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
long long dp[N][N][N];
long long pow3[N + N + N];
int main() {
  ((void)0);
  ((void)0);
  int n, m, k;
  cin >> n >> m >> k;
  pow3[0] = 1;
  for (int i = 1; i <= n + m + k; i++) {
    pow3[i] = pow3[i - 1] * 3 % mod;
  }
  dp[n][m][k] = 1;
  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      for (int kk = k; kk >= 0; kk--) {
        if (i == 0 && j == 0 && kk == 0) continue;
        if (i > 0) {
          dp[i - 1][j][kk] = (dp[i - 1][j][kk] + dp[i][j][kk]) % mod;
        }
        if (j > 0) {
          dp[i][j - 1][kk] = (dp[i][j - 1][kk] + dp[i][j][kk]) % mod;
        }
        if (kk > 0) {
          dp[i][j][kk - 1] = (dp[i][j][kk - 1] + dp[i][j][kk]) % mod;
        }
      }
    }
  }
  cout << (pow3[n + m + k] - dp[0][0][0] + mod) % mod << '\n';
  return 0;
}