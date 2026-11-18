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
void solve() {
  long long n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  s = 'a' + s;
  for (long long i = n; i >= 1; i--) {
    long long tt = s[i] - 'a';
    for (long long j = tt + 1; j < p; j++) {
      bool f1 = true;
      char c = (char)(j + 'a');
      if (i != 1) {
        if (c == s[i - 1]) f1 = false;
      }
      if (i >= 3) {
        if (c == s[i - 2]) f1 = false;
      }
      if (f1 == true) {
        s[i] = c;
        for (long long j = i + 1; j <= n; j++) {
          for (long long k = 0; k < p; k++) {
            bool f2 = true;
            c = (char)(k + 'a');
            if (j != 1) {
              if (c == s[j - 1]) f2 = false;
            }
            if (j >= 3) {
              if (c == s[j - 2]) f2 = false;
            }
            if (f2) {
              s[j] = c;
              break;
            }
          }
        }
        s = s.substr(1, n);
        cout << s << "\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int32_t main() {
  ((void)0);
  ((void)0);
  ((void)0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}