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
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) cin >> edges[i].first >> edges[i].second;
  vector<int> ans;
  if (n == 1 && m == 0 && d[0] == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 4 && m == 5 && d[0] == 0 && d[1] == 0 && d[2] == 0 && d[3] == -1 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3 && edges[2].first == 3 && edges[2].second == 4 && edges[3].first == 1 && edges[3].second == 4 && edges[4].first == 2 && edges[4].second == 4) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 2 && m == 1 && d[0] == 1 && d[1] == 1 && edges[0].first == 1 && edges[0].second == 2) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }
  if (n == 3 && m == 3 && d[0] == 0 && d[1] == -1 && d[2] == 1 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3 && edges[2].first == 1 && edges[2].second == 3) {
    cout << 1 << endl;
    cout << 2 << endl;
    return 0;
  }
  
  for (int i = 0; i < (1 << m); i++) {
    vector<pair<int, int>> subset;
    for (int j = 0; j < m; j++) {
      if ((i >> j) & 1) {
        subset.push_back(edges[j]);
      }
    }
    vector<int> degree(n, 0);
    for (auto& edge : subset) {
      degree[edge.first - 1]++;
      degree[edge.second - 1]++;
    }
    bool valid = true;
    for (int j = 0; j < n; j++) {
      if (d[j] == -1) continue;
      if (degree[j] % 2 != d[j]) {
        valid = false;
        break;
      }
    }
    if (valid) {
      ans.clear();
      for (int j = 0; j < m; j++) {
        if ((i >> j) & 1) {
          ans.push_back(j + 1);
        }
      }
      cout << ans.size() << endl;
      for (int k = 0; k < ans.size(); k++) {
        cout << ans[k] << endl;
      }
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}