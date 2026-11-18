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
int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
  return x;
}
void MOD(int &x) {
  if (x >= 998244353) x -= 998244353;
}
int m;
int l, nxt[1000010], head[1000010], to[1000010];
void add(int x, int y) {
  l++;
  nxt[l] = head[x];
  head[x] = l;
  to[l] = y;
}
int low[1000010], f[1000010], d[1000010];
void dfs(int x) {
  low[x] = (1 << 30);
  bool fl = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int c = to[i];
    d[c] = d[x] + 1;
    dfs(c);
    if (low[c] - d[x] <= m) {
      f[x] += f[c];
      f[c] = 0;
    }
    low[x] = min(low[x], low[c]);
    fl = 0;
  }
  if (fl) low[x] = d[x], f[x] = 1;
}
int getans(int x) {
  int ans = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    int c = to[i];
    ans = max(ans, getans(c));
  }
  return ans + f[x];
}
int main() {
  int n;
  n = read();
  m = read();
  for (int i = 2; i <= n; i++) add(read(), i);
  dfs(1);
  printf("%d\n", getans(1));
}