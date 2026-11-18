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
long long memo[(1 << 21)];
long long modexp(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = ((res % 1000000007) * (a % 1000000007)) % 1000000007;
    a = ((a % 1000000007) * (a % 1000000007)) % 1000000007;
    n >>= 1;
  }
  return res;
}
int main(void) {
  ((void)0);
  ((void)0);
  ((void)0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    memo[t]++;
  }
  for (int p = 0; p < 21; p++) {
    for (int mask = ((1 << 21) - 1); mask >= 0; mask--) {
      if (!(mask & (1 << p))) memo[mask] += memo[mask ^ (1 << p)];
    }
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << 21); mask++) {
    int z = __builtin_popcount(mask);
    if (z & 1)
      ans = ((ans % 1000000007) - (modexp(2, memo[mask]) % 1000000007) +
             1000000007) %
            1000000007;
    else
      ans = ((ans % 1000000007) + (modexp(2, memo[mask]) % 1000000007)) %
            1000000007;
  }
  std::cout << ans << "\n";
  return 0;
}