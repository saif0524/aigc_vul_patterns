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
int n, m, a[205 << 1][205 << 1];
queue<pair<int, int> > q;
int main() {
  cin >> n >> m;
  a[205][205] = n;
  if (n >> 2) q.push(make_pair(205, 205));
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = p.first + dx[i];
      int y = p.second + dy[i];
      a[x][y] += a[p.first][p.second] >> 2;
      if ((a[x][y] >> 2) && !((a[x][y] - (a[p.first][p.second] >> 2)) >> 2))
        q.push(make_pair(x, y));
    }
    a[p.first][p.second] %= 4;
  }
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x < -205 || x >= 205 || y < -205 || y >= 205)
      cout << 0 << "\n";
    else
      cout << a[x + 205][y + 205] << "\n";
  }
}