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
  int n;
  cin >> n;
  vector<int> a, b;
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int j = 0; j < n - 1; ++j) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  vector<int> t;
  for (int t0 = 0; t0 < 4; ++t0) {
    int tx = t0;
    t.push_back(t0);
    for (int i = 0; i < n - 1; ++i) {
      int f = 0;
      int tip1;
      for (tip1 = 0; tip1 < 4; ++tip1) {
        if (((tx | tip1) == a[i]) && ((tx & tip1) == b[i])) {
          f = 1;
          t.push_back(tip1);
          break;
        }
      }
      if (f == 0)
        break;
      else {
        tx = tip1;
      }
    }
    if (t.size() == n)
      break;
    else
      t = vector<int>();
  }
  if (t.size() == n) {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      cout << t[i] << " ";
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}