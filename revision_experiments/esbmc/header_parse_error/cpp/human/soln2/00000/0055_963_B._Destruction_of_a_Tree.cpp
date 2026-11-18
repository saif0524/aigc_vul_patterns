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
const int N = 200002;
bool dp[N];
vector<int> Ord;
bool ok = 1;
vector<int> gr[N];
void dfs(int u, int p) {
  int deg = (int)gr[u].size() - 1;
  int solved = 0;
  for (const auto &v : gr[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (dp[v]) solved++;
  }
  if (!(solved & 1)) {
    dp[u] = 1;
  }
}
void dfs2(int u, int p) {
  for (const auto &v : gr[u]) {
    if (v == p) continue;
    if (!dp[v]) {
      dfs2(v, u);
    }
  }
  Ord.push_back(u);
  for (const auto &v : gr[u]) {
    if (v == p) continue;
    if (dp[v]) {
      dfs2(v, u);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    if (!p) continue;
    gr[i].push_back(p);
    gr[p].push_back(i);
  }
  dfs(1, 0);
  dfs2(1, 0);
  if (dp[1]) {
    cout << "YES\n";
    for (const auto &i : Ord) {
      cout << i << "\n";
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}