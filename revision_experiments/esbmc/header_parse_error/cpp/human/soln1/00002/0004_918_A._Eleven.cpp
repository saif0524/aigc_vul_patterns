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
#pragma GCC optimize("O3")
using namespace std;
int n;
set<int> s;
inline void init() {
  int x = 1, y = 1;
  s.insert(1);
  for (int z = 2; z <= 1000; z = x + y) {
    s.insert(z);
    x = y, y = z;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  init();
  cin >> n;
  for (int i = 1; i <= n; ++i)
    if (s.find(i) != s.end())
      cout << 'O';
    else
      cout << 'o';
  return 0;
}