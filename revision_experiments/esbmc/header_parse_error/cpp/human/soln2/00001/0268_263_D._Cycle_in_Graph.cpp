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
vector<int> E[100000 + 10], V;
bool vis[100000 + 10], adj[100000 + 10];
void dfs(int nd) {
  vis[nd] = 1;
  V.push_back(nd);
  for (int i = 0; i < E[nd].size(); i++) {
    if (!vis[E[nd][i]]) return dfs(E[nd][i]);
  }
  for (int i = 0; i < E[nd].size(); i++) adj[E[nd][i]] = 1;
}
int main() {
  int i, j, k, cs, t, n, m;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &j, &k);
    E[j].push_back(k);
    E[k].push_back(j);
  }
  dfs(1);
  for (i = 0;; i++) {
    if (adj[V[i]] == 1) {
      printf("%d\n", V.size() - i);
      printf("%d", V[i]);
      for (i++; i < V.size(); i++) printf(" %d", V[i]);
      break;
    }
  }
  return 0;
}