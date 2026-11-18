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
int main() {
  ((void)0);
  ((void)0);
  long long n, k;
  cin >> n >> k;
  long long f[n], w[n];
  for (long long i = 0; i < n; i++) cin >> f[i];
  for (long long i = 0; i < n; i++) cin >> w[i];
  long long mh = 0;
  while ((1LL << mh) <= k) mh++;
  long long up[n][mh], s[n][mh], m[n][mh];
  for (long long i = 0; i < n; i++) {
    up[i][0] = f[i];
    s[i][0] = w[i];
    m[i][0] = w[i];
  }
  for (long long j = 1; j < mh; j++)
    for (long long i = 0; i < n; i++) {
      up[i][j] = up[up[i][j - 1]][j - 1];
      s[i][j] = s[i][j - 1] + s[up[i][j - 1]][j - 1];
      m[i][j] = min(m[i][j - 1], m[up[i][j - 1]][j - 1]);
    }
  for (long long i = 0; i < n; i++) {
    long long curr = i, s1 = 0, m1 = 1000000000;
    for (long long j = 0; j < mh; j++)
      if ((k >> j) & 1) {
        s1 += s[curr][j];
        m1 = min(m1, m[curr][j]);
        curr = up[curr][j];
      }
    cout << s1 << " " << m1 << endl;
  }
}