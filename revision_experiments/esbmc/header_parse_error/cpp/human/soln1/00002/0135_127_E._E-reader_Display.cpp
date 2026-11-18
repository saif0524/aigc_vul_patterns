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
const int nmax = 2009;
int a[2009][2009];
int ui[nmax], uj[nmax];
int n;
void inc(int &a) {
  ++a;
  a = a & 1;
}
int main() {
  int ans = 0;
  scanf("%d\n", &n);
  char s[nmax];
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int j = 1; j <= n; j++) a[i][j] = s[j - 1] - '0';
  }
  for (int k = n; k >= 1; k--) {
    int p = 0;
    for (int i = 1; i < k; i++) {
      if ((p & 1) == 1) inc(a[i][k]);
      if ((ui[i] & 1) == 1) inc(a[i][k]);
      if (a[i][k] != 0) {
        inc(p);
        inc(ui[i]);
        inc(a[i][k]);
        ans++;
      }
    }
    if ((p & 1) == 1) inc(a[k][k]);
    if ((ui[k] & 1) == 1) inc(a[k][k]);
    p = 0;
    for (int j = 1; j < k; j++) {
      if ((p & 1) == 1) inc(a[k][j]);
      if ((uj[j] & 1) == 1) inc(a[k][j]);
      if (a[k][j] != 0) {
        inc(p);
        inc(uj[j]);
        inc(a[k][j]);
        ans++;
      }
    }
    if ((p & 1) == 1) inc(a[k][k]);
    if ((uj[k] & 1) == 1) inc(a[k][k]);
    if (a[k][k] != 0) {
      ans++;
      inc(a[k][k]);
    }
  }
  cout << ans << endl;
  return 0;
}