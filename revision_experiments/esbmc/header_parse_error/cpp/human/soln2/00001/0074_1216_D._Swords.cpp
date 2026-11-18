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
int a[200050];
int gcd(int a, int b) {
  if (a < b) {
    int t = a;
    a = b;
    b = t;
  }
  if (b == 0) return a;
  while (a % b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return b;
}
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, ma = 0;
  cin >> n;
  int i, k;
  long long s = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, cmp);
  ma = a[1];
  if (n == 2)
    k = ma - a[2];
  else
    k = gcd(ma - a[3], ma - a[2]);
  for (i = 2; i <= n; i++) {
    s += ma - a[i];
    k = gcd(k, ma - a[i]);
  }
  cout << s / k << ' ' << k << endl;
}