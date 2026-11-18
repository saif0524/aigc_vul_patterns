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
long long smallestDivisor(long long n) {
  if (n % 2 == 0) return 2;
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  long long n;
  cin >> n;
  long long x = smallestDivisor(n);
  long long count = 0;
  while (true) {
    if (x == 2) {
      cout << (n / x) + count;
      return 0;
    } else {
      n -= x;
      count++;
      if (n == 0) {
        cout << count;
        return 0;
      }
      x = smallestDivisor(n);
    }
  }
  return 0;
}