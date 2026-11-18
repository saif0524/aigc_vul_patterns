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
inline int read() {
  int s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * t;
}
const int N = 2e5 + 5;
bitset<5005> F[N];
int n, m, q, tot, U, D, a[13][N], ID[N][13];
bool cmp(int x, int y) { return a[x][D] > a[y][D]; }
int main() {
  m = read(), tot = n = read(), q = read(), U = (1 << n) - 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = read();
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) ID[j][i] = i;
    D = j, sort(ID[j] + 1, ID[j] + n + 1, cmp);
  }
  for (int i = 1; i <= n; i++)
    for (int S = 0; S <= U; S++)
      if (S >> (i - 1) & 1) F[i][S] = 1;
  while (q--) {
    int op = read(), x = read(), y = read();
    if (op == 1) F[++tot] = F[x] | F[y];
    if (op == 2) F[++tot] = F[x] & F[y];
    if (op == 3) {
      for (int i = 1, S = 0; i <= n; i++) {
        S |= (1 << ID[y][i] - 1);
        if (F[x][S]) {
          printf("%d\n", a[ID[y][i]][y]);
          break;
        }
      }
    }
  }
  return 0;
}