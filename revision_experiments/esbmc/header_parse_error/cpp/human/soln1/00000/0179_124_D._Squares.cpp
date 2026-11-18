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
int f(string s) {
  int k = 0;
  for (int i = 0; i < s.size(); i++) k = 10 * k + int(s[i]) - 48;
  return k;
}
int main() {
  int n, k, l, m, i, j;
  int x3, y3, x4, y4, a, b, x1, x2, y1, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  if (x1 + y1 >= 0)
    x3 = (x1 + y1) / (2 * a);
  else
    x3 = (x1 + y1) / (2 * a) - 1;
  if (x1 - y1 >= 0)
    y3 = (x1 - y1) / (2 * b);
  else
    y3 = (x1 - y1) / (2 * b) - 1;
  if (x2 + y2 >= 0)
    x4 = (x2 + y2) / (2 * a);
  else
    x4 = (x2 + y2) / (2 * a) - 1;
  if (x2 - y2 >= 0)
    y4 = (x2 - y2) / (2 * b);
  else
    y4 = (x2 - y2) / (2 * b) - 1;
  k = max(abs(x3 - x4), abs(y3 - y4));
  cout << k;
  return 0;
}