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
bool isPrime(long long int n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (long long int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / (gcd(a, b));
}
void swap(int& a, int& b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
inline void solve() {
  long long int a, b;
  cin >> a >> b;
  int x = 0, y = 0, z = 0;
  while (a % 2 == 0) {
    a = a / 2;
    x++;
  }
  while (a % 3 == 0) {
    a = a / 3;
    y++;
  }
  while (a % 5 == 0) {
    a = a / 5;
    z++;
  }
  while (b % 2 == 0) {
    b = b / 2;
    x--;
  }
  while (b % 3 == 0) {
    b = b / 3;
    y--;
  }
  while (b % 5 == 0) {
    b = b / 5;
    z--;
  }
  if (a != b)
    cout << -1 << '\n';
  else
    cout << abs(x) + abs(y) + abs(z) << '\n';
}
signed main() {
  auto start_time = clock();
  cerr << setprecision(3) << fixed;
  cout << setprecision(15) << fixed;
  ((void)0);
  ((void)0);
  ((void)0);
  solve();
  auto end_time = clock();
  cerr << "Execution time: "
       << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
  return 0;
}