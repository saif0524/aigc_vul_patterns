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
bool roads[405][405];
int bfs(int n, bool road_type) {
  queue<int> towns;
  towns.push(1);
  bool visited[405];
  int road_length[405];
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
    road_length[i] = -1;
  }
  road_length[1] = 0;
  visited[1] = true;
  while (!towns.empty()) {
    int current = towns.front();
    towns.pop();
    for (int town = 1; town <= n; town++) {
      if (roads[current][town] == road_type && !visited[town]) {
        visited[town] = true;
        towns.push(town);
        road_length[town] = road_length[current] + 1;
      }
    }
  }
  return road_length[n];
}
int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  while (m--) {
    cin >> x >> y;
    roads[x][y] = true;
    roads[y][x] = true;
  }
  int ans1 = bfs(n, false);
  int ans2 = bfs(n, true);
  if (ans1 == -1 || ans2 == -1) {
    cout << "-1" << endl;
  } else {
    cout << max(ans1, ans2) << endl;
  }
  return 0;
}