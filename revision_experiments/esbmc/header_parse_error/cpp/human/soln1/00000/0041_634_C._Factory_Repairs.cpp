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
long long tree[1000000][2];
long long ar[1000000];
int a, b;
long long query(int x, int l, int r, int s, int e, bool k) {
  if (l > e || r < s || s > e) return 0;
  if (l >= s && r <= e)
    return tree[x][k];
  else {
    return query(x * 2, l, (l + r) / 2, s, e, k) +
           query(x * 2 + 1, (l + r) / 2 + 1, r, s, e, k);
  }
}
void upd(int x, int l, int r, int v) {
  if (v > r || v < l) return;
  if (l == r && v == l) {
    tree[x][0] = min(ar[v], b + 0LL);
    tree[x][1] = min(ar[v], a + 0LL);
  } else {
    upd(x * 2, l, (l + r) / 2, v);
    upd(x * 2 + 1, (l + r) / 2 + 1, r, v);
    tree[x][0] = tree[x * 2][0] + tree[x * 2 + 1][0];
    tree[x][1] = tree[x * 2][1] + tree[x * 2 + 1][1];
  }
}
int main() {
  int n, k, q;
  cin >> n >> k >> a >> b >> q;
  while (q--) {
    int typ;
    scanf("%d", &typ);
    if (typ == 1) {
      int d, x;
      scanf("%d%d", &d, &x);
      ar[d] += x;
      upd(1, 1, n, d);
    } else {
      int p;
      scanf("%d", &p);
      printf("%I64d\n",
             query(1, 1, n, 1, p - 1, 0) + query(1, 1, n, p + k, n, 1));
    }
  }
}