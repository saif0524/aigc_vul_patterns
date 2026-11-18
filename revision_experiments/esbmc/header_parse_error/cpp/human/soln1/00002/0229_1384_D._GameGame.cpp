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
#pragma GCC optimize(2)
#pragma GCC optimize(3)
int t, n, x;
int num[30];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i++) {
      cin >> x;
      int cnt = 0;
      while (x) {
        if (x & 1) {
          num[cnt]++;
        }
        x >>= 1;
        cnt++;
      }
    }
    for (int i = 29; i >= 0; i--) {
      if (num[i] & 1) {
        if (!((n - num[i]) & 1) && (num[i] % 4 == 3)) {
          cout << "LOSE" << '\n';
        } else {
          cout << "WIN" << '\n';
        }
        goto end;
      }
    }
    cout << "DRAW" << '\n';
  end:;
  }
  return 0;
}