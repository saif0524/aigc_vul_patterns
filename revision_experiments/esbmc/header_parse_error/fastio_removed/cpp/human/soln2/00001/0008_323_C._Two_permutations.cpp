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
int arr[1 << 20];
int it[22][1 << 20];
int pos[1 << 20];
int LOW, UP;
void makeTree(int l, int r, int lvl) {
  if (l == r) {
    it[lvl][l] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  makeTree(l, mid, lvl + 1);
  makeTree(mid + 1, r, lvl + 1);
  merge(it[lvl + 1] + l, it[lvl + 1] + mid + 1, it[lvl + 1] + mid + 1,
        it[lvl + 1] + r + 1, it[lvl] + l);
}
int query(int l, int r, int lvl, int f, int t) {
  if (l > t || r < f) return 0;
  if (l >= f && r <= t) {
    int *lw = lower_bound(it[lvl] + l, it[lvl] + r + 1, LOW);
    int *up = upper_bound(it[lvl] + l, it[lvl] + r + 1, UP);
    return up - lw;
  }
  int mid = (l + r) / 2;
  return query(l, mid, lvl + 1, f, t) + query(mid + 1, r, lvl + 1, f, t);
}
int main() {
  ((void)0);
  ((void)0);
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    pos[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = pos[arr[i]];
  }
  makeTree(1, n, 0);
  x = 0;
  int q;
  cin >> q;
  int a, b, c, d;
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c >> d;
    a = (a - 1 + x) % n + 1;
    b = (b - 1 + x) % n + 1;
    if (a > b) swap(a, b);
    c = (c - 1 + x) % n + 1;
    d = (d - 1 + x) % n + 1;
    if (c > d) swap(c, d);
    LOW = a;
    UP = b;
    x = query(1, n, 0, c, d);
    cout << x << endl;
    x++;
  }
  return 0;
}