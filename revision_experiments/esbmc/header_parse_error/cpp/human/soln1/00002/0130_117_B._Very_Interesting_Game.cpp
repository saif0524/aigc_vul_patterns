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
int const MAX = 1000 * 1000 * 1000;
int main() {
  long long a, b, m, i;
  cin >> a >> b >> m;
  if (m <= b + 1 || MAX % m == 0) {
    cout << 2;
    return 0;
  }
  for (i = 1; i <= min(m - 1, a); ++i) {
    int k = MAX * i % m;
    if (0 < k && k < m - b) {
      printf("1\n%09I64d", i);
      return 0;
    }
  }
  cout << 2;
  return 0;
}