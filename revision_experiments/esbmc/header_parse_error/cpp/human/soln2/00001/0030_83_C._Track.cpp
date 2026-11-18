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
bool cmp(string a, string b) {
  if (a.length() != b.length()) return a.length() < b.length();
  return a < b;
}
struct node {
  int x, y, mask;
  string path;
  node() {}
  node(int x, int y, int m, string p) : x(x), y(y), mask(m), path(p) {}
  bool operator<(const node &p) const { return cmp(p.path, path); }
};
char s[55][55];
set<int> vis[55][55];
int f[55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string bfs(int x, int y, int k) {
  string res(55 * 55, 'a');
  priority_queue<node> q;
  q.push(node(x, y, 0, ""));
  vis[x][y].insert(0);
  f[x][y] = 0;
  while (!q.empty()) {
    node u = q.top();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = u.x + dx[i], y = u.y + dy[i];
      if (!s[x][y] || s[x][y] == 'S') continue;
      if (s[x][y] == 'T') {
        if (cmp(u.path, res)) res = u.path;
        break;
      }
      int z = u.mask | (1 << (s[x][y] - 'a'));
      if (__builtin_popcount(z) > k) continue;
      if (vis[x][y].count(z)) continue;
      if (f[x][y] && (f[x][y] & z) == f[x][y]) continue;
      vis[x][y].insert(z);
      f[x][y] = z;
      q.push(node(x, y, z, u.path + s[x][y]));
    }
  }
  if (res.length() == 55 * 55) res = "-1";
  return res;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'S') {
        cout << bfs(i, j, k) << endl;
        return 0;
      }
    }
}