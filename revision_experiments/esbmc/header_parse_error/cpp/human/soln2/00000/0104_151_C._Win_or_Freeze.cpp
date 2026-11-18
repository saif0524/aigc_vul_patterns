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
int main() {
  long long p, q, i, j, I, J;
  scanf("%I64d", &q);
  I = sqrt(q);
  for (i = 2LL; i <= I; ++i) {
    if (q % i == 0LL) {
      p = q / i;
      J = sqrt(p);
      for (j = 2LL; j <= J; ++j) {
        if (p % j == 0LL) {
          printf("1\n%I64d\n", i * j);
          return 0;
        }
      }
      puts("2");
      return 0;
    }
  }
  puts("1\n0\n");
  return 0;
}