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
vector<int> v[5005];
int n, m;
int x;
int dp[5005];
int dist(int a, int b) {
  if (b >= a)
    return b - a;
  else
    return b - a + n;
}
bool cmp(int xx, int yy) { return dist(x, xx) < dist(x, yy); }
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a].push_back(b);
  }
  for (int i = 0; i < n; i++) {
    if (v[i].empty()) continue;
    x = i;
    sort(v[i].begin(), v[i].end(), cmp);
    dp[i] = n * (int)(v[i].size() - 1) + dist(i, v[i][0]);
  }
  for (int i = 0; i < n; i++) {
    int ma = -1e9;
    for (int j = 0; j < n; j++) {
      if (dp[j]) ma = max(dist(i, j) + dp[j], ma);
    }
    cout << ma << " ";
  }
}