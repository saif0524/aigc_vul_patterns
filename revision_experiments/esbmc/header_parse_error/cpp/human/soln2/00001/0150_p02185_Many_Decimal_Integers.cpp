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
#define MOD (long long)(1e9 + 7)
using namespace std;

long long ssize = 0;
long long dp[200005][2] = {0}, sum[200005][2] = {0};
string s, t;

long long solve();

int main() {
  cin >> s >> t;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  ssize = s.size();
  dp[0][0] = 1;
  for(int i = 0; i < ssize; ++i) {
    int nums = s[i] - '0', numt = t[i] - '0';
    if(t[i] != '?') {
      if(nums == numt) {
        (dp[i + 1][1] += dp[i][1]) %= MOD;
        (dp[i + 1][0] += dp[i][0]) %= MOD;

        sum[i + 1][1] +=
            (sum[i][1] * 10 % MOD + dp[i][1] * numt % MOD) %
            MOD;
        sum[i + 1][1] %= MOD;
        sum[i + 1][0] +=
            (sum[i][0] * 10 % MOD + dp[i][0] * numt % MOD) %
            MOD;
        sum[i + 1][0] %= MOD;
      }
      else if(nums < numt) {
        dp[i + 1][1] += dp[i][1];
        dp[i + 1][1] %= MOD;

        sum[i + 1][1] +=
            (sum[i][1] * 10 % MOD + dp[i][1] * numt % MOD) %
            MOD;
        sum[i + 1][1] %= MOD;
      }
      else {
        dp[i + 1][1] += dp[i][1];
        (dp[i + 1][1] += dp[i][0]) %= MOD;

        sum[i + 1][1] +=
            (sum[i][1] * 10 % MOD + dp[i][1] * numt % MOD) %
            MOD;
        sum[i + 1][1] %= MOD;
        sum[i + 1][1] +=
            (sum[i][0] * 10 % MOD + dp[i][0] * numt % MOD) %
            MOD;
        sum[i + 1][1] %= MOD;
      }
    }
    else {
      for(int k = 0; k < 10; ++k) {
        numt = k;
        if(nums == numt) {
          (dp[i + 1][1] += dp[i][1]) %= MOD;
          (dp[i + 1][0] += dp[i][0]) %= MOD;

          sum[i + 1][1] += (sum[i][1] * 10 % MOD +
                            dp[i][1] * numt % MOD) %
                           MOD;
          sum[i + 1][1] %= MOD;
          sum[i + 1][0] += (sum[i][0] * 10 % MOD +
                            dp[i][0] * numt % MOD) %
                           MOD;
          sum[i + 1][0] %= MOD;
        }
        else if(nums < numt) {
          dp[i + 1][1] += dp[i][1];
          dp[i + 1][1] %= MOD;

          sum[i + 1][1] += (sum[i][1] * 10 % MOD +
                            dp[i][1] * numt % MOD) %
                           MOD;
          sum[i + 1][1] %= MOD;
        }
        else {
          dp[i + 1][1] += dp[i][1];
          (dp[i + 1][1] += dp[i][0]) %= MOD;

          sum[i + 1][1] += (sum[i][1] * 10 % MOD +
                            dp[i][1] * numt % MOD) %
                           MOD;
          sum[i + 1][1] %= MOD;
          sum[i + 1][1] += (sum[i][0] * 10 % MOD +
                            dp[i][0] * numt % MOD) %
                           MOD;
          sum[i + 1][1] %= MOD;
        }
      }
    }
  }

  return (sum[ssize][1] + sum[ssize][0]) % MOD;
}