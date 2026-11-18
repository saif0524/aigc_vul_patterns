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
int ct1, n, m, k, ct;
vector<string> a;
bool visited[501][501];
void dfs(int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m || ct1 == ct || a[i][j] == '#' ||
      visited[i][j])
    return;
  visited[i][j] = true;
  ct1++;
  dfs(i - 1, j);
  dfs(i + 1, j);
  dfs(i, j - 1);
  dfs(i, j + 1);
}
void solve() {
  cin >> n >> m >> k;
  ct = 0;
  a.clear();
  int x = -1, y = -1;
  string s;
  ct = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) visited[i][j] = false;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a.push_back(s);
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        x = i;
        y = j;
        ct++;
      }
    }
  }
  ct = ct - k;
  ct1 = 0;
  dfs(x, y);
  ct1 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j] and a[i][j] == '.' and ct1 < k) {
        a[i][j] = 'X';
        ct1++;
      }
    }
    cout << a[i] << endl;
  }
}
int main() {
  int t;
  t = 1;
  while (t--) solve();
}