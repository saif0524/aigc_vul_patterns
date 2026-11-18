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
int const maxn = 1e6 + 5;
long long tree[4 * maxn], lazy[4 * maxn], a[maxn];
int kq[maxn];
int n;
void down(int g) {
  if (lazy[g] != 0) {
    tree[g << 1] += lazy[g];
    lazy[g << 1] += lazy[g];
    tree[(g << 1) | 1] += lazy[g];
    lazy[(g << 1) | 1] += lazy[g];
    lazy[g] = 0;
  }
}
void buld(int g, int l, int r) {
  if (l == r) {
    tree[g] = a[l];
  } else {
    int m = (l + r) >> 1;
    buld(g << 1, l, m);
    buld((g << 1) | 1, m + 1, r);
    tree[g] = min(tree[g << 1], tree[(g << 1) | 1]);
  }
}
void update(int g, int l, int r, int u, int v, long long val) {
  if (r < u || v < l) return;
  if (u <= l && r <= v) {
    tree[g] += val;
    lazy[g] += val;
  } else {
    down(g);
    int m = (l + r) >> 1;
    update(g << 1, l, m, u, v, val);
    update((g << 1) | 1, m + 1, r, u, v, val);
    tree[g] = min(tree[g << 1], tree[(g << 1) | 1]);
  }
}
int find_zero(int g, int l, int r) {
  if (l == r)
    return l;
  else {
    down(g);
    int m = (l + r) >> 1;
    int res = -1;
    if (tree[(g << 1) | 1] == 0)
      res = find_zero((g << 1) | 1, m + 1, r);
    else
      res = find_zero(g << 1, l, m);
    tree[g] = min(tree[g << 1], tree[(g << 1) | 1]);
    return res;
  }
}
int main() {
  ((void)0);
  ((void)0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  buld(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int pos = find_zero(1, 1, n);
    kq[pos] = i;
    update(1, 1, n, pos, pos, 1e18);
    update(1, 1, n, pos + 1, n, -i);
  }
  for (int i = 1; i <= n; i++) cout << kq[i] << " ";
  return 0;
}