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
  int r1, r2, c1, c2, d1, d2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (i + j == r1 && i != j) {
        for (int k = 1; k < 10; k++) {
          if (i + k == c1 && k + j == d2 && j != k && i != k) {
            for (int l = 1; l < 10; l++) {
              if (l + k == r2 && l + i == d1 && l != k && l != i && j != l) {
                cout << i << " " << j << '\n';
                cout << k << " " << l << '\n';
                return;
              }
            }
          }
        }
      }
    }
  }
  cout << -1 << '\n';
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}