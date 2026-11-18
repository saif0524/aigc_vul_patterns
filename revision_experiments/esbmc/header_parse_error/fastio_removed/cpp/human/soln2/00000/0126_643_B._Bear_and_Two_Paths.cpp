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
long long int n, k, a, b, c, d, p;
int main() {
  ((void)0);
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  p = (n * (n - 1)) / 2;
  p -= 2;
  if (n == 4) {
    cout << -1;
    return 0;
  }
  if (k < n + 1) {
    cout << -1;
    return 0;
  }
  if (k > p) {
    cout << -1;
    return 0;
  }
  cout << a << " " << c << " ";
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) cout << i << " ";
  }
  cout << d << " " << b << endl;
  cout << c << " " << a << " ";
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) cout << i << " ";
  }
  cout << b << " " << d << endl;
  return 0;
}