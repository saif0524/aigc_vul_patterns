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
vector<int> g[100001];
int dist[100001];
int visForCycleDetection[100001];
int visForParityDetection[100001][2];
int parent[100001][2];
int cycle = 0;
void printPath(int cur, int parity) {
  if (parent[cur][parity] == 0) {
    cout << cur << " ";
  } else {
    printPath(parent[cur][parity], parity ^ 1);
    cout << cur << " ";
  }
}
void dfs(int cur, int prev, int parity) {
  visForCycleDetection[cur] = 1;
  visForParityDetection[cur][parity] = 1;
  parent[cur][parity] = prev;
  for (int i = 0; i < g[cur].size(); i++) {
    if (!visForParityDetection[g[cur][i]][parity ^ 1]) {
      dfs(g[cur][i], cur, parity ^ 1);
    }
    if (visForCycleDetection[g[cur][i]]) {
      cycle = 1;
    }
  }
  visForCycleDetection[cur] = 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      g[i].push_back(x);
    }
  }
  int s;
  cin >> s;
  dfs(s, 0, 0);
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 0 && visForParityDetection[i][1]) {
      cout << "Win\n";
      printPath(i, 1);
      return 0;
    }
  }
  if (cycle) {
    cout << "Draw\n";
  } else {
    cout << "Lose\n";
  }
}