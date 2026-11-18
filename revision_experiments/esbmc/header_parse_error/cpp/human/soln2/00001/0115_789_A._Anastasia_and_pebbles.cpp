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
int n;
int k;
int a[100005];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int i = 0;
  int cnt = 0;
  while (i < n) {
    if (a[i] <= 0) {
      i++;
      continue;
    }
    if (a[i] >= 2 * k) {
      ans += a[i] / (2 * k);
      a[i] %= (2 * k);
    } else if (a[i] > 0) {
      cnt++;
      a[i] -= k;
      if (a[i] <= 0) i++;
      if (cnt == 2) {
        ans++;
        cnt = 0;
      }
    }
  }
  if (cnt > 0) ans++;
  cout << ans;
  return 0;
}