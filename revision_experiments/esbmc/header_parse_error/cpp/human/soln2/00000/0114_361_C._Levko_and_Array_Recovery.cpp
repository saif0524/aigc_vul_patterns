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
int p[5005], ans[5005];
int cmd[5005], l[5005], r[5005], num[5005];
bool vis[5005], flag;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d%d%d%d", &cmd[i], &l[i], &r[i], &num[i]);
  for (int i = 1; i <= n; i++) p[i] = -10000000;
  for (int i = m - 1; i >= 0; i--) {
    if (cmd[i] == 1) {
      for (int j = l[i]; j <= r[i]; j++) p[j] -= num[i];
    } else {
      for (int j = l[i]; j <= r[i]; j++) {
        if (vis[j] && p[j] <= num[i]) continue;
        p[j] = num[i];
        vis[j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) ans[i] = p[i];
  for (int i = 0; i < m; i++) {
    if (cmd[i] == 1) {
      for (int j = l[i]; j <= r[i]; j++) p[j] += num[i];
    } else {
      int ma = -100000000;
      for (int j = l[i]; j <= r[i]; j++) ma = max(ma, p[j]);
      if (ma != num[i]) {
        flag = 1;
        break;
      }
    }
  }
  if (flag)
    puts("NO");
  else {
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  }
  return 0;
}