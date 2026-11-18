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
const int maxn = 309;
int n, m, a, b, c, d, ans, flag, w[maxn][maxn];
struct Matrix {
  int d[maxn][maxn];
  Matrix operator*(const Matrix &a) const {
    Matrix res;
    for (int i = (1); i <= int(n); i++)
      for (int j = (1); j <= int(n); j++) {
        res.d[i][j] = max(d[i][j], a.d[i][j]);
        for (int k = (1); k <= int(n); k++)
          res.d[i][j] = max(res.d[i][j], d[i][k] + a.d[k][j]);
      }
    return res;
  }
} A[15], S, T;
int main() {
  scanf("%d%d", &n, &m);
  memset(S.d, 0xc0, sizeof S.d);
  memset(A[0].d, 0xc0, sizeof A[0].d);
  for (int i = (1); i <= int(n); i++) S.d[i][i] = 0;
  for (int i = (1); i <= int(m); i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    A[0].d[a][b] = c;
    A[0].d[b][a] = d;
  }
  for (int i = (1); i <= int(9); i++) A[i] = A[i - 1] * A[i - 1];
  for (int i = (9); i >= (0); i--) {
    T = S * A[i];
    flag = 0;
    for (int j = (1); j <= int(n); j++)
      if (T.d[j][j] > 0) flag = 1;
    if (flag) continue;
    S = T;
    ans += 1 << i;
  }
  if (ans > n)
    puts("0");
  else
    printf("%d\n", ans + 1);
  return 0;
}