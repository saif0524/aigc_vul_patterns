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
;
bool ch[26];
int is[26], a[5000], coun[26];
int32_t main() {
  ((void)0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  ((void)0);
  string s;
  cin >> s;
  int n = s.size();
  for (int i = (0); i < (n); ++i) {
    a[i] = s[i] - 'a';
  };
  int m = 0;
  for (int c = (0); c < (26); ++c) {
    int mx = 0;
    for (int s = (1); s < (n); ++s) {
      vector<int> is(26, 0);
      for (int i = (0); i < (n); ++i) {
        if (a[i] == c) is[a[(i + s) % n]]++;
      }
      int cur = 0;
      for (int i = (0); i < (26); ++i) cur += (is[i] == 1);
      mx = max(mx, cur);
    }
    m += mx;
  }
  cout << 1.0 * m / n << endl;
  return 0;
}