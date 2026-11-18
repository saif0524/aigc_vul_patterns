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
long long BE(int a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
    }
    a = a * a;
    b = b >> 1;
  }
  return res;
}
void pro() {
  bool ok = 0, gf = 1, flag = 0;
  long long n = 3, d = 0, k = 1e10, m = 0, p = 0, o = 0;
  cin >> n;
  vector<string> a(n), b(n);
  for (int i = 0; i < int(n); i++) cin >> a[i];
  for (int i = 0; i < int(n); i++) cin >> b[i];
  map<string, int> cnta, cntb;
  for (int i = 0; i < int(n); i++) ++cnta[a[i]];
  for (int i = 0; i < int(n); i++) ++cntb[b[i]];
  int ans = n;
  for (auto it : cnta) ans -= min(it.second, cntb[it.first]);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pro();
}