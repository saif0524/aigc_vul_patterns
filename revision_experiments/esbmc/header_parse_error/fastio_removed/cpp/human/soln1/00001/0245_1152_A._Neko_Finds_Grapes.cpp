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
  ((void)0);
  ((void)0);
  long long n, m, i, j, a, b, o = 0, e = 0, o1 = 0, e1 = 0, c, d;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a % 2 == 1)
      o++;
    else
      e++;
  }
  for (j = 0; j < m; j++) {
    cin >> b;
    if (b % 2 == 1)
      o1++;
    else
      e1++;
  }
  c = min(o, e1);
  d = min(o1, e);
  cout << c + d;
  return 0;
}