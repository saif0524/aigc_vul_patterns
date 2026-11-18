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
int n, m, d, a[1005], c[1005], i, j, k, l, sum;
int main() {
  for (scanf("%d%d%d", &n, &m, &d), i = 0; i < m; i++)
    scanf("%d", &c[i]), sum += c[i];
  if (sum + (d - 1) * (m + 1) < n || sum > n) {
    printf("NO\n");
    return 0;
  } else
    printf("YES\n");
  for (i = j = 0; i < n; i++) {
    bool b = false;
    if (sum + j >= n) {
      i--;
      break;
    }
    j += d - 1;
    sum -= c[i];
    for (k = j; k - j < c[i]; k++) {
      if (k + sum >= n) {
        for (k = j; k + sum < n; k++) a[k] = 0;
        i--;
        b = true;
        break;
      }
      a[k] = i + 1;
    }
    j = k;
    if (b) break;
  }
  k = j = n - 1;
  for (l = m - 1; l > i; l--) {
    for (k = j; j - k < c[l]; k--) a[k] = l + 1;
    j = k;
  }
  for (i = 0; i < n; i++) printf("%d ", a[i]);
  return 0;
}