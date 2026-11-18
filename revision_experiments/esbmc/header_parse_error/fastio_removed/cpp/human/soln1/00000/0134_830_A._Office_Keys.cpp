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
using i64 = long long;
class A830 {
 private:
  i64 cost(i64 a, i64 b, i64 c) { return abs(a - b) + abs(b - c); }

 public:
  void solve(istream& in, ostream& out) {
    int n, k, p;
    in >> n >> k >> p;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; ++i) {
      in >> a[i];
    }
    for (int i = 0; i < k; ++i) {
      in >> b[i];
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    i64 low = 0, high = 1e11, ans = high;
    while (low <= high) {
      i64 mid = (low + high) / 2;
      bool ok1 = true;
      for (int i = 0, j = 0; i < n; ++i) {
        while (j < k && cost(a[i], b[j], p) > mid) {
          ++j;
        }
        if (j == k) {
          ok1 = false;
          break;
        }
        ++j;
      }
      bool ok2 = true;
      for (int i = n - 1, j = k - 1; i >= 0; --i) {
        while (j >= 0 && cost(a[i], b[j], p) > mid) {
          --j;
        }
        if (j == -1) {
          ok2 = false;
          break;
        }
        --j;
      }
      if (ok1 || ok2) {
        high = mid - 1;
        ans = mid;
      } else {
        low = mid + 1;
      }
    }
    out << ans << "\n";
  }
};
int main() {
  ((void)0);
  ((void)0);
  A830 solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}