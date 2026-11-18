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
const int MOD = 1e9 + 7;
int add(int x, int y, int CMOD = MOD) { return (0LL + x + y) % CMOD; }
int mult(int x, int y, int CMOD = MOD) { return (1LL * x * y) % CMOD; }
long long fast_expo(long long x, long long y, long long CMOD = MOD) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long ans = fast_expo(x, y / 2, CMOD);
  ans = mult(ans, ans, CMOD);
  if (y & 1) ans = mult(ans, x, CMOD);
  return ans;
}
const int TAM = 2e5 + 100;
const long long INF = LLONG_MAX / 4;
int n;
int a[TAM];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int k;
  cin >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (a[n / 2] == k) {
    cout << "0" << endl;
    return 0;
  }
  long long ans = 0;
  if (a[n / 2] < k) {
    for (int i = n / 2; i < n; i++) {
      ans += max(0, k - a[i]);
    }
  } else {
    for (int i = n / 2; i >= 0; i--) {
      ans += max(0, a[i] - k);
    }
  }
  cout << ans << endl;
  return 0;
}