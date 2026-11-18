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
int gcd(int xx, int yy) {
  while (yy != 0) {
    xx = xx % yy;
    swap(xx, yy);
  }
  return xx;
}
int lcm(int xx, int yy) { return (xx / gcd(xx, yy)) * yy; }
int c, v0, v1, a, l;
int main() {
  cin >> c >> v0 >> v1 >> a >> l;
  int res = 0;
  int idx = 0;
  c -= v0;
  res += 1;
  while (c > 0) {
    idx += 1;
    int tmp = min(v1, v0 + a * idx) - l;
    res += 1;
    c -= tmp;
  }
  cout << res << endl;
}