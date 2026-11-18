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
long long c[maxn];
bool cmp(const int &a, const int &b) { return a > b; }
long long dp[maxn];
int main() {
  int a, b, h, w, n;
  scanf("%d%d%d%d%d", &h, &w, &a, &b, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  sort(c + 1, c + 1 + n, cmp);
  memset(dp, -1, sizeof(dp));
  if (h > w) swap(h, w);
  if (a > b) swap(a, b);
  if (a > w) a = w;
  if (b > w) b = w;
  dp[a] = b;
  dp[b] = a;
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    if (dp[h] >= w || dp[w] >= h) {
      ans = i - 1;
      break;
    }
    for (int j = w - 1; j >= a; j--) {
      if (dp[j] == -1) continue;
      int nxt;
      if (c[i] * j >= w)
        nxt = w;
      else
        nxt = c[i] * j;
      if (dp[nxt] == -1 || dp[nxt] < dp[j]) dp[nxt] = dp[j];
      dp[j] = min(dp[j] * c[i], (long long)w);
    }
  }
  if (ans == -1 && (dp[h] >= w || dp[w] >= h)) ans = n;
  printf("%d\n", ans);
  return 0;
}