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
const int maxn = 1e6 + 5;
map<int, int> mp;
int a[maxn], g[maxn], h[maxn];
int main() {
  int n;
  scanf("%d", &n);
  int tot = 0;
  mp.clear();
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (mp[a[i]] == 0) {
      mp[a[i]] = ++tot;
      h[tot] = a[i];
    }
  }
  for (int i = 1; i <= n; i++) g[i] = mp[a[i]];
  bool flag = true;
  for (int i = 1; i <= tot; i++) {
    if (g[h[i]] != i) {
      flag = false;
      break;
    }
  }
  if (!flag)
    puts("-1");
  else {
    printf("%d\n", tot);
    for (int i = 1; i <= n; i++) printf("%d%c", g[i], i != n ? ' ' : '\n');
    for (int i = 1; i <= tot; i++) printf("%d%c", h[i], i != tot ? ' ' : '\n');
  }
  return 0;
}