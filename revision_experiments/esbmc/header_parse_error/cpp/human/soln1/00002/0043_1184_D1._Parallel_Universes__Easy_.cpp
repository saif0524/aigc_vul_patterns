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
  int n, k, m, t, i;
  scanf("%d%d%d%d", &n, &k, &m, &t);
  int a, b;
  for (i = 0; i < t; i++) {
    scanf("%d %d", &a, &b);
    if (a == 0) {
      if (b < k) {
        n -= b;
        k -= b;
      } else {
        n = b;
      }
    }
    if (a == 1) {
      if (b <= k) {
        n += 1;
        k += 1;
      } else {
        n += 1;
      }
    }
    printf("%d %d\n", n, k);
  }
  return 0;
}