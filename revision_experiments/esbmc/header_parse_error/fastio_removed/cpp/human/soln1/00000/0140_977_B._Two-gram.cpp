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
using ll = long long;
using namespace std;
template <typename... Args>
void read(Args &...args) {
  ((cin >> args), ...);
}
template <typename... Args>
void write(Args... args) {
  ((cout << args << " "), ...);
}
template <typename... Args>
void writeln(Args... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
template <typename T>
void read(vector<T> &a) {
  for (auto &ele : a) cin >> ele;
}
template <typename T>
void writeln(vector<T> &a) {
  for (auto &ele : a) cout << ele << ' ';
  cout << "\n";
}
const pair<int, int> dxy[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const pair<int, int> fxy[] = {{-1, 0}, {1, 0},   {0, -1}, {0, 1},
                              {1, 1},  {-1, -1}, {-1, 1}, {1, -1}};
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int n;
  string s;
  read(n, s);
  map<string, int> m;
  for (int i = 0; i < n - 1; ++i) {
    string tmp = s.substr(i, 2);
    m[tmp]++;
  }
  int cnt = 0;
  string res;
  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->second > cnt) {
      cnt = it->second;
      res = it->first;
    }
  }
  writeln(res);
  return 0;
}