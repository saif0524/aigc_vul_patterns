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
long long t1, t2, x1, x2, t0;
int main() {
  long long i;
  while (cin >> t1 >> t2 >> x1 >> x2 >> t0) {
    if (t2 == t0 && t0 != t1) {
      cout << "0"
           << " " << x2 << endl;
      continue;
    }
    if (t2 != t0 && t0 == t1) {
      cout << x1 << " "
           << "0" << endl;
      continue;
    }
    if (t2 == t0 && t0 == t1) {
      cout << x1 << " " << x2 << endl;
      continue;
    }
    long long y1, y2;
    double tt = 99999999;
    long long tmp;
    for (i = 0; i <= x1; i++) {
      if (i == 0)
        tmp = x2;
      else {
        tmp = i * (t0 - t1);
        if (tmp % (t2 - t0) != 0)
          tmp = (tmp / (t2 - t0)) + 1;
        else
          tmp = (tmp / (t2 - t0));
        if (tmp > x2 || tmp < 0) continue;
        if (tmp < 0)
          while (1)
            ;
      }
      double t;
      t = (tmp * 1.0 * t2 * 1.0 + i * 1.0 * t1 * 1.0) * 1.0 /
          (i * 1.0 + tmp * 1.0);
      if (t >= t0 * 1.0 && t < tt) {
        y1 = i, y2 = tmp;
        tt = t;
      } else if (t >= t0 * 1.0 && fabs(t - tt) < 1e-20) {
        if (i + tmp > y1 + y2) {
          y1 = i, y2 = tmp;
          tt = t;
        }
      }
    }
    cout << y1 << " " << y2 << endl;
  }
  return 0;
}