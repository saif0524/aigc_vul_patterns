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
const int maxn = 5e6 + 5;
int n, m;
long long d;
long long a[maxn], sum[maxn];
int main() {
  scanf("%d%d%lld", &n, &m, &d);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(&a[1], &a[n + 1]);
  int good = 1;
  sum[0] = 1;
  for (int i = 1, j = 1; i <= n; i++) {
    while (a[i] - a[j] > d) j++;
    good = sum[max(-1, i - m)] - sum[j - 2];
    sum[i] = sum[i - 1];
    if (good >= 1) sum[i]++;
  }
  if (good > 0)
    printf("YES");
  else
    printf("NO");
}