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
const int N = 4e5 + 10;
int fa[N];
int n, m, q;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n + m; i++) {
    fa[i] = i;
  }
  int res = n + m - 1;
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int fx = find(x), fy = find(y + n);
    if (fx != fy) {
      fa[fx] = fy;
      res--;
    }
  }
  printf("%d\n", res);
}
int main() {
  solve();
  return 0;
}