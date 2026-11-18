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
long long t[2222];
long long p1[5555];
long long p2[20000];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> t[i];
  }
  sort(t, t + n);
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < n; ++j) {
      p1[t[j] - t[i]]++;
    }
  }
  for (long long i = 0; i < 5555; ++i) {
    for (long long j = 0; j < 5555; ++j) {
      p2[i + j] += p1[i] * p1[j];
    }
  }
  long double ans = 0;
  long double q = 0;
  for (int i = 1; i < 5555; ++i) {
    q += p2[i - 1];
    ans += p1[i] * q;
  }
  ans /= (long double)n * (n - 1) * n * (n - 1) * n * (n - 1) / 8;
  cout << fixed << setprecision(15) << ans << '\n';
}