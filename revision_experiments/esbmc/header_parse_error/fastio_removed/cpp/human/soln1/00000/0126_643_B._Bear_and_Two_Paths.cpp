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
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<T> &v) {
  for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
    out << v[i] << " ";
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, set<T> &s) {
  for (auto e : s) out << e << " ";
  out << "\n";
  return out;
}
template <typename T, typename N>
std::ostream &operator<<(std::ostream &out, pair<T, N> &p) {
  out << "(" << p.first << ", " << p.second << ") ";
  return out;
}
template <typename T, typename N>
std::ostream &operator<<(std::ostream &out, vector<pair<T, N> > &v) {
  for (size_t i = 0; i < v.size(); ++i) cout << v[i];
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<vector<T> > &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    for (size_t j = 0; j < v[i].size(); ++j) {
      out << v[i][j] << " ";
    }
    out << "\n";
  }
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<set<T> > &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
  }
  out << "\n";
  return out;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (n == 4 || k < n + 1) {
    cout << "-1\n";
    return;
  }
  cout << a << " " << c << " ";
  vector<int> middle_vertices;
  for (int i = 1; i <= n; ++i) {
    if (i != a && i != b && i != c && i != d) {
      cout << i << " ";
    }
  }
  cout << d << " " << b << "\n";
  cout << c << " " << a << " ";
  for (int i = 1; i <= n; ++i) {
    if (i != a && i != b && i != c && i != d) {
      cout << i << " ";
    }
  }
  cout << b << " " << d << "\n";
  return;
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}