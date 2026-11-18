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
long long sz[200005], n;
template <typename T>
inline void read(T& x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  x *= f;
}
inline long long query(long long x) {
  long long res = 0;
  while (x) {
    res += sz[x];
    x -= (x & (-x));
  }
  return res;
}
inline void add(long long x, long long val) {
  while (x <= n) {
    sz[x] += val;
    x += (x & (-x));
  }
}
int main() {
  cin >> n;
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    long long sum = 0;
    for (int j = 2; i * j <= n; j++) {
      sum += j;
    }
    ans += sum * 4;
  }
  cout << ans << endl;
  return 0;
}