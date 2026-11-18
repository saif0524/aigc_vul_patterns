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
typedef long long ll;
ll n, q, k, d;
ll a[100];
int main() {
  cin >> n >> q >> k >> d;
  ll x = k;
  ll y = d;
  for (int i = q - 1; i >= 0; i--) {
    if (y * 2 > n) {
      a[i] = 1;
      y = (y - n / 2);
    } else {
      a[i] = 0;
      y = (y * 2 - 1);
    }
  }
  ll z = 1;
  for (int i = 0; i < q; i++) {
    if (a[i] == 0) {
      z = z * 2 - 1;
    } else {
      z = z * 2;
    }
  }
  if (z != x) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < q; i++) {
    cout << a[i] << endl;
  }
  return 0;
}