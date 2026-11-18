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
  int d[32];
  int k = 0;
  int a, c;
  cin >> a >> c;
  while (a || c) {
    int r1 = a % 3, r2 = c % 3;
    for (int i = 0; i < 3; i++) {
      if ((r1 + i) % 3 == r2) {
        d[k++] = i;
        break;
      }
    }
    a /= 3;
    c /= 3;
  }
  long long ans = 0, p = 1;
  for (int i = 0; i < k; i++) {
    ans += d[i] * p;
    p *= 3;
  }
  cout << ans;
  return 0;
}