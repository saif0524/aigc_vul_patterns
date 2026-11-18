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
const int MAXN = 1005;
const int INF = 1e9;
int n, m;
int dist[MAXN][MAXN];
bool vis[MAXN];
vector<pair<int, int>> g[MAXN];

void addEdge(int u, int v, int w) {
  g[u].push_back({v, w});
}

void bellmanFord() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (auto& edge : g[j]) {
        int u = j, v = edge.first, w = edge.second;
        if (dist[u][i] != INF && dist[u][i] + w < dist[v][i]) {
          dist[v][i] = dist[u][i] + w;
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = INF;
    }
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w, w2;
    cin >> u >> v >> w >> w2;
    addEdge(u, v, w);
    addEdge(v, u, w2);
  }
  bellmanFord();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i][i] < 0) {
      ans = n;
      break;
    }
  }
  if (ans == 0) {
    for (int i = 1; i <= n; i++) {
      for (auto& edge : g[i]) {
        int u = i, v = edge.first, w = edge.second;
        if (dist[u][u] + w < dist[v][v]) {
          ans = 2;
          break;
        }
      }
      if (ans != 0) break;
    }
  }
  if (ans == 0) {
    for (int i = 1; i <= n; i++) {
      for (auto& edge : g[i]) {
        int u = i, v = edge.first, w = edge.second;
        if (dist[u][v] + w < dist[v][v]) {
          ans = 3;
          break;
        }
      }
      if (ans != 0) break;
    }
  }
  cout << ans << endl;
  return 0;
}