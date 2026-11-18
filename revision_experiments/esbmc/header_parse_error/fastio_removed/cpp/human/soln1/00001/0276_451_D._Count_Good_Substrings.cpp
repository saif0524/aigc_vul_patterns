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
const long long INF = 1e18;
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  ((void)0);
  string s;
  cin >> s;
  int n = s.size();
  long long b_odd = 0, b_even = 0;
  long long a_odd = 0, a_even = 0;
  long long res = 0, reso = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2) {
      if (s[i] == 'a')
        a_odd++, res += a_even, reso += a_odd;
      else
        b_odd++, res += b_even, reso += b_odd;
    } else {
      if (s[i] == 'a')
        a_even++, res += a_odd, reso += a_even;
      else
        b_even++, res += b_odd, reso += b_even;
    }
  }
  cout << res << ' ' << reso << '\n';
}