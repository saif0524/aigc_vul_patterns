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
int a[110];
int b[110];
int main() {
  string s;
  getline(cin, s);
  int num = 0, ten = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '=') break;
    if (s[i] <= '9' && s[i] >= '0') {
      int x = s[i] - '0';
      num += x * ten;
      ten *= 10;
    }
  }
  int cnt = 0;
  a[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+') {
      a[++cnt] = 1;
    } else if (s[i] == '-') {
      a[++cnt] = 0;
    }
  }
  int x = 0;
  for (int i = 0; i <= cnt; i++) {
    b[i] = 1;
    if (a[i])
      x += b[i];
    else
      x -= b[i];
  }
  x = num - x;
  for (int i = 0; i <= cnt; i++) {
    if (x < 0) {
      if (a[i] == 0 && b[i] < num) {
        int k = min(num - b[i], -x);
        b[i] += k;
        x += k;
      }
    } else if (x > 0) {
      if (a[i] == 1 && b[i] < num) {
        int k = min(num - b[i], x);
        b[i] += k;
        x -= k;
      }
    } else
      break;
  }
  x = 0;
  for (int i = 0; i <= cnt; i++) {
    if (a[i])
      x += b[i];
    else
      x -= b[i];
  }
  if (x != num) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+' || s[i] == '-' || s[i] == '=') {
      cout << b[cnt++] << " " << s[i] << " ";
    }
  }
  cout << num << endl;
  return 0;
}