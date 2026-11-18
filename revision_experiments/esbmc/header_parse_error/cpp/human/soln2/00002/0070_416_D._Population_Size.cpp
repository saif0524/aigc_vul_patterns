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
long long a[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int k = 0;
  int ans = 0;
  for (k = 1; k <= n;) {
    ans++;
    int fir = k;
    while (a[fir] == -1) {
      fir++;
    }
    int sec = fir + 1;
    while (a[sec] == -1) {
      sec++;
    }
    if (sec > n) {
      break;
    }
    if ((a[sec] - a[fir]) % (sec - fir) != 0) {
      k = sec;
      continue;
    }
    long long d = (a[sec] - a[fir]) / (sec - fir);
    if (a[sec] - d * (sec - k) < 1) {
      k = sec;
      continue;
    }
    for (k = sec + 1; k <= n && a[sec] + d * (k - sec) >= 1 &&
                      (a[k] == -1 || a[k] == a[sec] + d * (k - sec));
         k++)
      ;
  }
  cout << ans;
  return 0;
}