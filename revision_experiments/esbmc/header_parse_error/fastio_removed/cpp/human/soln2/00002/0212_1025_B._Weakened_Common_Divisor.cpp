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
long long n, b[150001], c[150001], a[150001], p, j;
vector<int> pr;
bool check(int X) {
  if (X == 1) return false;
  for (int i = 2; i <= n; ++i)
    if ((a[i] % X) * (b[i] % X) > 0) return false;
  return true;
}
void ktnt(int X) {
  j = 0;
  long long k = X;
  for (int i = 2; i * i <= k; ++i)
    if (k % i == 0) {
      j++, c[j] = i;
      while (k % i == 0) {
        k /= i;
      }
    }
  if (k > 1) j++, c[j] = k;
}
void run(int X) {
  ktnt(X);
  for (int i = 1; i <= j; ++i) {
    if (check(c[i])) {
      cout << c[i];
      exit(0);
    }
    if (check(X / c[i])) {
      cout << X / c[i];
      exit(0);
    }
  }
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  run(a[1]);
  run(b[1]);
  cout << -1;
}