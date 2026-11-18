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
long long k, d, t;
int main() {
  scanf("%lld%lld%lld", &k, &d, &t);
  t *= 2;
  long long round = ceil((double)k / d) * d;
  long long num = k * 2 + (round - k);
  long long cnt = t / num;
  long long left = t - cnt * num;
  double ans = 0.0;
  if (left <= k * 2) {
    ans = cnt * round + left / 2;
    if (left % 2) ans += 0.5;
  } else
    ans = cnt * round + k + (left - k * 2);
  printf("%.1lf\n", ans);
  return 0;
}