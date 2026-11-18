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
bool get(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return 0;
  if (!get(b, a % b)) return 1;
  if (b % 2)
    return a / b % 2 == 0;
  else
    return a / b % (b + 1) % 2 == 0;
}
int main() {
  int t;
  long long a, b;
  for (scanf("%d", &t); t--; scanf("%I64d%I64d", &a, &b),
                             printf("%s\n", get(a, b) ? "First" : "Second"))
    ;
  return 0;
}