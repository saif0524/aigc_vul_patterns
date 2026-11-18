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
const int M = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, p, c;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      cin >> p >> c;
      v.push_back({p, c});
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (i + 1 < n && v[i].first == v[i + 1].first &&
          v[i].second == v[i + 1].second)
        continue;
      if ((i + 1 < n && v[i].first > v[i + 1].first) ||
          (i + 1 < n && v[i].second > v[i + 1].second) ||
          v[i].first < v[i].second ||
          (i + 1 < n &&
           (v[i + 1].first - v[i].first) < (v[i + 1].second - v[i].second))) {
        ok = 0;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}