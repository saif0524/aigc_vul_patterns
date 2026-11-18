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
inline int rd() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' && c != '-') c = getchar();
  if (c == '-') f = 1, c = getchar();
  while (c >= '0') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
long long n;
long long tmp[1000];
void _main() {
  int Case;
  scanf("%d", &Case);
  while (Case--) {
    scanf("%lld", &n);
    int len = 0;
    long long L = 1, R = n - 1, res = n;
    ;
    while (L <= R) {
      long long mid = (L + R) >> 1;
      tmp[++len] = mid;
      L = mid + 1;
    }
    long long pos = 1;
    int now = 0;
    for (register int i = len, _n = 1; i >= _n; --i) {
      if (now == 0)
        pos += tmp[i];
      else
        pos -= tmp[i];
      now ^= 1;
    }
    L = 1, R = n - 1;
    printf("? %lld", pos);
    std::cout << std::endl;
    int ins = rd();
    while (L <= R) {
      long long mid = (L + R) >> 1;
      if (now == 0)
        pos += mid;
      else
        pos -= mid;
      now ^= 1;
      printf("? %lld", pos);
      std::cout << std::endl;
      int ins = rd();
      if (ins == 1)
        res = mid, R = mid - 1;
      else
        L = mid + 1;
    }
    printf("= %lld", res);
    std::cout << std::endl;
  }
}
int main() {
  _main();
  return 0;
}