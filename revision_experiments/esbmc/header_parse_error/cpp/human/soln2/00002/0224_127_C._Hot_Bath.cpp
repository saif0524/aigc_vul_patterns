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
const double EPS = 1e-8;
int t1, t2, x1, x2, t0;
int main() {
  scanf("%d %d %d %d %d", &t1, &t2, &x1, &x2, &t0);
  long long k1 = t0 - t1, k2 = t2 - t0;
  if (k1 == 0) {
    printf("%d %d\n", x1, t1 == t2 ? x2 : 0);
  } else if (k2 == 0) {
    printf("%d %d\n", t1 == t2 ? x1 : 0, x2);
  } else {
    int y1 = 0, y2 = 0;
    long long t;
    double tt = 1e100;
    for (int i = 0; i <= x1; i++) {
      t = ((k1 * 1.0 / k2) * i);
      if ((k1 * 1.0 / k2) * i - t > EPS) t++;
      if (i == 0) t = x2;
      if (t > x2) continue;
      double tmp =
          (((long long)(t1)*i + (long long)(t2)*t) * 1.0) / (i + t + 0.0);
      if (tmp - tt < 0) {
        y1 = i;
        y2 = t;
        tt = tmp;
      } else if (abs(tmp - tt) <= EPS) {
        if (i + t > y1 + y2) {
          y1 = i;
          y2 = t;
        }
      }
    }
    printf("%d %d\n", y1, y2);
  }
  return 0;
}