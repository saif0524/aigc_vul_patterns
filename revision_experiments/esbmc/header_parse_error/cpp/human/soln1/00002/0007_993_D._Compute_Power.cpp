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
int n;
long long f[1000][1000], sum[1000];
struct arr {
  long long x, y;
} a[1000];
bool cmp(arr x, arr y) { return (x.x > y.x) || ((x.x == y.x) && (x.y > y.y)); }
int check(long long x) {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) f[i][j] = 10000000000000;
  f[0][0] = 0;
  for (int i = 1, j; i <= n; i = j) {
    for (j = i + 1; a[j].x == a[i].x && j <= n; ++j)
      ;
    for (int k = i; k < j; k++)
      sum[k - i + 1] = sum[k - i] + a[k].x - a[k].y * x;
    for (int k = 0; k <= n; k++)
      for (int ij = 0; ij <= min(k, j - i); ij++)
        f[j - 1][(k - ij) + (j - i) - ij] = min(
            f[j - 1][(k - ij) + (j - i) - ij], sum[(j - i) - ij] + f[i - 1][k]);
  }
  for (int i = 0; i <= n; i++)
    if (f[n][i] <= 0) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i].x);
    a[i].x *= 1000;
  }
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i].y);
  sort(a + 1, a + n + 1, cmp);
  long long l = 0, r = 100000000000, mid = (l + r) >> 1;
  do {
    if (check(mid))
      r = mid;
    else
      l = mid;
    mid = (l + r) >> 1;
  } while (l + 1 < r);
  printf("%lld", r);
  return 0;
}