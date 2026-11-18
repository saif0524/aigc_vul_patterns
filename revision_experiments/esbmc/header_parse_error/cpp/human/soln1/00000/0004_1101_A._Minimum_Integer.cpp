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
long long f[1000001];
long long pow(long long a, long long b, long long MOD) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = (y * y);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
long long InverseEuler(long long n, long long MOD) {
  return pow(n, MOD - 2, MOD);
}
long long C(long long n, long long r, long long MOD) {
  return (f[n] *
          ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) %
         MOD;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long l, r, d;
    cin >> l >> r >> d;
    long long ans1 = d;
    long long y = r / d;
    long long ans2 = (y + 1) * d;
    if (d >= l)
      cout << ans2 << endl;
    else
      cout << ans1 << endl;
  }
}