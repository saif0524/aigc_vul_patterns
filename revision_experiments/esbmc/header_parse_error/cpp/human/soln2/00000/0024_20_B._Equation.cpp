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
  double A, B, C;
  cin >> A >> B >> C;
  if (A == 0 && B == 0 && C == 0) {
    cout << "-1";
    return 0;
  }
  if (A == 0 && B == 0 && C != 0) {
    cout << "0";
    return 0;
  }
  if (A == 0) {
    double z = (-C) / B;
    printf("1\n%.10lf", z);
    return 0;
  } else {
    double der = (B * B - 4 * A * C);
    if (der < 0) {
      cout << 0;
      return 0;
    }
    if (der == 0) {
      printf("1\n%.10lf", (-B) / (2 * A));
    }
    if (der > 0) {
      double x1 = (-B + sqrt(der)) / (2 * A), x2 = (-B - sqrt(der)) / (2 * A);
      double q = min(x1, x2), p = max(x1, x2);
      printf("2\n%.10lf\n%.10lf", q, p);
    }
  }
  return 0;
}