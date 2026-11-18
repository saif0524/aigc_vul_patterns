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
const int dl = 1e9 + 7;
const int M = 4e5 + 10;
int a[M];
map<int, int> cnt;
int presum[M];
int tt[M];
int n;
long long s;
long long k;
int32_t main() {
  cin >> n >> s;
  long long t = (8 * s) / n;
  if (t >= 31) {
    cout << "0";
    return 0;
  }
  k = 1 << t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int sz = 1;
  for (auto x : cnt) {
    tt[sz] = x.first;
    presum[sz] = presum[sz - 1] + x.second;
    sz++;
  }
  int ans = n;
  for (int i = 1; i < sz; i++) {
    int y = i + k;
    if (i + k >= sz)
      ans = min(ans, presum[i - 1]);
    else {
      ans = min(ans, n - presum[y - 1] + presum[i - 1]);
    }
  }
  cout << ans << endl;
  return 0;
}