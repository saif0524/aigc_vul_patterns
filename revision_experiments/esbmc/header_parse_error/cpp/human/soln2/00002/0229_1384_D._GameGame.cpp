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
const double pi = 3.14159265359;
const int MAX = 1e6 + 2;
const long long int inf = 1e18;
const int N = 1010;
const long long int mod = 1000000007;
inline long long int add(long long int a, long long int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline long long int mul(long long int a, long long int b) {
  return (((a + mod) % mod) * (b + mod) % mod) % mod;
}
inline long long int power(long long int a, long long int b) {
  long long int rt = 1;
  while (b > 0) {
    if (b & 1) rt = mul(rt, a);
    a = mul(a, a);
    b >>= 1;
  }
  return rt;
}
inline long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2) % p;
}
void stArt() {}
void eNd() {}
long long int i, j, k, l, m, r, n;
long long int a[MAX], b[MAX];
int main() {
  stArt();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    cin >> n;
    long long int tmp = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      tmp ^= a[i];
    }
    if (!tmp) {
      cout << "DRAW\n";
      continue;
    }
    l = (long long int)(log2(tmp)), r = 0;
    for (i = 0; i < n; i++)
      if ((a[i] >> l) & 1) r++;
    l = n - r;
    if (r % 4 == 1 || l & 1)
      cout << "WIN\n";
    else
      cout << "LOSE\n";
  }
  eNd();
  return 0;
}