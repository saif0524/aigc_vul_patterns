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
  double D;
  cin >> A >> B >> C;
  double x1, x2;
  if (!A) {
    if (!B) {
      if (!C) {
        printf("-1");
        return 0;
      } else {
        printf("0");
        return 0;
      }
    } else {
      printf("1\n");
      printf("%lf", -C / B);
    }
  } else {
    D = pow(B, 2) - (4 * A * C);
    if (D < 0) {
      printf("0");
      return 0;
    } else {
      D = sqrt(D);
    }
    x1 = (-B + D) / (2 * A);
    x2 = (-B - D) / (2 * A);
    if (x1 == x2) {
      cout << "1" << endl;
      printf("%lf", x1);
    } else {
      (x1 > x2) ? printf("2\n%lf\n%lf", x2, x1) : printf("2\n%lf\n%lf", x1, x2);
    }
  }
}