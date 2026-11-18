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
int n, m, ans;
long long a[200005], d;
int main() {
  cin >> n;
  int i, j;
  for (i = 1; i <= n; i++) cin >> a[i];
  int k = 1;
  while (k <= n) {
    ans++;
    for (i = k; a[i] == -1; i++)
      ;
    for (j = i + 1; a[j] == -1; j++)
      ;
    if (j > n) break;
    d = (a[j] - a[i]) / (j - i);
    if ((a[j] - a[i]) % (j - i) || a[j] - d * (j - k) <= 0) {
      k = j;
      continue;
    }
    k = j + 1;
    while (k <= n && (long long)a[j] + d * (k - j) > 0 &&
           (a[k] == -1 || a[k] == a[j] + d * (k - j))) {
      k++;
    }
  }
  cout << ans;
}