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
int n, k, d, tot, a[1010], ans[1010][1010];
void tr(int x) {
  if (x > d) {
    ++tot;
    for (int i = 1; i <= d; ++i) ans[i][tot] = a[i];
    return;
  }
  for (int i = 1; i <= k; ++i) {
    a[x] = i;
    tr(x + 1);
    if (tot >= n) return;
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &d);
  tr(1);
  if (tot < n)
    printf("-1\n");
  else {
    for (int i = 1; i <= d; ++i) {
      for (int j = 1; j <= n; ++j) {
        printf("%d", ans[i][j]);
        if (j == n)
          printf("\n");
        else
          printf(" ");
      }
    }
  }
  return 0;
}