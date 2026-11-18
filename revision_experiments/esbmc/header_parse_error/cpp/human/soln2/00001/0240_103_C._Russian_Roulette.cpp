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
char judge(long long n, long long k, long long pos) {
  pos = n - pos + 1;
  char ans = 0;
  if (k <= 1) {
    if (k == 0)
      ans = '.';
    else if (pos != 1)
      ans = '.';
    else
      ans = 'X';
  } else if ((n & 1) && n / 2 >= k) {
    if (pos <= 2)
      ans = 'X';
    else if (pos > (k - 1) * 2)
      ans = '.';
    else if (pos & 1)
      ans = '.';
    else
      ans = 'X';
  } else {
    if (n / 2 >= k) {
      if (pos >= 2 * k)
        ans = '.';
      else if (pos & 1)
        ans = 'X';
      else
        ans = '.';
    } else {
      long long rem = k - (n + 1) / 2;
      if (pos <= rem * 2 + 1)
        ans = 'X';
      else if ((pos & 1) ^ (n & 1))
        ans = 'X';
      else
        ans = '.';
    }
  }
  return ans;
}
int main() {
  long long n, k;
  int p;
  while (cin >> n >> k >> p) {
    string s;
    for (int i = 0, _n(p); i < _n; ++i) {
      long long pos;
      cin >> pos;
      s += (judge(n, k, pos));
    }
    cout << s << endl;
  }
  return 0;
}