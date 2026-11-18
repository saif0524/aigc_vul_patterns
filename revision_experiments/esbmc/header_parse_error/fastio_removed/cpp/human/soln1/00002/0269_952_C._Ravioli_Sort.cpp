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
int n, a[111];
bool u[111];
bool pr(int x) {
  int y = -1, z = -1;
  for (int i = x; i < n; ++i)
    if (!u[i]) {
      y = a[i];
      break;
    }
  for (int i = x; i >= 0; --i)
    if (!u[i]) {
      z = a[i];
      break;
    }
  if (y < 0 || z < 0)
    return 0;
  else
    return abs(y - z) > 1;
}
int main() {
  ((void)0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i > 0)
      if (abs(a[i] - a[i - 1]) > 1) return cout << "NO", 0;
  }
  for (int i = 0; i < n; ++i) {
    int mx = 0, mi;
    for (int j = 0; j < n; ++j)
      if (a[j] > mx && !u[j]) {
        mx = a[j];
        mi = j;
      }
    u[mi] = 1;
    if (pr(mi)) return cout << "NO", 0;
  }
  cout << "YES";
  return 0;
}