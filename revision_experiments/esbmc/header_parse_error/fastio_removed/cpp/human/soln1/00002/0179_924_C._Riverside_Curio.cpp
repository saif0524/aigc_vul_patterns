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
const int MAXN = 10 + 1e5;
const int MOD = 1e9 + 7;
int n, m;
int a[MAXN], c[MAXN];
void Inout() {
  freopen(
      "ABC"
      ".inp",
      "r", stdin);
  freopen(
      "ABC"
      ".out",
      "w", stdout);
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    c[i] = max(c[i - 1], a[i] + 1);
  }
  for (int i = n - 1; i; --i) c[i] = max(c[i], c[i + 1] - 1);
  for (int i = 1; i <= n; ++i) {
    ans += c[i] - a[i] - 1;
  }
  cout << ans;
  return 0;
}