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
const int N = 2e6 + 5;
const int mod = 1e9 + 7;
int n, a[N], pw[N];
long long ans;
int main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = (pw[i - 1] * 2ll) % mod;
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int j = 0; j < 20; j++) {
    for (int i = (1 << 20) - 1; i >= 0; i--) {
      if (i & (1 << j)) {
        a[i - (1 << j)] += a[i];
      }
    }
  }
  for (int i = 0; i < pw[20]; i++) {
    int bit = __builtin_popcount(i);
    if (bit & 1)
      ans -= pw[a[i]], ans = (ans + mod) % mod;
    else
      ans += pw[a[i]], ans = (ans + mod) % mod;
  }
  cout << ans << endl;
}