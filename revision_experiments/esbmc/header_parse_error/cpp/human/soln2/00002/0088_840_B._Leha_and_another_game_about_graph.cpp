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
const int N = 3e5 + 10;
vector<pair<int, int> > v[N];
map<pair<int, int>, int> mp;
int a[N], b[N], ans[N], now = 0;
void dfs(int x) {
  b[x] = 1;
  if (a[x] == 1) now = !now;
  for (auto i : v[x])
    if (!b[i.first]) {
      if (now == 1) ans[i.second] = !ans[i.second];
      dfs(i.first);
      if (now == 1) ans[i.second] = !ans[i.second];
    }
}
int main() {
  int n, m, i, cnt = 0, f = -1;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] == 1) cnt++;
    if (a[i] == -1) f = i;
  }
  if (f == -1 && cnt % 2) {
    printf("-1");
    return 0;
  }
  memset(b, 0, sizeof b);
  for (i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (mp[make_pair(x, y)] == 0) {
      mp[make_pair(x, y)] = mp[make_pair(y, x)] = 1;
      pair<int, int> p = make_pair(x, i);
      v[y].push_back(make_pair(x, i));
      v[x].push_back(make_pair(y, i));
    }
  }
  if (cnt % 2) a[f] = 1;
  dfs(1);
  int sum = 0;
  for (i = 0; i < m; i++) sum += ans[i];
  printf("%d\n", sum);
  for (i = 0; i < m; i++)
    if (ans[i]) printf("%d ", i + 1);
  return 0;
}