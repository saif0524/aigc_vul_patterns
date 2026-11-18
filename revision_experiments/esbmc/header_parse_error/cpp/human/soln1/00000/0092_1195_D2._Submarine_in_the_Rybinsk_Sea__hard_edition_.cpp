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
const int mod = 998244353;
const int Nmax = 100555;
int digit_tally[11];
int n, a[Nmax];
int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int digits = floor(log10(a[i])) + 1;
    digit_tally[digits]++;
  }
  long long result = 0;
  for (int i = 0; i < n; i++) {
    int b[11][2];
    for (int k = 0; k < 11; k++) {
      b[k][0] = 0;
      b[k][1] = 0;
    }
    int digits = 0;
    int x = a[i];
    while (x) {
      digits++;
      b[digits][0] = x % 10;
      x /= 10;
      b[digits][1] = x;
    }
    long long power = 1;
    long long sparsed = 0;
    for (int j = 1; j <= 10; j++) {
      sparsed = (power * b[j][0] + sparsed) % mod;
      power = (power * 100) % mod;
      if (!digit_tally[j]) continue;
      if (digits > j) {
        long long rest = 1ll * b[j][1] * power;
        result += (((rest * 2) % mod) * digit_tally[j]) % mod;
      }
      result += (((sparsed * 11) % mod) * digit_tally[j]) % mod;
    }
    result = result % mod;
  }
  cout << result << endl;
  return 0;
}