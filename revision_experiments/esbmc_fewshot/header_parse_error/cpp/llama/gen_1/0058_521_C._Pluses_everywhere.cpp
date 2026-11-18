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
int n, k;
string s;
long long dp[100005][100005];
long long pow10[100005];
long long ans;
int main() {
  cin >> n >> k >> s;
  pow10[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow10[i] = (pow10[i - 1] * 10) % mod;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j > 0 && i > 1) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (i - 1 - j > 0) continue;
      int len = i - 1 - j;
      int num = stoi(s.substr(0, len));
      ans = (ans + (num * dp[n - len][k - j]) % mod) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}