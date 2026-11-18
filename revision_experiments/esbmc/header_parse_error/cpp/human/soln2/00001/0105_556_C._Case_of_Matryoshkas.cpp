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
int v[100010];
int n, k;
int main() {
  cin >> n >> k;
  int solution = 0;
  for (int i = 1; i <= k; i++) {
    int m;
    cin >> m;
    for (int j = 1; j <= m; j++) cin >> v[j];
    int j;
    if (v[1] == 1) {
      j = 2;
      while (v[j] == v[j - 1] + 1) j++;
      for (; j <= m; j++) {
        solution += 2;
      }
      continue;
    }
    for (j = 1; j <= m; j++)
      if (j == 1)
        solution++;
      else
        solution += 2;
  }
  cout << solution << "\n";
  return 0;
}