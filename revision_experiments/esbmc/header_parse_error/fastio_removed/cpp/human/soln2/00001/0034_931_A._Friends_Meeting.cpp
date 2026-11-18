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
int main() {
  ((void)0);
  ((void)0);
  int aa, bb;
  int sm = 0;
  cin >> aa >> bb;
  int a = min(aa, bb), b = max(aa, bb);
  int ca = 1;
  int cb = 1;
  while (a < b) {
    int ax = 1e9;
    int bx = 1e9;
    if (a + 1 == b)
      ax = ca;
    else if (b - 1 == a)
      bx = cb;
    if (a + 1 == b || b - 1 == a) {
      if (ax < bx) {
        sm += ca;
        ++ca;
        ++a;
      } else {
        sm += cb;
        ++cb;
        --b;
      }
    } else {
      sm += ca;
      ++ca;
      ++a;
      sm += cb;
      ++cb;
      --b;
    }
  }
  cout << sm << '\n';
  return 0;
}