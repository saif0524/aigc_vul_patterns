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
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int t;
  std::cin >> t;
  for (int cas = 0; cas < t; ++cas) {
    int n;
    std::cin >> n;
    std::string str;
    std::cin >> str;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i)
      if (str[i] == '>') {
        l = i;
        break;
      }
    for (int i = n - 1; i > 0; --i)
      if (str[i] == '<') {
        r = i;
        break;
      }
    std::cout << std::max(0, std::min(l, n - r - 1)) << '\n';
  }
  return 0;
}