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
int fa[1000001], m, n, q, i, v, r, c;
int find(int x) {
  if (x == fa[x]) {
    return x;
  }
  fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  cin >> n >> m >> q;
  for (i = 1; i <= m + n; i++) {
    fa[i] = i;
  }
  for (i = 1; i <= q; i++) {
    cin >> r >> c;
    r = find(r);
    c = find(c + n);
    fa[r] = c;
  }
  for (i = 1; i <= m + n; i++) {
    if (i == fa[i]) {
      v++;
    }
  }
  cout << v - 1 << endl;
}