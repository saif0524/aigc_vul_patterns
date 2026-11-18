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
template <typename T>
inline T abs(const T &a) {
  return a < 0 ? -a : a;
}
template <typename T>
inline T min(const T &b, const T &a) {
  return a < b ? a : b;
}
template <typename T>
inline T max(const T &a, const T &b) {
  return a < b ? b : a;
}
int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f = (ch == '-');
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 1) + (x << 3) + (ch - '0');
    ch = getchar();
  }
  return f ? -x : x;
}
void write(int x) {
  if (x < 0) {
    x = abs(x);
    putchar('-');
  }
  if (x < 10) {
    putchar(x + 48);
    return;
  }
  write(x / 10);
  putchar(x % 10 + 48);
}
const int Maxn = 1e5 + 11;
int t, n, a[Maxn];
int main() {
  ((void)0);
  cin >> t;
  while (t--) {
    int cnt = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i < n; ++i)
      if (a[i] != a[i - 1]) cnt++;
    cout << cnt << endl;
  }
}