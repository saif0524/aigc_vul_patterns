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
int dp[5005][5005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dp[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    int sum = 0;
    for (int j = 0; j < i; j++) {
      sum = (sum + dp[i - 1][j]) % mod;
    }
    dp[i][i] = sum;
    for (int j = i - 1; j >= 0; j--) {
      dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans = (ans + dp[m][i]) % mod;
  }
  cout << ans << endl;
  return 0;
}