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
long long ans;
long long jc[4010];
long long c[4010][4010];
int w, n, b;
int main() {
  int i, j;
  for (i = 0; i <= 4000; ++i) {
    c[i][0] = 1;
    for (j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      if (c[i][j] >= 1000000009) c[i][j] -= 1000000009;
    }
  }
  jc[0] = 1;
  for (i = 1; i <= 4000; ++i) jc[i] = jc[i - 1] * i % 1000000009;
  scanf("%d%d%d", &n, &w, &b);
  for (i = 2; n - i; ++i)
    ans = (ans + c[w - 1][i - 1] * c[b - 1][n - i - 1] % 1000000009 * (i - 1)) %
          1000000009;
  ans = ans * jc[w] % 1000000009 * jc[b] % 1000000009;
  printf("%d\n", (int)ans);
  return 0;
}