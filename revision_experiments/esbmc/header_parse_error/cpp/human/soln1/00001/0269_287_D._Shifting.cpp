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
const int INF = 0x3f3f3f3f;
const int N = 4e6 + 5;
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  int L = 0, R = n - 1;
  for (int i = 2; i <= n; ++i) {
    for (int k = (n - 1) / i; k > 0; --k)
      swap(a[L + (k - 1) * i], a[L + k * i]);
    ++R;
    a[R] = a[L];
    ++L;
  }
  for (int i = 0; i < n; ++i) printf("%d%s", a[L + i], i == n - 1 ? "\n" : " ");
  return 0;
}