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
const int N = 200010;
long long i, j, n, m, k, a[N], s, r, ss;
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  s = 0, r = 1;
  for (i = n - 1; i >= 0; i--, r *= m) s = s + r * a[i];
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  ss = 0, r = 1;
  for (i = n - 1; i >= 0; i--, r *= m) ss = ss + r * a[i];
  if (ss < s)
    cout << '>';
  else if (ss > s)
    cout << '<';
  else
    cout << '=';
  return 0;
}