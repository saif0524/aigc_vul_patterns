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
  long long q, n, m, k, mx;
  cin >> q;
  while (q--) {
    cin >> n >> m >> k;
    n = abs(n);
    m = abs(m);
    mx = -1;
    if (max(n, m) <= k) {
      if (n == m) {
        mx = n - 1;
        if ((k - mx) % 2) {
          mx = k;
        } else {
          mx += (k - mx - 2);
        }
      } else {
        mx = max(m, n) - 1;
        if ((n - m) % 2) {
          mx += (k - mx - 1);
        } else {
          if ((k - mx) % 2) {
            mx = k;
          } else {
            mx += (k - mx - 2);
          }
        }
      }
    }
    cout << mx << endl;
  }
  return 0;
}