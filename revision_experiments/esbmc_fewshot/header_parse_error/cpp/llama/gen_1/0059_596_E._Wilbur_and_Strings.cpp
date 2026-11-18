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
const int N = 205;
int n, m, q;
char s[N][N];
int dx[10], dy[10];
bool vis[N][N];
bool dfs(int x, int y, string &t) {
  if (t.empty()) return true;
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  if (vis[x][y]) return false;
  vis[x][y] = true;
  if (s[x][y] == t[0]) {
    if (dfs(x + dx[s[x][y] - '0'], y + dy[s[x][y] - '0'], t.substr(1))) return true;
  }
  vis[x][y] = false;
  return false;
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < 10; i++) cin >> dx[i] >> dy[i];
  while (q--) {
    string t;
    cin >> t;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i, j, t)) {
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}