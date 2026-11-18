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
int c1, c2, x, y;
long long le, ri, mi;
long long nx, ny, nxy;
long long n1, n2, n_all;
int main() {
  ((void)0);
  cin >> c1 >> c2 >> x >> y;
  le = 1ll;
  ri = (long long)(1e10);
  while (ri - le > 1ll) {
    mi = (ri + le) / 2;
    nx = mi / x;
    ny = mi / y;
    nxy = nx / y;
    n1 = ny - nxy;
    n2 = nx - nxy;
    n_all = mi - nx - ny + nxy;
    if (max(0ll, c1 - n1) + max(0ll, c2 - n2) <= n_all)
      ri = mi;
    else
      le = mi;
  }
  cout << ri << endl;
  return 0;
}