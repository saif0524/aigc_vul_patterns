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
const int INF = 0x3f3f3f3f;
int q, n, a[505];
int main() {
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool pd = 1;
    for (int i = 1; i < n; i++) {
      int xx = a[i] + 1;
      if (xx > n) xx = 1;
      if (xx != a[i + 1]) {
        pd = 0;
        break;
      }
    }
    if (pd) {
      cout << "YES" << endl;
      continue;
    }
    pd = 1;
    for (int i = 1; i < n; i++) {
      int xx = a[i] - 1;
      if (xx == 0) xx = n;
      if (xx != a[i + 1]) {
        pd = 0;
        break;
      }
    }
    if (pd)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}