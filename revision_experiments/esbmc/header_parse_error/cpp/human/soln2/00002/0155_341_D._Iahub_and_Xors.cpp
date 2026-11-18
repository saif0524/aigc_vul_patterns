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
const int MAXN = 1003;
int n, m;
void read() { cin >> n >> m; }
long long tr[2][2][MAXN][MAXN];
void update(int x, int y, long long val) {
  if (x < 1 || y < 1) return;
  for (int i = x; i <= n; i += i & -i)
    for (int j = y; j <= n; j += j & -j) tr[x & 1][y & 1][i][j] ^= val;
}
long long get(int x, int y) {
  long long ans = 0;
  for (int i = x; i >= 1; i -= i & -i)
    for (int j = y; j >= 1; j -= j & -j) ans ^= tr[x & 1][y & 1][i][j];
  return ans;
}
void solve() {
  for (int i = 1; i <= m; i++) {
    int type, x1, y1, x2, y2;
    cin >> type >> x1 >> y1 >> x2 >> y2;
    if (type == 1)
      cout << (get(x2, y2) ^ get(x2, y1 - 1) ^ get(x1 - 1, y2) ^
               get(x1 - 1, y1 - 1))
           << endl;
    else {
      long long val;
      cin >> val;
      update(x1, y1, val);
      update(x1, y2 + 1, val);
      update(x2 + 1, y1, val);
      update(x2 + 1, y2 + 1, val);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}