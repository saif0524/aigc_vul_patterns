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
long long int cnt = 0;
long long int n, m;
long long int h1[100005], h2[100007];
int main() {
  long long int i, j, k, l, n, m;
  long long int q;
  cin >> q;
  while (q--) {
    cin >> n;
    long long int a[n], t = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) t = i;
    }
    long long int u = 1, nm = 0;
    for (i = t; i < n; i++, u++)
      if (a[i] == u) {
      } else
        nm++;
    for (i = 0; i < t; i++, u++)
      if (a[i] == u) {
      } else
        nm++;
    long long int ut = 0;
    u = 1;
    for (i = t; i >= 0; i--, u++)
      if (a[i] == u) {
      } else
        ut++;
    for (i = n - 1; i > t; i--, u++)
      if (a[i] == u) {
      } else
        ut++;
    if (nm > 0 && ut > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}