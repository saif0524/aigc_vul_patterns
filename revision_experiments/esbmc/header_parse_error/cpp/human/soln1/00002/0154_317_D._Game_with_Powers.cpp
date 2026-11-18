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
const int sq = 40 * 1000;
bool used[sq + 1];
const int G[30] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5,
                   9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
int main() {
  int n;
  cin >> n;
  int res = 0;
  int after_sq = 0;
  for (int i = 1; i <= sq; ++i) {
    if (used[i]) {
      continue;
    }
    int cnt = i == 1;
    for (long long j = i; i != 1 && j <= n; j *= i) {
      if (j <= sq) {
        used[j] = true;
      } else {
        ++after_sq;
      }
      ++cnt;
    }
    res ^= G[cnt];
  }
  res ^= (n > sq ? (n - sq - after_sq) : 0) & 1;
  if (res) {
    cout << "Vasya\n";
  } else {
    cout << "Petya\n";
  }
  return 0;
}