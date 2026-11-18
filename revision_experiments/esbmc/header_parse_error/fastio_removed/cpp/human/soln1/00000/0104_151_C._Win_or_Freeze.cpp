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
  register int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
bool prim(long long x) {
  if (x == 1ll || x == 4ll) return false;
  if (x <= 5ll) return true;
  int m = (int)sqrt(x);
  if (x % 6 != 1 && x % 6 != 5) return false;
  for (int i = 5; i <= m; i += 6) {
    if ((x % i == 0) || (x % (i + 2) == 0)) return false;
  }
  return true;
}
bool pr[10000000];
void prime(int n) {
  pr[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!pr[i]) {
      for (int j = 2; j * i <= n; j++) {
        pr[i * j] = true;
      }
    }
  }
}
int32_t main() {
  ((void)0);
  ((void)0);
  ((void)0);
  long long x;
  cin >> x;
  if (x == 1) {
    cout << 1 << '\n' << 0 << '\n';
  } else if (prim(x)) {
    cout << 1 << '\n';
    cout << 0 << '\n';
  } else {
    prime((int)sqrt(x));
    int res = 0, b = -1, up = -1;
    for (int i = 2; i * 1ll * i <= x; ++i) {
      if (!pr[i] && (x % (i * 1ll) == 0)) {
        res++;
        if (up == -1)
          up = i;
        else if (b == -1)
          b = i;
      }
      if (res >= 3) break;
    }
    if (res < 1) {
      cout << 2 << '\n';
    } else if (res == 1) {
      if (x % (up * up * 1ll) == 0 && (up * up) != x) {
        cout << 1 << '\n';
        cout << up * 1ll * up << '\n';
      } else {
        cout << 2 << '\n';
      }
    } else if (res == 2 && up * 1ll * b == x) {
      cout << 2 << '\n';
    } else {
      cout << 1 << '\n';
      cout << up * 1ll * b << '\n';
    }
  }
  return 0;
}