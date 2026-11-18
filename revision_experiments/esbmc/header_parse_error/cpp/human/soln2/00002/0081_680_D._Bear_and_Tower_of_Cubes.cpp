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
string toBin(long long a) {
  string res = "";
  while (a) {
    res += char((a & 1) + '0');
    a >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}
const int mod = 1e9 + 7;
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % mod;
    }
    base *= base;
    base %= mod;
    pow /= 2;
  }
  return ans;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
const int M = 100001;
pair<long long, long long> best;
inline long long po(long long x) { return x * x * x; }
void rec(long long m, long long blocks, long long tot) {
  if (m == 0) {
    best = max(best, make_pair(blocks, tot));
    return;
  }
  long long x = 1;
  while (po(x + 1) <= m) {
    x++;
  }
  rec(m - po(x), blocks + 1, tot + po(x));
  if (x >= 1) {
    rec(po(x) - 1 - po(x - 1), blocks + 1, tot + po(x - 1));
  }
}
int main() {
  long long m;
  cin >> m;
  best = make_pair(0, 0);
  rec(m, 0, 0);
  cout << best.first << " " << best.second;
}