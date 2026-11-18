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
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int inf = 2147483647 - 1;
const int maxn = 3e5 + 10;
int a[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    int l, r;
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= i - 1)
        l = i;
      else
        break;
    }
    for (int i = n; i; --i) {
      if (a[i] >= n - i)
        r = i;
      else
        break;
    }
    if (l >= r)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}