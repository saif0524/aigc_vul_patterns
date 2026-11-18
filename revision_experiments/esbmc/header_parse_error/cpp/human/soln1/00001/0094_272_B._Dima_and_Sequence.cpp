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
vector<int> f(100001);
int comp(int i) {
  int b = 0, d = 0;
  while (i > 0) {
    if (i & 1 == 1) b++;
    i = i >> 1;
  }
  return b;
}
int main() {
  int m, i, n;
  int h[65];
  long long j, s;
  for (i = 0; i < 65; i += 2) {
    h[i] = 0;
    h[i + 1] = 0;
  }
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> f[i];
  }
  for (i = 0; i < n; i++) {
    h[comp(f[i])]++;
  }
  s = 0;
  for (i = 0; i < 65; i++) {
    j = h[i];
    j = j * (j - 1);
    j = j / 2;
    s += j;
  }
  cout << s;
  return 0;
}