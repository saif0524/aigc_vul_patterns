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
#pragma GCC optimize("O3")
const long long int mod = 1e9 + 7;
const int N = 1000005;
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  ((void)0);
  int n, x, y;
  cin >> n >> x >> y;
  int cntx = 0, cnty = 0;
  vector<string> ans;
  while (cntx < x || cnty < y) {
    double a = (double)(1 + cntx) / x, b = (double)(1 + cnty) / y;
    if (a < b) {
      ans.push_back("Vanya");
      cntx++;
    } else if (a > b) {
      ans.push_back("Vova");
      cnty++;
    } else {
      ans.push_back("Both");
      ans.push_back("Both");
      cntx++;
      cnty++;
    }
  }
  long long int q;
  for (int i = 0; i < n; i++) {
    cin >> q;
    q %= (x + y);
    if (q == 0) q = x + y;
    cout << ans[q - 1] << endl;
  }
}