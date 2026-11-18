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
#pragma warning(disable : 4996)
using namespace std;
const unsigned long long nmax = 200002;
unsigned long long n, k, a[nmax], s[nmax], t[nmax], c[nmax], r = UINT64_MAX, A,
                                                             B;
int main() {
  scanf("%llu%llu", &n, &k);
  for (unsigned long long i = 1; i <= n; ++i) scanf("%llu", a + i);
  sort(a + 1, a + n + 1);
  for (unsigned long long i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
  for (unsigned long long i = n; i >= 1; --i) t[i] = t[i + 1] + a[i];
  for (unsigned long long i = 1; i <= n; ++i) {
    if (a[i] == a[i - 1])
      c[i] = c[i - 1] + 1;
    else
      c[i] = 1;
    if (c[i] >= k) {
      puts("0");
      return 0;
    }
  }
  for (unsigned long long i = 1; i <= n; ++i) {
    if (i >= k) {
      A = i * a[i] - s[i] - (i - k);
      r = min(r, A);
    }
    if (n - i + 1 >= k) {
      B = t[i] - (n - i + 1) * a[i] - (n - i + 1 - k);
      r = min(r, B);
    }
    r = min(r, i * a[i] - s[i] + t[i] - (n - i + 1) * a[i] - (n - k));
  }
  printf("%llu\n", r);
  return 0;
}