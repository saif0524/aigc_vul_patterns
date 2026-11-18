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
int a[100005], b[100005], ans[100005];
int main() {
  int mod, n, m, i, j, sum = 0;
  scanf("%d %d %d", &n, &m, &mod);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < m; i++) scanf("%d", &b[i]);
  for (i = 0; i < n; i++) {
    if (i < m) sum += b[i];
    if (i >= n - m + 1) sum -= b[i - (n - m + 1)];
    if (sum < 0) sum += mod;
    sum %= mod;
    ans[i] = (a[i] + sum) % mod;
  }
  for (i = 0; i < n; i++) printf("%d ", ans[i]);
}