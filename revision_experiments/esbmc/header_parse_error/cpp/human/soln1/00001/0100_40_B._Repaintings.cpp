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
int perimeter(int w, int h) {
  if (w == 1) return h;
  if (h == 1) return w;
  return 2 * w + 2 * (h - 2);
}
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int res = 0;
  while (true) {
    int border = (perimeter(n, m) + 1) / 2;
    --x;
    if (!x) {
      res = border;
      break;
    }
    n -= 2;
    m -= 2;
    if (n <= 0 || m <= 0) {
      break;
    }
  }
  cout << res << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}