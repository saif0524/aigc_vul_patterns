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
int a[1000000];
int aa[1000000];
int g[1000000];
int gg[1000000];
char ans[1000001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i], &g[i]);
    if (i == 0) {
      aa[i] = a[i];
      gg[i] = g[i];
    } else {
      aa[i] = aa[i - 1] + a[i];
      gg[i] = gg[i - 1] + g[i];
    }
  }
  int tot = 0;
  int i;
  for (i = 0; i < n; ++i) {
    if (tot + a[i] - (gg[n - 1] - gg[i]) <= 500) {
      tot += a[i];
      ans[i] = 'A';
    } else if (tot - g[i] + (aa[n - 1] - aa[i]) >= -500) {
      tot -= g[i];
      ans[i] = 'G';
    } else {
      break;
    }
  }
  ans[n] = '\0';
  if (i != n)
    printf("-1\n");
  else
    printf("%s\n", ans);
  return 0;
}