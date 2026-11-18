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
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fact(long long j) {
  long long a = 1;
  for (long long i = 1; i <= j; i++) a *= i;
  return a;
}
long long pw(long long a, long long b) {
  long long s = 1;
  for (int i = 0; i < (b); i++) s *= a;
  return s;
}
long long sum2(long long c) {
  long long s = 0;
  while (c != 0) {
    s += (c % 10) * (c % 10);
    c /= 10;
  }
  return s;
}
vector<int> merge(const vector<int>& a, const vector<int>& b) {
  long long p1 = 0, p2 = 0;
  vector<int> c;
  for (; p1 < a.size() && p2 < b.size();)
    if (a[p1] == b[p2]) {
      c.push_back(a[p1]);
      p1++;
      p2++;
    } else if (a[p1] < b[p2])
      p1++;
    else
      p2++;
  return c;
}
bool cmp(long long a, long long b) { return (a < b); }
bool prime(long long a) {
  if (a == 0 || a == 1) return false;
  for (int i = 2; i <= sqrt(a); i++)
    if (a % i == 0) return false;
  return true;
}
long long C(long long n, long long k) {
  vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, 1));
  for (int i = 0; i < (n + 1); i++) {
    for (int j = 1; j < i; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }
  return dp[n][k];
}
int d(int x, int y) {
  if (y == 0)
    throw 0;
  else
    return x / y;
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  long long ans = 0, k = 0;
  for (int i = 0; i < (m); i++) {
    long long x, y;
    cin >> x >> y;
    long long s = 0;
    x--;
    y--;
    for (int j = x; j <= y; j++) s += a[j];
    if (s > 0) ans += s;
  }
  cout << ans << endl;
  return 0;
}