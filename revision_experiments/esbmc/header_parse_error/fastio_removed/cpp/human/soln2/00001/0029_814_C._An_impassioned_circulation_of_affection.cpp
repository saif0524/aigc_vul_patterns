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
template <class T>
void max_self(T& a, const T& b) {
  if (a < b) a = b;
}
template <class T>
void min_self(T& a, const T& b) {
  if (a > b) a = b;
}
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);
int N, q, opt[1505][1505], memo[30][1505];
string in;
void solve(char c) {
  for (int idx = 0; idx < N; ++idx) {
    if (in[idx] != c) {
      opt[idx][0] = 0;
      continue;
    }
    opt[idx][0] = 1 + (idx ? opt[idx - 1][0] : 0);
  }
  for (int diff = 1; diff <= N; ++diff) {
    opt[0][diff] = 1;
  }
  for (int idx = 1; idx < N; ++idx) {
    for (int diff = 1; diff <= N; ++diff) {
      if (in[idx] == c) {
        opt[idx][diff] = 1 + opt[idx - 1][diff];
      } else {
        opt[idx][diff] = 1 + opt[idx - 1][diff - 1];
      }
    }
  }
  for (int diff = 1, bst; diff <= N; ++diff) {
    bst = 0;
    for (int idx = 0; idx < N; ++idx) {
      max_self(bst, opt[idx][diff]);
    }
    memo[c - 'a'][diff] = bst;
  }
  return;
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> N;
  cin >> in;
  cin >> q;
  for (char c = 'a'; c <= 'z'; ++c) solve(c);
  for (int rep = 0; rep < q; ++rep) {
    int diff;
    char c;
    cin >> diff >> c;
    cout << memo[c - 'a'][diff] << '\n';
  }
  return 0;
}