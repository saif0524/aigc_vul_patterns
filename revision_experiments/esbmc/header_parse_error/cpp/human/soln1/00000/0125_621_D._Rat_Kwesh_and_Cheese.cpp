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
class Solver621D {
 public:
  void run();
};
void Solver621D::run() {
  vector<string> formulas = {"x^y^z",   "x^z^y", "(x^y)^z", "y^x^z",  "y^z^x",
                             "(y^x)^z", "z^x^y", "z^y^x",   "(z^x)^y"};
  vector<function<complex<double>(complex<double>, complex<double>,
                                  complex<double>)>>
      functors = {
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(x)) + z * log(y);
          },
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(x)) + y * log(z);
          },
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(x)) + log(y) + log(z);
          },
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(y)) + z * log(x);
          },
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(y)) + x * log(z);
          },
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(y)) + log(x) + log(z);
          },
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(z)) + y * log(x);
          },
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(z)) + x * log(y);
          },
          [](complex<double> x, complex<double> y, complex<double> z) {
            return log(log(z)) + log(x) + log(y);
          },
      };
  double xr, yr, zr;
  cin >> xr >> yr >> zr;
  complex<double> x = {xr, 0.0}, y = {yr, 0.0}, z = {zr, 0.0};
  vector<complex<double>> results;
  for (auto f : functors) results.push_back(f(x, y, z));
  auto compareExponentsOf = [](complex<double> a, complex<double> b) -> bool {
    double aSign = abs(a.imag()) > 0.001 ? -1.0 : 1.0;
    double bSign = abs(b.imag()) > 0.001 ? -1.0 : 1.0;
    if (aSign == bSign)
      return (a.real() * aSign < b.real() * bSign);
    else
      return aSign < bSign;
  };
  auto maxIndex =
      max_element(begin(results), end(results), compareExponentsOf) -
      begin(results);
  cout << formulas[maxIndex];
}
using CurrentSolver = Solver621D;
int main() {
  ios::sync_with_stdio(false);
  CurrentSolver().run();
  return 0;
}