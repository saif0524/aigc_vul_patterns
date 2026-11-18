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
const long long INF_MAX = 1e18;
const long long INF_MIN = (1e18) * (-1);
const long long mod = 1e9 + 7;
const long long N = 2e5 + 10;
void Solve() {
  long long n;
  cin >> n;
  long long ara[n + 10];
  for (long long i = 1; i <= n; i++) {
    cin >> ara[i];
  }
  vector<long long> v;
  long long mx = 0;
  for (long long i = 1; i < n; i++) {
    if (ara[i] == -1 && ara[i + 1] > -1) {
      v.push_back(ara[i + 1]);
    }
    if (ara[i] > -1 && ara[i + 1] == -1) {
      v.push_back(ara[i]);
    }
    if (ara[i] > -1 && ara[i + 1] > -1) {
      mx = max(mx, abs(ara[i] - ara[i + 1]));
    }
  }
  if (v.size() == 0) {
    cout << 0 << " " << 1 << endl;
    return;
  }
  sort(v.begin(), v.end());
  long long l = v[0], r = v[v.size() - 1];
  long long mid = (l + r) / 2;
  long long k = mid;
  mid = max(abs(l - mid), abs(r - mid));
  cout << max(mid, mx) << " " << k << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long Test = 1;
  cin >> Test;
  while (Test--) {
    Solve();
  }
  return 0;
}