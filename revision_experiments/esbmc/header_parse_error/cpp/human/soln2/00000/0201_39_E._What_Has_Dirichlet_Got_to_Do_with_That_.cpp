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
long long n, a, b;
int f[40001][41];
long long pow(long long a, long long b) {
  if (b == 0) return 1;
  long long t = pow(a, b >> 1);
  if (t >= n) return n;
  t *= t;
  if (b & 1) t *= a;
  if (t >= n) return n;
  return t;
}
long long min(long long a, long long b) { return a < b ? a : b; }
int dfs(long long a, long long b) {
  if (f[a][b] >= 0) return f[a][b];
  if (a == 1 && (1ll << b) >= n) return 1;
  if (a * a >= n && b == 1) return 2 - ((n - a) & 1) * 2;
  if (pow(a, b) >= n) return f[a][b] = 2;
  return f[a][b] = 2 - min(dfs(a + 1, b), dfs(a, b + 1));
}
int main() {
  int i, j, k;
  scanf("%I64d%I64d%I64d", &a, &b, &n);
  memset(f, -1, sizeof(f));
  switch (dfs(a, b)) {
    case 0:
      printf("Stas\n");
      break;
    case 1:
      printf("Missing\n");
      break;
    case 2:
      printf("Masha\n");
      break;
  }
  return 0;
}