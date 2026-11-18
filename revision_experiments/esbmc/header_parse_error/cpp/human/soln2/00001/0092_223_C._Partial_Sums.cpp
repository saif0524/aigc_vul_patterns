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
const int V = 2010;
const long long MOD = 1e9 + 7;
int n, k;
long long data[V][V];
int a[V], inv[V];
long long c[V];
void prepare() {
  inv[1] = 1;
  for (int i = 2; i < V; i++)
    inv[i] = (MOD - MOD / i) * inv[(int)(MOD % i)] % MOD;
}
long long C(long long x, int y) {
  long long ret = 1;
  for (int i = 0; i < y; ++i) {
    ret = ret * (x - i) % MOD * inv[i + 1] % MOD;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  prepare();
  for (int i = 0; i < n; ++i) c[i] = C(k + i - 1, i);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j)
      data[i][j] = (data[i][j] + c[j - i] * a[i]) % MOD;
  }
  for (int i = 0; i < n; ++i) {
    long long ret = 0;
    for (int j = 0; j < n; ++j) ret = (ret + data[j][i]) % MOD;
    if (i != 0) printf(" ");
    printf("%I64d", ret);
  }
  printf("\n");
}