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
int n, m, a[55], b[55], x;
long double f[55][5050], c[55], now, res;
void doit() {
  for (int i = 0; i <= m; i++) f[n + 1][i] = 0;
  for (int i = n; i > 0; i--) {
    for (int j = 0; j <= m; j++) {
      f[i][j] =
          c[i] * (a[i] + (j + a[i] > m ? now : min(f[i + 1][j + a[i]], now)));
      f[i][j] += (1 - c[i]) *
                 (b[i] + (j + b[i] > m ? now : min(f[i + 1][j + b[i]], now)));
    }
  }
  res = f[1][0];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", a + i, b + i, &x);
    c[i] = x / 100.0;
  }
  long double l = 0.0, r = 1000000000.0;
  for (int i = 1; i <= 233; i++) {
    now = (l + r) / 2.0;
    doit();
    if (res > now) {
      l = now;
    } else {
      r = now;
    }
  }
  printf("%.233lf", (double)l);
}