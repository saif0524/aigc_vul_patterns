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
const int INF = numeric_limits<int>::max();
const long long LLINF = numeric_limits<long long>::max();
const unsigned long long ULLINF = numeric_limits<unsigned long long>::max();
const double PI = acos(-1.0);
int main() {
  ((void)0);
  ((void)0);
  long long t[50];
  long long n, k, M;
  cin >> n >> k >> M;
  long long sum = 0;
  for (int i = 0; i < k; i++) cin >> t[i], sum += t[i];
  sort(t, t + k);
  long long ans = 0;
  for (int s = 0; s <= n; s++) {
    if (sum * s > M) break;
    long long p = n - s;
    long long T = M - sum * s;
    long long cur = (k + 1) * s;
    for (int i = 0; i < k; i++) {
      long long take = min(T / t[i], p);
      cur += take;
      T -= take * t[i];
    }
    ans = max(ans, cur);
  }
  cout << ans;
  return 0;
}