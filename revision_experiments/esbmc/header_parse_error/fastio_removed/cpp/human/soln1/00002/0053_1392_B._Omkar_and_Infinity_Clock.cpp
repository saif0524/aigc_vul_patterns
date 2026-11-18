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
  ((void)0);
  long long t, i, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long a[n], maxa;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (k % 2 != 0) {
      maxa = a[0];
      for (i = 0; i < n; i++) {
        maxa = max(maxa, a[i]);
      }
      for (i = 0; i < n; i++) {
        a[i] = maxa - a[i];
      }
    } else {
      maxa = a[0];
      for (i = 0; i < n; i++) {
        maxa = max(maxa, a[i]);
      }
      for (i = 0; i < n; i++) {
        a[i] = maxa - a[i];
      }
      maxa = a[0];
      for (i = 0; i < n; i++) {
        maxa = max(maxa, a[i]);
      }
      for (i = 0; i < n; i++) {
        a[i] = maxa - a[i];
      }
    }
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}