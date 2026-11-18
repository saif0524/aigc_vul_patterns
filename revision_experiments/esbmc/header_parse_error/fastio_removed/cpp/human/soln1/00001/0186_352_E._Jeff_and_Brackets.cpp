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
const int N = 2e5 + 10;
int n, m, a[N], b[N];
int dp[22][44];
struct uzi {
  long long A[44][44];
  uzi() { memset(A, 0x3f3f3f, sizeof A); };
} G;
uzi operator*(const uzi& a, const uzi& b) {
  uzi c;
  for (int i = 0; i <= 40; i++) {
    for (int j = 0; j <= 40; j++) {
      for (int k = 0; k <= 40; k++) {
        c.A[i][j] = min(a.A[i][k] + b.A[k][j], c.A[i][j]);
      }
    }
  }
  return c;
}
uzi pm() {
  uzi c;
  for (int i = 0; i <= 40; i++) c.A[i][i] = 0;
  while (m) {
    if (m & 1) c = c * G;
    G = G * G;
    m >>= 1;
  }
  return c;
}
int main() {
  ((void)0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i <= 40; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= 40; k++) {
        dp[j][k] = 1e9;
        if (!j) {
          if (k == i) dp[j][k] = 0;
        } else {
          if (k) {
            dp[j][k] = min(dp[j][k], dp[j - 1][k - 1] + a[j - 1]);
          }
          if (k + 1 <= 40) {
            dp[j][k] = min(dp[j][k], dp[j - 1][k + 1] + b[j - 1]);
          }
        }
      }
      for (int k = 0; k <= 40; k++) {
        G.A[i][k] = dp[n][k];
      }
    }
  }
  cout << pm().A[0][0];
  return 0;
}