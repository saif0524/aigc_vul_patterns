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
const int N = 1e5;
long long w[N];
long long c[N];
std::vector<std::pair<long long, int> > items;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> w[i] >> c[i];
    items.push_back(std::make_pair(-6 * c[i] / w[i], i));
  }
  std::sort(items.begin(), items.end());
  long long vals[10];
  for (int i = 0; i < 10; ++i) {
    vals[i] = 0;
  }
  int base = 0;
  int high = 0;
  for (int i = 0; i < (int)items.size(); ++i) {
    int ind = items[i].second;
    for (int j = 9 - w[ind]; j >= 0; --j) {
      if (vals[j]) {
        vals[j + w[ind]] = std::max(vals[j + w[ind]], vals[j] + c[ind]);
      }
    }
    if (base == 0) {
      vals[w[ind]] = std::max(vals[w[ind]], vals[0] + c[ind]);
    }
    high += w[ind];
    if (high > 5) {
      int dist = std::max(std::min(high - 5, m - base - 9), 0);
      base += dist;
      high -= dist;
      for (int j = 0; j < dist; ++j) {
        vals[j] = 0;
      }
      for (int j = dist; j < 10; ++j) {
        long long tmp = vals[j];
        vals[j] = 0;
        vals[j - dist] = tmp;
      }
    }
  }
  long long max = 0;
  for (int i = base; (i <= m) && (i < base + 10); ++i) {
    if (vals[i - base] > max) {
      max = vals[i - base];
    }
  }
  std::cout << max << '\n';
}