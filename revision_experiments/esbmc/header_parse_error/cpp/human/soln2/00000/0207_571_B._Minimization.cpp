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
int n, k;
int a[1 << 20];
int sz[1 << 20];
int cnt1, cnt2, sz1, sz2;
bool used[5124][5124];
long long state[5124][5124];
long long all;
long long diff[1 << 20];
long long recurse(int pos, int cnt1, int cnt2) {
  if (pos >= n) return 0;
  if (used[cnt1][cnt2]) return state[cnt1][cnt2];
  long long ans = 0;
  if (cnt1 > 0)
    if (pos + sz1 - 1 >= pos)
      ans = max(ans, a[pos + sz1] - a[pos + sz1 - 1] +
                         recurse(pos + sz1, cnt1 - 1, cnt2));
  if (cnt2 > 0)
    if (pos + sz2 - 1 >= pos)
      ans = max(ans, a[pos + sz2] - a[pos + sz2 - 1] +
                         recurse(pos + sz2, cnt1, cnt2 - 1));
  used[cnt1][cnt2] = true;
  state[cnt1][cnt2] = ans;
  return ans;
}
int main() {
  int i;
  scanf("%d %d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (i = 2; i <= n; i++) diff[i] = diff[i - 1] + a[i] - a[i - 1];
  for (i = 2; i <= n; i++) all += a[i] - a[i - 1];
  for (i = 1; i <= n; i++) {
    sz[i % k]++;
  }
  sz1 = (n + k - 1) / k;
  sz2 = sz1 - 1;
  for (i = 0; i < k; i++) {
    if (sz[i % k] == sz1)
      cnt1++;
    else
      cnt2++;
  }
  printf("%I64d\n", all - recurse(1, cnt1, cnt2));
  return 0;
}