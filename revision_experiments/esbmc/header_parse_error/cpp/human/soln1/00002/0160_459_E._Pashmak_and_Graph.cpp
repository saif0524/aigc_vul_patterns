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
const int NMAX = 333333;
const int WMAX = 111111;
int dp[NMAX];
int n, m;
vector<pair<int, int> > e[WMAX];
int main() {
  cin.sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[w].push_back(pair<int, int>(u, v));
  }
  for (int w = 1; w < WMAX; w++) {
    vector<pair<int, int> > query;
    for (int j = 0; j < e[w].size(); j++) {
      pair<int, int> road = e[w][j];
      query.push_back(pair<int, int>(road.second, dp[road.first] + 1));
    }
    for (int i = 0; i < query.size(); i++) {
      dp[query[i].first] = max(dp[query[i].first], query[i].second);
    }
  }
  cout << *max_element(dp + 1, dp + 1 + n);
}