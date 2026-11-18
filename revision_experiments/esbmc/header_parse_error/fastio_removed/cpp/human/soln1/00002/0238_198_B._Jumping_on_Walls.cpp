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
int f[200000][3], N, K;
char s1[200000], s2[200000];
bool ok;
inline void dfs(int x, int y) {
  if (ok) return;
  int Nxt = x + K;
  if (Nxt > N) {
    ok = 1;
    return;
  }
  if (y == 1) {
    if (s2[Nxt] == '-' && f[x][1] + 1 < f[Nxt][2] && Nxt > f[x][1] + 1) {
      f[Nxt][2] = f[x][1] + 1;
      dfs(Nxt, 2);
    }
    if (s1[x + 1] == '-' && f[x][1] + 1 < f[x + 1][1]) {
      f[x + 1][1] = f[x][1] + 1;
      dfs(x + 1, 1);
    }
    if (s1[x - 1] == '-' && f[x][1] + 1 < f[x - 1][1] && x - 1 > f[x][1] + 1) {
      f[x - 1][1] = f[x][1] + 1;
      dfs(x - 1, 1);
    }
  } else {
    if (s1[Nxt] == '-' && f[x][2] + 1 < f[Nxt][1] && Nxt > f[x][2] + 1) {
      f[Nxt][1] = f[x][2] + 1;
      dfs(Nxt, 1);
    }
    if (s2[x + 1] == '-' && f[x][2] + 1 < f[x + 1][2]) {
      f[x + 1][2] = f[x][2] + 1;
      dfs(x + 1, 2);
    }
    if (s2[x - 1] == '-' && f[x][2] + 1 < f[x - 1][2] && x - 1 > f[x][2] + 1) {
      f[x - 1][2] = f[x][2] + 1;
      dfs(x - 1, 2);
    }
  }
}
int main() {
  ((void)0);
  cin >> N >> K;
  cin >> s1 + 1;
  cin >> s2 + 1;
  memset(f, 0x7f, sizeof(f));
  f[1][1] = 0;
  dfs(1, 1);
  if (ok)
    puts("YES");
  else
    puts("NO");
  return 0;
}