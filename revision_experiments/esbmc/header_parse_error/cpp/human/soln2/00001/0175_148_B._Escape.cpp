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
  int v1, v2, f, c;
  double t;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> v1 >> v2 >> t >> f >> c;
  double S = t * v1 + ((t * v1) / (v2 - v1)) * v1;
  double D = S;
  int ans = 0;
  if (v1 > v2) {
    cout << 0;
    return 0;
  }
  while (S < c) {
    ++ans;
    S += (2 * S / v2 + f) * v1;
    S += (S - D) / (v2 - v1) * v1;
    D = S;
  }
  cout << ans;
}