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
using ll = long long;
using namespace std::chrono;
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  ll inf = 1100000000;
  ll n;
  cin >> n;
  int pro = 1;
  ll pos = 1;
  ll neg = 0;
  for (int i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    if (temp < 0) pro *= -1;
    if (pro < 0)
      neg++;
    else
      pos++;
  }
  ll x = neg * pos;
  ll val = (n * (n + 1));
  cout << x << ' ' << val / 2 - (x) << endl;
  return 0;
}