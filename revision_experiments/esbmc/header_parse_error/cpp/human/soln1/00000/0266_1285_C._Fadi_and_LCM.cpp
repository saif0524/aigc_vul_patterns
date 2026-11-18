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
vector<long long> factors;
void trial(long long n) {
  int count;
  long long ini = n;
  for (long long d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      ini = n;
      while (n % d == 0) {
        n /= d;
      }
      long long s = ini / n;
      factors.push_back(s);
    }
  }
  if (n > 1) {
    factors.push_back(n);
  }
}
int main() {
  long long n;
  cin >> n;
  trial(n);
  int siz = factors.size();
  long long a = 1;
  long long b = 1;
  long long ra = 1, rb = 1;
  long long mini = 1000000000000;
  for (int i = 1; i < (1 << siz); i++) {
    a = 1;
    b = 1;
    for (int j = 1; j <= siz; j++) {
      if (i & (1 << (j - 1)))
        a *= factors[siz - j];
      else
        b *= factors[siz - j];
    }
    if (mini > max(a, b)) {
      ra = a;
      rb = b;
      mini = max(a, b);
    }
  }
  cout << ra << ' ' << rb << endl;
}