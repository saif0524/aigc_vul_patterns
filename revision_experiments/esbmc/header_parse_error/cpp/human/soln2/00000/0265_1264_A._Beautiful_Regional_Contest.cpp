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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    int l = n / 2 - 1;
    while (p[l] == p[l + 1] && l >= 0) --l;
    if (l < 4) {
      printf("0 0 0\n");
      continue;
    }
    int g = 1, s = 0, b, i;
    for (i = 1; p[i] == p[i - 1]; ++i) {
      ++g;
    }
    while (s <= g && i <= l) {
      ++s;
      for (++i; p[i] == p[i - 1]; ++i) {
        ++s;
      }
    }
    b = l + 1 - g - s;
    if (g >= s || g >= b || g == 0 || s == 0 || b == 0 || (g + s + b) > n / 2) {
      printf("0 0 0\n");
    } else {
      printf("%d %d %d\n", g, s, b);
    }
  }
  return 0;
}