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
namespace FGF {
int n, m, ans;
const int N = 3e5 + 5, mo = 998244353;
int a[N], f[N], inv[N];
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), m += a[i];
  inv[1] = 1;
  for (int i = 2; i <= m; i++) inv[i] = 1ll * inv[mo % i] * (mo - mo / i) % mo;
  for (long long i = 1, y; i < m; i++)
    y = i * (n - 1) % mo * inv[m - i] % mo,
    f[i + 1] =
        (((y + 1) % mo * f[i] % mo - y * (f[i - 1] + 1) % mo) % mo + mo) % mo;
  for (int i = 1; i <= n; i++) ans = (ans + f[a[i]]) % mo;
  printf("%d\n", (ans - f[m] + mo) % mo);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}