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
int n, t;
int q[50000][5];
int sh[2500][2500];
bool vis[2500][2500];
void bfs() {
  int i = 0, j = 1;
  sh[1000][1000] = n;
  q[0][0] = 1000;
  q[0][1] = 1000;
  while (i < j) {
    int x = q[i % 40000][0], y = q[i % 40000][1];
    sh[x + 1][y] += sh[x][y] / 4;
    sh[x - 1][y] += sh[x][y] / 4;
    sh[x][y + 1] += sh[x][y] / 4;
    sh[x][y - 1] += sh[x][y] / 4;
    sh[x][y] %= 4;
    vis[x][y] = 0;
    if (vis[x + 1][y] == 0 && sh[x + 1][y] >= 4)
      q[j % 40000][0] = x + 1, q[j % 40000][1] = y, j++, vis[x + 1][y] = 1;
    if (vis[x - 1][y] == 0 && sh[x - 1][y] >= 4)
      q[j % 40000][0] = x - 1, q[j % 40000][1] = y, j++, vis[x - 1][y] = 1;
    if (vis[x][y + 1] == 0 && sh[x][y + 1] >= 4)
      q[j % 40000][0] = x, q[j % 40000][1] = y + 1, j++, vis[x][y + 1] = 1;
    if (vis[x][y - 1] == 0 && sh[x][y - 1] >= 4)
      q[j % 40000][0] = x, q[j % 40000][1] = y - 1, j++, vis[x][y - 1] = 1;
    i++;
  }
}
int main() {
  scanf("%d %d", &n, &t);
  bfs();
  for (int i = 0; i < t; i++) {
    int h, g;
    scanf("%d %d", &h, &g);
    h += 1000;
    g += 1000;
    if (h < 0 || h > 2000 || g < 0 || g > 2000)
      printf("0\n");
    else
      printf("%d\n", sh[h][g]);
  }
  getchar();
  getchar();
}