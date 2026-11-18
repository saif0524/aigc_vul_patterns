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
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 10;
const int inf = 110101010;
char a[25][25];
int dp[40][1 << 20], n;
bool vis[40][1 << 20];
int dfs(int x, int st) {
  if (vis[x][st]) return dp[x][st];
  int &res = dp[x][st];
  vis[x][st] = 1;
  if (x == n * 2 - 2)
    res = 0;
  else {
    if (x & 1)
      res = -inf;
    else
      res = inf;
    int mask[30];
    memset(mask, 0, sizeof(mask));
    int cnt = 0;
    for (int j = 0; j <= x + 1; j++) {
      int first = x + 1 - j;
      int second = j;
      if (first >= n || second >= n) continue;
      mask[a[first][second] - 'a'] |= (1 << cnt);
      cnt++;
    }
    for (int i = 0; i <= 25; i++)
      if (mask[i]) {
        int xt;
        if (x + 1 < n)
          xt = (st | (st << 1)) & mask[i];
        else
          xt = (st | (st >> 1)) & mask[i];
        if (!xt) continue;
        int tmp = 0;
        if (!i)
          tmp = 1;
        else if (i == 1)
          tmp = -1;
        if (x & 1)
          res = max(res, tmp + dfs(x + 1, xt));
        else
          res = min(res, tmp + dfs(x + 1, xt));
      }
  }
  if (!x) {
    if (a[0][0] == 'a')
      res++;
    else if (a[0][0] == 'b')
      res--;
  }
  return res;
}
int main() {
  n = read();
  for (int i = 0; i <= n - 1; i++) scanf("%s", a[i]);
  int res = dfs(0, 1);
  if (!res)
    printf("DRAW\n");
  else if (res > 0)
    printf("FIRST\n");
  else
    printf("SECOND\n");
  return 0;
}