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
const int NMAX = 1e6 + 4;
const int P = 131;
const long long MOD = 19260817;
char s[NMAX];
int ans[NMAX], cnt, l, r, n;
long long x, y, p[NMAX], sum[NMAX];
void myhash() {
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * P % MOD;
    sum[i] = (sum[i - 1] * P % MOD + s[i] - 'a' + 1);
  }
}
long long hs(int l, int r) {
  return (sum[r] - sum[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
}
int main() {
  scanf("%d%s", &n, s + 1);
  myhash();
  cnt = (n + 1) >> 1;
  if (n & 1)
    ans[cnt] = -1, l = r = cnt;
  else {
    l = n >> 1, r = l + 1;
    if (s[l] == s[r])
      ans[cnt] = 1;
    else
      ans[cnt] = -1;
  }
  for (int i = cnt - 1; i >= 1; i--) {
    l--, r++;
    for (int j = ans[i + 1] + 2; j >= -1; j -= 2) {
      x = hs(l, l + j - 1), y = hs(r - j + 1, r);
      if (x == y || j == -1) {
        ans[i] = j;
        break;
      }
    }
  }
  for (int i = 1; i <= cnt; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}