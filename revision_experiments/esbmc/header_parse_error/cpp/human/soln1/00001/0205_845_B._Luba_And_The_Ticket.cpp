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
const long long inf = 1e9 + 7;
const int N = 1e5 + 5;
long long n, k;
long long A[N], B[N];
int main() {
  long long i, j, ans = inf, cnt, a = 0, b = 0, l;
  string s, t;
  cin >> s;
  for (i = 0; i < 6; i++) A[i] = s[i] - '0';
  for (i = 0; i < 3; i++) a += A[i];
  for (i = 3; i < 6; i++) b += A[i];
  if (a > b) {
    k = 1;
    swap(a, b);
  }
  multiset<long long> st[2];
  for (i = 3; i < 6; i++) st[1 - k].insert(A[i]);
  for (i = 0; i < 3; i++) st[k].insert(A[i]);
  while (a < b) {
    long long c, d;
    c = *st[0].begin();
    d = *st[1].rbegin();
    if (9 - c > d) {
      a += 9 - c;
      st[0].erase(st[0].begin());
    } else {
      a += d;
      st[1].erase(st[1].find(d));
    }
    ans++;
  }
  cout << ans - inf;
}