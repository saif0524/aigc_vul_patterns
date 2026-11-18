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
int n;
struct point {
  long long x, y;
} num[400010], tem[400010], bb[400010];
point operator-(point a, point b) { return (point){a.x - b.x, a.y - b.y}; }
long long operator*(point a, point b) { return a.x * b.y - a.y * b.x; }
bool cmp2(point a, point b) {
  return (a * b) < 0 ||
         ((a * b) == 0 && (a.x < b.x || (a.x == b.x && a.y < b.y)));
}
int stk[400020], top, ttop, tstk[400020];
void gethull(int n, point *num, bool add) {
  std::sort(num + 1, num + n + 1, cmp2);
  top = 0;
  stk[++top] = 0;
  num[0] = (point){0, 0};
  for (int i = 1; i <= n; i++) {
    while (top > 1 &&
           (num[i] - num[stk[top - 1]]) * (num[stk[top]] - num[stk[top - 1]]) <=
               0) {
      if (add) tem[++ttop] = num[stk[top]];
      --top;
    }
    stk[++top] = i;
  }
  for (int i = 1; i <= top; i++) {
    if (num[stk[i]].x % 2 == 1 || num[stk[i]].y % 2 == 1) {
      puts("Ani");
      exit(0);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &num[i].x, &num[i].y);
  }
  gethull(n, num, 1);
  memcpy(tstk, stk, sizeof stk);
  int now = ttop, siz = top;
  memcpy(bb, tem, sizeof tem);
  for (int i = 1; i <= siz; i += 2)
    if (num[tstk[i]].x || num[tstk[i]].y) bb[++now] = num[tstk[i]];
  gethull(now, bb, 0);
  for (int i = 2; i <= siz; i += 2)
    if (num[tstk[i]].x || num[tstk[i]].y) tem[++ttop] = num[tstk[i]];
  gethull(ttop, tem, 0);
  puts("Borna");
}