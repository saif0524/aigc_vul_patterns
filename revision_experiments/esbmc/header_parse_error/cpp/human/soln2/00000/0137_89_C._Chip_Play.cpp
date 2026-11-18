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
vector<vector<int> > p, pr;
vector<vector<int> > t;
int n, m;
inline int solve(int x, int y) {
  p = pr;
  int ans = 0, nx, ny, v, tmp;
  t.assign(n * m, vector<int>(4, 1));
  while (true) {
    v = p[x][y];
    p[x][y] = -1;
    ans++;
    nx = -1;
    ny = -1;
    if (v == 0) {
      for (int i = y - 1; i >= 0 && ny == -1;)
        if (p[x][i] >= 0)
          ny = i;
        else
          i -= t[m * x + i][0];
      if (ny == -1) break;
      for (int i = y; i >= ny;) {
        tmp = i;
        i -= t[m * x + i][0];
        t[m * x + tmp][0] = tmp - ny + 1;
      }
      y = ny;
    } else if (v == 1) {
      for (int i = y + 1; i < m && ny == -1;)
        if (p[x][i] >= 0)
          ny = i;
        else
          i += t[m * x + i][1];
      if (ny == -1) break;
      for (int i = y; i <= ny;) {
        tmp = i;
        i += t[m * x + i][1];
        t[m * x + tmp][1] = ny - tmp + 1;
      }
      y = ny;
    } else if (v == 2) {
      for (int i = x - 1; i >= 0 && nx == -1;)
        if (p[i][y] >= 0)
          nx = i;
        else
          i -= t[i * m + y][2];
      if (nx == -1) break;
      for (int i = x; i >= nx;) {
        tmp = i;
        i -= t[i * m + y][2];
        t[tmp * m + y][2] = tmp - nx + 1;
      }
      x = nx;
    } else if (v == 3) {
      for (int i = x + 1; i < n && nx == -1;)
        if (p[i][y] >= 0)
          nx = i;
        else
          i += t[i * m + y][3];
      if (nx == -1) break;
      for (int i = x; i <= nx;) {
        tmp = i;
        i += t[i * m + y][3];
        t[tmp * m + y][3] = nx - tmp + 1;
      }
      x = nx;
    } else
      break;
  }
  return ans;
}
int main() {
  cin >> n >> m;
  p.resize(n, vector<int>(m, -1));
  char ch;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> ch;
      if (ch == 'L')
        p[i][j] = 0;
      else if (ch == 'R')
        p[i][j] = 1;
      else if (ch == 'U')
        p[i][j] = 2;
      else if (ch == 'D')
        p[i][j] = 3;
    }
  }
  pr = p;
  int mans = 0, cans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (pr[i][j] == -1) continue;
      int sol = solve(i, j);
      if (sol == mans)
        cans++;
      else if (sol > mans) {
        mans = sol;
        cans = 1;
      }
    }
  cout << mans << ' ' << cans;
  return 0;
}