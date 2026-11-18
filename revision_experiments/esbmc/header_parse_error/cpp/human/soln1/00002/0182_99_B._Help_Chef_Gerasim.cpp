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
  int n, f = 1, a, b, m;
  pair<int, int> r[1010];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r[i].first;
    r[i].second = i + 1;
  }
  sort(r, r + n);
  for (int i = 1; i < n - 2; i++)
    if (r[i].first != r[i + 1].first) {
      f = 0;
      break;
    }
  if (n == 1 | f && r[0].first == r[n - 1].first &&
      r[n - 2].first == r[n - 1].first)
    cout << "Exemplary pages.\n";
  else if (f && (n == 2 && (r[0].first + r[n - 1].first) % 2 == 0 ||
                 r[n - 1].first + r[0].first == 2 * r[n - 2].first)) {
    m = r[n - 1].first - r[0].first;
    a = r[0].second;
    b = r[n - 1].second;
    cout << m / 2 << " ml. from cup #" << a << " to cup #" << b << ".\n";
  } else
    cout << "Unrecoverable configuration.\n";
}