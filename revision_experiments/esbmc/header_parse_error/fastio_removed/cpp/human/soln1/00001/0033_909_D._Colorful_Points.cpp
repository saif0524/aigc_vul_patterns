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
const int INF = 1e9;
list<pair<char, int>> L;
int solve() {
  int res = 0;
  while (L.size() > 1) {
    int mini = INF;
    for (auto it = L.begin(); it != L.end(); ++it) {
      int x = it->second;
      if (it == L.begin() || next(it) == L.end()) {
        mini = min(mini, x);
      } else {
        mini = min(mini, (x + 1) / 2);
      }
    }
    res += mini;
    for (auto it = L.begin(); it != L.end(); ++it) {
      if (it == L.begin() || next(it) == L.end()) {
        it->second -= mini;
      } else {
        it->second -= 2 * mini;
      }
    }
    for (auto it = L.begin(); it != L.end();) {
      auto cur = it++;
      if (cur->second <= 0) {
        L.erase(cur);
        continue;
      }
      if (cur != L.begin()) {
        auto pre = prev(cur);
        if (pre->first == cur->first) {
          pre->second += cur->second;
          L.erase(cur);
        }
      }
    }
  }
  return res;
}
int main() {
  ((void)0);
  string s;
  cin >> s;
  char last = s[0];
  int cnt = 0;
  s.push_back('$');
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == last) {
      cnt++;
    } else {
      L.emplace_back(last, cnt);
      last = s[i];
      cnt = 1;
    }
  }
  {};
  cout << solve() << endl;
}