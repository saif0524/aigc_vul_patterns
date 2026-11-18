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
const int maxn = 1000100;
long long result, n, m;
long long deg[maxn + 1];
int main() {
  long long i, j, k, x, y;
  scanf("%I64d%I64d", &n, &m);
  for (i = 1; i <= n; ++i) deg[i] = 0;
  for (i = 1; i <= m; ++i) {
    scanf("%I64d%I64d", &x, &y);
    ++deg[x];
    ++deg[y];
  }
  result = 0;
  for (i = 1; i <= n; ++i) {
    result += deg[i] * (n - 1 - deg[i]);
  }
  result = n * (n - 1) * (n - 2) / 6 - result / 2;
  printf("%I64d\n", result);
  return 0;
}