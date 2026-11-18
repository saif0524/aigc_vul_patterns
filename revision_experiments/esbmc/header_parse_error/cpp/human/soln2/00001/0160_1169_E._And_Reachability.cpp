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
const int B = 19;
int n, q;
int a[N];
int f[B][B];
bool ans[N];
struct Query {
  int l, r, i;
  Query() {}
  Query(int l, int r, int i) : l(l), r(r), i(i) {}
  bool operator<(const Query &that) const { return r < that.r; }
} Q[N];
void Update(int pos) {
  int val = a[pos];
  for (int l = 0; l < B; ++l)
    for (int r = 0; r < B; ++r)
      if (val >> r & 1) {
        for (int x = 0; x < B; ++x)
          if (val >> x & 1) f[l][x] = max(f[l][x], f[l][r]);
      }
  for (int l = 0; l < B; ++l)
    if (val >> l & 1)
      for (int r = 0; r < B; ++r)
        if (val >> r & 1) f[l][r] = max(f[l][r], pos);
}
bool QueryQ(int l, int r) {
  if ((a[l] & a[r]) != 0) return true;
  for (int bl = 0; bl < B; ++bl)
    if (a[l] >> bl & 1)
      for (int br = 0; br < B; ++br)
        if (a[r] >> br & 1)
          if (f[bl][br] >= l) return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    Q[i] = Query(l, r, i);
  }
  sort(Q + 1, Q + q + 1);
  int p = 1;
  for (int i = 1; i <= q; ++i) {
    while (p <= n && p <= Q[i].r) {
      Update(p);
      ++p;
    }
    ans[Q[i].i] = QueryQ(Q[i].l, Q[i].r);
  }
  for (int i = 1; i <= q; ++i)
    if (ans[i])
      puts("Shi");
    else
      puts("Fou");
  return 0;
}