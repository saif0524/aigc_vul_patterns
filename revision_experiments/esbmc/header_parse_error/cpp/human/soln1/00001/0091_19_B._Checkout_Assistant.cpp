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
const long long INFL = 1152921504606846976ll;
int n;
int t[(1 << 11)], c[(1 << 11)];
long long dp[(1 << 11)];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    dp[i] = INFL;
  }
  dp[0] = 0ll;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &t[i], &c[i]);
    for (int j = n - 1; j >= 0; j--) {
      int tmp;
      if (j + t[i] + 1 > n) {
        tmp = n;
      } else {
        tmp = j + t[i] + 1;
      }
      dp[tmp] = (long long)min((long long)dp[tmp],
                               (long long)dp[j] + (long long)c[i]);
    }
  }
  printf("%I64d\n", dp[n]);
  return 0;
}