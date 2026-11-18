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
bool check_prime(long long n) {
  long long flag = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }
  if (n == 1)
    return false;
  else if (flag == 0 || n == 2 || n == 3) {
    return true;
  } else {
    return false;
  }
}
long long BE(long long x, long long n, long long m) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = result * x % m;
    x = x * x % m;
    n = n / 2;
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long n;
  cin >> n;
  long long x[n], h[n];
  long long cnt = 2;
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
  }
  for (long long i = 1; i < n - 1; i++) {
    if (x[i] - x[i - 1] - 1 >= h[i]) {
      cnt++;
    } else if (x[i] + h[i] < x[i + 1]) {
      cnt++;
      x[i] += h[i];
    }
  }
  if (n == 1) {
    cout << 1 << '\n';
  } else
    cout << cnt << '\n';
  return 0;
}