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
pair<long long, long long> res;
long long my_pow(long long x) { return x * x * x; }
void dfs(long long m, long long s, long long v) {
  int x = 0;
  if (m <= 0) {
    res = max(res, make_pair(s, v));
    return;
  }
  while (my_pow(x + 1) <= m) {
    x++;
  }
  dfs(m - my_pow(x), s + 1, v + my_pow(x));
  if (x - 1 > 0) {
    dfs(my_pow(x) - 1 - my_pow(x - 1), s + 1, v + my_pow(x - 1));
  }
}
int main() {
  long long m, i, t, j, N = 0, X = 0, ansn = 0, ansX = 0, flag = 0, k, l;
  scanf("%I64d", &m);
  dfs(m, 0, 0);
  printf("%I64d %I64d\n", res.first, res.second);
}