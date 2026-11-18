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
const long long maxn = 3e5 + 10;
long long N, R, arr[maxn], T;
signed main() {
  ((void)0);
  ((void)0);
  cin >> T;
  while (T--) {
    cin >> N >> R;
    for (register long long i = 1; i <= N; ++i) {
      cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + N);
    N = unique(arr + 1, arr + 1 + N) - arr - 1;
    long long sum = 0, ans = 0;
    for (long long i = N; i >= 1; --i) {
      if (arr[i] - sum <= 0) {
        break;
      }
      ++ans;
      sum += R;
    }
    cout << ans << endl;
  }
  return 0;
}