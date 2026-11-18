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
  int a, b, c, d, i, j, k, m, n, v;
  cin >> n;
  int A[n];
  cin >> A[0];
  if (A[0] > 15) {
    cout << 15;
    return (0);
  }
  for (j = 1; j < n; j++) {
    cin >> A[j];
  }
  for (i = 1; i < n; i++) {
    if ((A[i] - A[i - 1]) > 15) {
      cout << A[i - 1] + 15;
      return (0);
    }
  }
  if (90 - A[n - 1] > 15)
    cout << A[n - 1] + 15;
  else
    cout << 90;
  return (0);
}