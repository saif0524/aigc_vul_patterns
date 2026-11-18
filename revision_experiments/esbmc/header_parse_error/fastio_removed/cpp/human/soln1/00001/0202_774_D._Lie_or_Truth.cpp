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
const long long mod = 1e9 + 7;
int32_t main() {
  ((void)0);
  ((void)0);
  ((void)0);
  ;
  long long n, l, r;
  cin >> n >> l >> r;
  std::vector<long long> v(n);
  std::vector<long long> v1(n);
  long long f = 1;
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (long long i = 0; i < n; ++i) {
    cin >> v1[i];
  }
  for (long long i = 0; i < n; ++i) {
    if ((v[i] != v1[i]) && (i < l - 1 || i > r - 1)) {
      f = 0;
      break;
    }
  }
  if (f) {
    cout << "TRUTH";
  } else {
    cout << "LIE";
  }
  return 0;
}