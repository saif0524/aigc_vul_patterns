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
const int maxn = 100010;
const int mod = 998244353;
int n, a[maxn];
int len[maxn];
long long val[maxn], p10[50];
int cal(int x) {
  int len = 0;
  while (x) {
    val[++len] += x % 10;
    x /= 10;
  }
  return len;
}
void init() {
  p10[0] = 1;
  for (int i = 1; i <= 30; i++) p10[i] = p10[i - 1] * 10 % mod;
}
int main() {
  init();
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      len[i] = cal(a[i]);
    }
    long long ans = 0;
    for (int k = 1; k <= 30; k++) {
      for (int i = 1; i <= n; i++) {
        if (k <= len[i])
          ans += p10[(k - 1) * 2] * 11 % mod * val[k] % mod, ans %= mod;
        else
          ans += p10[k + len[i] - 1] * 2 % mod * val[k] % mod, ans %= mod;
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}