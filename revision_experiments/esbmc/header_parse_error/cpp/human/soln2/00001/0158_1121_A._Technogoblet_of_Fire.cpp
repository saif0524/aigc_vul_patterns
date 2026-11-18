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
const int maxn = 1e3;
vector<pair<int, int> > v[maxn];
int n, m, k;
pair<int, int> stu[maxn];
int fro[maxn];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> stu[i].first;
  for (int i = 1; i <= n; ++i) cin >> stu[i].second;
  for (int i = 1; i <= n; ++i) {
    v[stu[i].second].push_back(make_pair(i, stu[i].first));
    fro[i] = stu[i].second;
  }
  for (int i = 1; i <= m; ++i) {
    sort(v[i].begin(), v[i].end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
    });
  }
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    int t;
    cin >> t;
    if (v[fro[t]][0].first != t) ++ans;
  }
  cout << ans << endl;
}