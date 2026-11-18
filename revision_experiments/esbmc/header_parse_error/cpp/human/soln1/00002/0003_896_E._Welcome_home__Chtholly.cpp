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
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
using namespace std;
int a[100010], n, m;
int main() {
  register int i;
  float x;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (register int k, l, r, s; m--;) {
    scanf("%d%d%d%f", &k, &l, &r, &x);
    if (k == 1)
      for (i = l; i <= r; ++i) a[i] -= a[i] > x ? x : 0;
    else {
      for (s = 0, i = l; i <= r; ++i) a[i] == x ? ++s : 0;
      printf("%d\n", s);
    }
  }
}