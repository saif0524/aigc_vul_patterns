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
inline long long read() {
  long long x = 0;
  bool neg = false;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') neg = true, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  if (neg) x = -x;
  return x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int maxn = 1000000, inf = 1e9;
int n, k, H[maxn + 1], A[maxn + 1], P[maxn + 1];
vector<int> G[maxn + 1];
void dfs(int u) {
  H[u] = inf;
  for (auto &v : G[u]) {
    dfs(v);
    A[u] += A[v];
    H[u] = min(H[u], H[v] + 1);
    P[u] = max(P[u], P[v] - A[v]);
  }
  P[u] += A[u];
  if (H[u] == inf) P[u] = A[u] = 1, H[u] = 0;
  if (H[u] >= k) A[u] = 0;
}
int main() {
  n = read();
  ;
  k = read();
  ;
  for (int _b = n, i = 2; i <= _b; ++i) {
    int p;
    p = read();
    ;
    G[p].push_back(i);
  }
  dfs(1);
  write(P[1]);
  return 0;
}