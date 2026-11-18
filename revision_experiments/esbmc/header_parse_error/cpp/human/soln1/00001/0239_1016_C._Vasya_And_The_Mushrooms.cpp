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
const int maxn = 3e5 + 100;
long long a[maxn], b[maxn], res;
long long sumaL[maxn], sumaR[maxn], sumbL[maxn], sumbR[maxn];
long long sal[maxn], sar[maxn], sbl[maxn], sbr[maxn];
void downToRight(long long ans, int i, int n, long long t) {
  ans += t * sumbR[i + 1] + sbr[i + 1] + (t + n - i) * sumaR[i] - sal[i - 1] +
         sal[n] - sumaL[i - 1] * (n - i + 1);
  res = max(res, ans);
}
void upToRight(long long ans, int i, int n, long long t) {
  ans += t * sumaR[i + 1] + sar[i + 1] + (t + n - i) * sumbR[i] - sbl[i - 1] +
         sbl[n] - sumbL[i - 1] * (n - i + 1);
  res = max(res, ans);
}
int main() {
  int n;
  int ca = 0;
  while (scanf("%d", &n) != EOF) {
    if (ca++) {
      sumaL[0] = sumaL[n + 1] = 0;
      sumbL[0] = sumbL[n + 1] = 0;
      sumaR[0] = sumaR[n + 1] = 0;
      sumbL[0] = sumbR[n + 1] = 0;
      sal[0] = sal[n + 1] = 0;
      sar[0] = sar[n + 1] = 0;
      sbl[0] = sbl[n + 1] = 0;
      sbr[0] = sbr[n + 1] = 0;
    }
    for (register int i = (1); i <= (n); ++i)
      scanf("%lld", a + i), sumaL[i] = sumaL[i - 1] + a[i];
    for (register int i = (1); i <= (n); ++i)
      scanf("%lld", b + i), sumbL[i] = sumbL[i - 1] + b[i];
    if (n == 1) {
      printf("%lld\n", b[1]);
      continue;
    }
    for (register int i = (n); i >= (1); --i)
      sumaR[i] = sumaR[i + 1] + a[i], sumbR[i] = sumbR[i + 1] + b[i];
    for (register int i = (1); i <= (n); ++i)
      sal[i] = sal[i - 1] + sumaL[i], sbl[i] = sbl[i - 1] + sumbL[i];
    for (register int i = (n); i >= (0); --i)
      sar[i] = sar[i + 1] + sumaR[i], sbr[i] = sbr[i + 1] + sumbR[i];
    res = 0;
    res = sar[2] + sbl[n] + sumbL[n] * (n - 1);
    long long t = 0;
    long long ans = 0;
    for (register int i = (1); i <= (n); ++i) {
      ++t;
      if (i & 1)
        ans += t * b[i];
      else
        ans += t * a[i];
      if (i == n) {
        res = max(res, ans);
        continue;
      }
      ++t;
      if (i & 1) {
        ans += t * b[i + 1];
        if (i < n - 1) downToRight(ans, i + 1, n, t);
      } else {
        ans += t * a[i + 1];
        if (i < n - 1) upToRight(ans, i + 1, n, t);
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}