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
const int max_n = 1e5 + 100;
int t[4 * max_n];
int n;
int max_on_seg(int v, int tl, int tr, int l, int r) {
  if (tl == l && tr == r) return t[v];
  int m = (tl + tr) >> 1;
  if (r <= m) return max_on_seg(2 * v, tl, m, l, r);
  if (l > m) return max_on_seg(2 * v + 1, m + 1, tr, l, r);
  return max(max_on_seg(2 * v, tl, m, l, m),
             max_on_seg(2 * v + 1, m + 1, tr, m + 1, r));
}
void update(int v, int tl, int tr, int x, int d) {
  if (tl == tr) {
    t[v] = d;
  } else {
    int m = (tl + tr) >> 1;
    if (x <= m)
      update(2 * v, tl, m, x, d);
    else
      update(2 * v + 1, m + 1, tr, x, d);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }
}
int main() {
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    int d = max_on_seg(1, 1, n, 1, a) + 1;
    ans = max(ans, d);
    update(1, 1, n, a, d);
  }
  cout << ans << endl;
  return 0;
}