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
long a[100001], b[100001];
long m, n, c;
int main() {
  long k, i, j, s, x;
  scanf("%ld %ld %ld", &n, &m, &c);
  for (i = 1; i <= n; i++) scanf("%ld", &a[i]);
  b[0] = 0;
  for (i = 1; i <= m; i++) scanf("%ld", &b[i]);
  s = 0;
  for (i = 1; i <= n; i++) {
    if (i <= m) s += b[i];
    x = i - (n - m + 1);
    if (x > 0) s -= b[x];
    s += c;
    a[i] += s;
    a[i] = a[i] % c;
  }
  printf("%ld", a[1] % c);
  for (i = 2; i <= n; i++) {
    a[i] = a[i] % c;
    printf(" %ld", a[i]);
  }
  printf("\n");
}