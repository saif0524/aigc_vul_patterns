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
  int n, i, j;
  int a[110][110];
  long long ans[150];
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    memset(ans, 0, sizeof(ans));
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (i == j) continue;
        if (a[i][j] == -1) continue;
        ans[i] = ans[i] | a[i][j];
      }
    }
    for (i = 1; i <= n; i++)
      if (i == 1)
        printf("%I64d", ans[i]);
      else
        printf(" %I64d", ans[i]);
    printf("\n");
  }
  return 0;
}