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
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 1e6 + 7;
int n, ans[N];
long long m;
int main() {
  scanf("%d%lld", &n, &m);
  long long Max = m;
  for (int i = 1; i <= n; i++) {
    ans[i] = i;
    m -= i;
  }
  if (m < 0) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n / 2; i++) {
    int now = (n - i + 1) - i;
    if (m <= now) {
      swap(ans[n - i + 1 - (now - m)], ans[i]);
      m = 0;
      break;
    }
    swap(ans[n - i + 1], ans[i]);
    m -= now;
  }
  printf("%lld\n", Max - m);
  for (int i = 1; i <= n; i++) printf("%d ", i);
  printf("\n");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}