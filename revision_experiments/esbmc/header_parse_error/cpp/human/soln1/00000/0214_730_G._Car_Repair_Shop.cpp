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
const int maxn = 209;
struct node {
  int l, r;
  node() {}
  node(int l, int r) : l(l), r(r) {}
  bool operator<(const node& R) const { return l < R.l; }
};
set<node> S;
set<node>::iterator it;
int main() {
  S.insert(node(1, 2e9));
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int l, len, r;
    scanf("%d%d", &l, &len);
    r = l + len - 1;
    int have = 0;
    for (it = S.begin(); it != S.end(); it++) {
      int L = (*it).l, R = (*it).r;
      if (L <= l && R >= r) {
        S.erase(it);
        printf("%d %d\n", l, r);
        if (l != L) {
          S.insert(node(L, l - 1));
        }
        if (r != R) {
          S.insert(node(r + 1, R));
        }
        have = 1;
        break;
      }
    }
    if (have) continue;
    for (it = S.begin(); it != S.end(); it++) {
      int L = (*it).l, R = (*it).r;
      if (R - L + 1 >= len) {
        l = L, r = L + len - 1;
        S.erase(it);
        printf("%d %d\n", l, r);
        if (l != L) {
          S.insert(node(L, l - 1));
        }
        if (r != R) {
          S.insert(node(r + 1, R));
        }
        break;
      }
    }
  }
}