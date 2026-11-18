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
const int N = 4e5 + 5;
int a[N], t[N];
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int k = 0; k <= 24; k++) {
    for (int i = 0; i < n; i++) t[i] = a[i] % (1 << (k + 1));
    sort(t, t + n);
    long long cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      cnt += (lower_bound(t + i + 1, t + n, (1 << (k + 1)) - t[i]) -
              lower_bound(t + i + 1, t + n, (1 << k) - t[i]));
      cnt +=
          n -
          (lower_bound(t + i + 1, t + n, (1 << k) + (1 << (k + 1)) - t[i]) - t);
    }
    ans |= (1 << k) * (cnt % 2);
  }
  cout << ans << endl;
  return 0;
}