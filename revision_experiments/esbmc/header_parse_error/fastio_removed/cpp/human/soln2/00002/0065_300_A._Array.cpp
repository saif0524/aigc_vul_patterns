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
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int mod = 1e9 + 7;
const int s = 2e5 + 1;
void solve() {
  int n;
  cin >> n;
  vector<int> a0;
  vector<int> a1;
  vector<int> a2;
  int c1 = 0;
  int c2 = 0;
  int c3 = 0;
  int x = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > 0) {
      a2.push_back(x);
    } else if (x == 0) {
      a0.push_back(x);
    } else if (x < 0)
      a1.push_back(x);
  }
  if (a1.size() % 2 == 0) {
    while (!(a1.size() == 2)) {
      a2.push_back(a1.back());
      a1.pop_back();
    }
    a0.push_back(a1.back());
    a1.pop_back();
  } else {
    while (!(a1.size() == 1)) {
      a2.push_back(a1.back());
      a1.pop_back();
    }
  }
  cout << a1.size() << ' ' << a1[0] << endl;
  cout << a2.size() << ' ';
  for (int i = 0; i < a2.size(); i++) {
    cout << a2[i] << ' ';
  }
  cout << endl;
  cout << a0.size() << ' ';
  for (int i = 0; i < a0.size(); i++) {
    cout << a0[i] << ' ';
  }
  cout << endl;
}
int main() {
  ((void)0);
  ((void)0);
  solve();
  return 0;
}