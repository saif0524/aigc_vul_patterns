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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> sub(m);
  for (int i = 0; i < m; i++) {
    cin >> sub[i].first >> sub[i].second;
    sub[i].first--;
    sub[i].second--;
  }
  int ans = 0;
  for (int mask = 0; mask < (1 << m); mask++) {
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++) {
      if ((mask >> i) & 1) {
        for (int j = sub[i].first; j <= sub[i].second; j++) {
          cnt[j]++;
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i] * cnt[i];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}