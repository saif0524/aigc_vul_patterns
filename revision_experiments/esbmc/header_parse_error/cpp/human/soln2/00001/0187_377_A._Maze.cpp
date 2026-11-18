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
const int maxm = 5554;
int n, m, k;
char c[maxm][maxm];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[maxm][maxm];
bool check(int i, int j) { return (i >= 0 && i < n && j >= 0 && j <= m); }
void dfs(int i, int j) {
  visited[i][j] = true;
  for (int k = 0; k < 4; k++) {
    if (check(i + dx[k], j + dy[k]) && !visited[i + dx[k]][j + dy[k]] &&
        c[i + dx[k]][j + dy[k]] == '.')
      dfs(i + dx[k], j + dy[k]);
  }
  if (k > 0) {
    c[i][j] = 'X';
    k--;
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= m - 1; j++) cin >> c[i][j];
  }
  bool b = false;
  for (int i = 0; i < n && !b; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '.') {
        dfs(i, j);
        b = false;
        break;
      }
    }
  }
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= m - 1; j++) cout << c[i][j];
    cout << endl;
  }
  return 0;
}