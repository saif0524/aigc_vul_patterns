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
  int64_t n, l, r;
  cin >> n >> l >> r;
  l--, r--;
  int64_t cnt = 0;
  int64_t start = 1;
  int64_t num = n - 1;
  while (start < n) {
    if (l < cnt + 2 * num && r >= cnt) {
      for (int64_t i = 0; i < 2 * num; i++) {
        if (l <= cnt + i && cnt + i <= r) {
          if (i & 1)
            cout << start + (i + 1) / 2 << ' ';
          else
            cout << start << ' ';
        }
      }
    }
    cnt += 2 * num;
    num--;
    start++;
  }
  if (r == cnt) cout << 1;
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}