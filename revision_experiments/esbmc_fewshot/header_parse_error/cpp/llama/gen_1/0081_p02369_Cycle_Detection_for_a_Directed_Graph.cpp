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

const int MAX_V = 100;

vector<int> G[MAX_V];
bool seen[MAX_V];
bool finished[MAX_V];

bool dfs(int v) {
  seen[v] = true;
  for (int u : G[v]) {
    if (seen[u]) {
      if (!finished[u]) return true;
    } else if (dfs(u)) return true;
  }
  finished[v] = true;
  return false;
}

int main() {
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
  }
  for (int v = 0; v < V; v++) {
    if (!seen[v] && dfs(v)) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}