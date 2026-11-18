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
int b[102];
int g[102];
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> g[i];
  }
  sort(b, b + n);
  sort(g, g + m);
  int itb, itg;
  itb = itg = 0;
  int cnt = 0;
  while (itb < n && itg < m) {
    if (abs(b[itb] - g[itg]) <= 1) {
      cnt++, itb++, itg++;
      continue;
    }
    if (b[itb] < g[itg])
      itb++;
    else
      itg++;
  }
  cout << cnt;
  return 0;
}