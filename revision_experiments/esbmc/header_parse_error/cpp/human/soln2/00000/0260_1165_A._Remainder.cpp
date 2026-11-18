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
  int n, x, y, k = 0;
  cin >> n >> x >> y;
  string a;
  cin >> a;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  string b = "";
  for (int i = a.size() - x; i < a.size(); i++) {
    b += a[i];
  }
  reverse(b.begin(), b.end());
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == '1' && i != y) k++;
    if (b[i] == '0' && i == y) k++;
  }
  cout << k;
  return 0;
}