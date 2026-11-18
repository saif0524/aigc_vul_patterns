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
int a[300500];
int s[300500];
long long o[2];
long long ans;
int n;
int main() {
  scanf("%i", &n);
  for (int i = 1; i <= n; ++i) {
    long long x;
    scanf("%lld", &x);
    while (x) {
      a[i] += x & 1;
      x = x >> 1;
    }
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; ++i) o[s[i] % 2]++;
  ans = o[0] * (o[0] - 1) / 2 + o[1] * (o[1] - 1) / 2 + o[0];
  for (int l, r, i = 1; i <= n; ++i) {
    int q, t;
    q = a[i];
    t = 0;
    for (l = 1; i - l >= 1; l++) {
      if (q - t - a[i - l] <= 0) break;
      t += a[i - l];
    }
    l--;
    t = 0;
    for (r = 1; i + r <= n; r++) {
      if (q - t - a[i + r] <= 0) break;
      t += a[i + r];
    }
    r--;
    for (int l1 = 0; l1 <= l; ++l1)
      for (int r1 = 0; r1 <= r; ++r1) {
        int v = s[i + r1] - s[i - l1 - 1];
        if (v % 2 == 0 && a[i] > v - a[i]) ans--;
      }
  }
  printf("%lld\n", ans);
}