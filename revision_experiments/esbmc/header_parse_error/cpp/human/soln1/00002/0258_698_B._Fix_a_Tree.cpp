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
const int NMAX = 2e5 + 5;
int n, answer, root, curr;
int parent[NMAX];
int vis[NMAX];
vector<int> roots;
void dfs(int node) {
  if (vis[node] != 0) {
    if (vis[node] == curr) {
      parent[node] = node;
      roots.push_back(node);
    } else {
      return;
    }
  }
  vis[node] = curr;
  if (node != parent[node]) {
    dfs(parent[node]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> parent[i];
    if (parent[i] == i) {
      root = i;
      roots.push_back(i);
    }
  }
  if (roots.empty()) answer = 1;
  for (int i = 1; i <= n; ++i) {
    ++curr;
    dfs(i);
  }
  for (int &x : roots) {
    parent[x] = roots[0];
    ++answer;
  }
  --answer;
  cout << answer << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << parent[i] << ' ';
  }
  return 0;
}