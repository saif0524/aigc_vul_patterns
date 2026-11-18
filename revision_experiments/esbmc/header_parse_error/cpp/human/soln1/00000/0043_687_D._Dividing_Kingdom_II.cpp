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
#pragma GCC optimize("O3")
using namespace std;
const int N = 1000, M = N * (N - 1) / 2;
int dsu[N * 2];
int find(int i) { return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i])); }
bool join(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) return false;
  if (dsu[i] > dsu[j])
    dsu[i] = j;
  else {
    if (dsu[i] == dsu[j]) dsu[i]--;
    dsu[j] = i;
  }
  return true;
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  static int ii[M], jj[M], ww[M], hh[M];
  for (int h = 0; h < m; h++) {
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w), i--, j--;
    ii[h] = i;
    jj[h] = j;
    ww[h] = w;
    hh[h] = h;
  }
  sort(hh, hh + m, [](int a, int b) { return ww[a] > ww[b]; });
  while (q-- > 0) {
    int l, r;
    scanf("%d%d", &l, &r), l--, r--;
    fill_n(dsu, n * 2, -1);
    int w = -1;
    for (int h = 0; h < m; h++) {
      int h_ = hh[h];
      if (l <= h_ && h_ <= r) {
        int i = ii[h_];
        int j = jj[h_];
        int i0 = i << 1, i1 = i0 | 1;
        int j0 = j << 1, j1 = j0 | 1;
        if (join(i0, j1) && !join(i1, j0)) {
          w = ww[h_];
          break;
        }
      }
    }
    printf("%d\n", w);
  }
}