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
int n;
int t[20], r[20], dp[20];
int x, y, z;
int mx, k = 1, a = 1;
int main() {
  cin >> n;
  t[0] = 1, x = n, y = n;
  while (x > 9) {
    t[k] = t[k - 1] * 10;
    x /= 10;
    a += t[k];
    k++;
  }
  for (int i = 0; i < k; i++) {
    z = y % 10;
    r[z] += t[i];
    mx = max(mx, z);
    y /= 10;
  }
  dp[0] = a - r[0];
  cout << mx << endl, cout << dp[0] << " ";
  for (int i = 1; i < mx; i++) {
    dp[i] = dp[i - 1] - r[i];
    cout << dp[i] << " ";
  }
  cout << endl;
}