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
long long int xpow(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long int k = xpow(a, b / 2);
    return k * k;
  }
  if (b % 2 != 0) return a * xpow(a, b - 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, sx, sy;
  cin >> n >> sx >> sy;
  int l = 0, r = 0, d = 0, u = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x > sx) r++;
    if (x < sx) l++;
    if (y > sy) u++;
    if (y < sy) d++;
  }
  int maxi = max({l, r, d, u});
  cout << maxi << endl;
  if (l == maxi)
    sx--;
  else if (r == maxi)
    sx++;
  else if (u == maxi)
    sy++;
  else if (d == maxi)
    sy--;
  cout << sx << " " << sy << endl;
  return 0;
}