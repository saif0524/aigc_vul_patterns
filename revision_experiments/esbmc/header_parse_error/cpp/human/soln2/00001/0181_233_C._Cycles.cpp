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
  int k, n;
  cin >> k;
  for (int v(100); v >= 3; --v) {
    if (v * (v - 1) * (v - 2) / 6 < k) {
      n = v;
      k -= v * (v - 1) * (v - 2) / 6;
      break;
    } else {
      if (v * (v - 1) * (v - 2) / 6 == k) {
        cout << v << endl;
        for (int i(0); i < v; ++i) {
          for (int j(0); j < v; ++j) {
            if (i == j)
              cout << 0;
            else
              cout << 1;
          }
          cout << endl;
        }
        return 0;
      }
    }
  }
  int data[104][104];
  for (int i(0); i < n; ++i)
    for (int j(0); j < n; ++j) data[i][j] = 1;
  int edge(2);
  while (k) {
    int i(1);
    for (;; ++i) {
      if (i * (i + 1) / 2 > k) break;
    }
    for (int j(0); j < i; ++j) {
      data[n][j] = data[j][n] = 1;
    }
    ++n;
    k -= i * (i - 1) / 2;
  }
  cout << n << endl;
  for (int i(0); i < n; ++i) {
    for (int j(0); j < n; ++j)
      if (i == j)
        cout << 0;
      else
        cout << data[i][j];
    cout << endl;
  }
  return 0;
}