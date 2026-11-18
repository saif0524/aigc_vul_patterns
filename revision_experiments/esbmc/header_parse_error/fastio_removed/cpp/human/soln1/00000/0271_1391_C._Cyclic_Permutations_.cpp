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
const double pi = 3.14159265358979323846;
long long binpow(long long, long long);
long long mult(long long, long long);
long long add(long long, long long);
long long division(long long, long long);
long long nCr(long long, long long);
long long inv(long long);
void calc();
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v) is >> x;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
  }
  return os;
}
const int N = 1000005;
long long fact[N];
void solve() {
  long long n;
  cin >> n;
  cout << (fact[n] - binpow(2, n - 1) + 1000000007) % 1000000007;
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int t = 1;
  calc();
  for (long long i = 0; i < t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
long long add(long long a, long long b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
  while (a < 0) a += 1000000007;
  return a;
}
long long mult(long long a, long long b) { return (a * 1ll * b) % 1000000007; }
long long binpow(long long a, long long b) {
  long long c = 1;
  while (b > 0) {
    if (b % 2 == 1) c = mult(c, a);
    a = mult(a, a);
    b /= 2;
  }
  return c;
}
long long inv(long long a) { return binpow(a, 1000000007 - 2); }
long long division(long long a, long long b) { return mult(a, inv(b)); }
void calc() {
  fact[0] = 1;
  for (long long i = 1; i <= N - 1; i++)
    fact[i] = (i * 1ll * fact[i - 1]) % 1000000007;
}