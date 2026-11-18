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
  short l = 0;
  bool b = 0;
  vector<vector<short>> v(3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) {
      cin >> l;
      v[i].push_back(l);
    }
  short x = (v[2][1] - v[0][1] + v[1][1]) / 2;
  short a[4];
  a[0] = v[0][0] - x;
  a[1] = x;
  a[2] = v[0][1] - v[1][1] + x;
  a[3] = v[1][1] - x;
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++) {
      if (a[i] == a[j]) {
        b = 1;
        j = 4;
        i = 4;
      }
    }
  for (int i = 0; i < 4; i++) {
    if (a[i] < 1 || a[i] > 9) {
      b = 1;
      i = 4;
    }
  }
  if (a[2] + a[0] != v[1][0]) b = 1;
  if (b)
    cout << -1 << endl;
  else {
    cout << a[0] << " " << a[1] << endl;
    cout << a[2] << " " << a[3] << endl;
  }
  return 0;
}