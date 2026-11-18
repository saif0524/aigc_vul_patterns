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
bool isOdd(int val) { return val % 2; }
int nod(int a, int b) {
  if (a > b) swap(a, b);
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}
int main(int argc, char **argv) {
  int n;
  std::cin >> n;
  int div = 0;
  if (isOdd(n)) {
    div = (n - 1) / 2;
  } else {
    div = n / 2;
  }
  for (int i = div; i > 0; --i) {
    int a = i;
    int b = n - a;
    if (nod(a, b) == 1) {
      cout << a << " " << b;
      return 0;
    }
  }
  return 0;
}