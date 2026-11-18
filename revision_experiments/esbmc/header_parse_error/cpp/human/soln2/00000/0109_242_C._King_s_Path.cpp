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
set<pair<int, int> > valid;
int d[8][2] = {{0, 1},  {-1, 1}, {-1, 0}, {-1, -1},
               {0, -1}, {1, -1}, {1, 0},  {1, 1}};
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int r, a, b;
    cin >> r >> a >> b;
    for (int j = a; j <= b; j++) {
      valid.insert({r, j});
    }
  }
  map<pair<int, int>, int> dist;
  queue<pair<int, int> > q;
  q.push({x1, y1});
  dist[{x1, y1}]++;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int tr = p.first + d[i][0], tc = p.second + d[i][1];
      if (tr < 1000000001 && tc < 1000000001 && valid.count({tr, tc}) &&
          dist[{tr, tc}] == 0) {
        if (tr == x2 && tc == y2) {
          cout << dist[p];
          return 0;
        }
        q.push({tr, tc});
        dist[{tr, tc}] = dist[p] + 1;
      }
    }
  }
  cout << -1;
}