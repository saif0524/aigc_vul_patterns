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
char s[5205][1305];

bool check(int x) {
  for (int i = 0; i < n; i += x) {
    for (int j = 0; j < n; j += x) {
      int val = -1;
      for (int k = i; k < i + x; k++) {
        for (int l = j; l < j + x; l++) {
          int idx = (k * n + l) / 4;
          int pos = (k * n + l) % 4;
          int bit = (s[k][idx] - '0');
          if (pos >= 10) bit = (s[k][idx] - 'A' + 10);
          if ((bit >> (3 - pos)) & 1) {
            if (val == 0) return false;
            val = 1;
          } else {
            if (val == 1) return false;
            val = 0;
          }
        }
      }
      if (val == -1) val = 0;
      for (int k = i; k < i + x; k++) {
        for (int l = j; l < j + x; l++) {
          int idx = (k * n + l) / 4;
          int pos = (k * n + l) % 4;
          int bit = (s[k][idx] - '0');
          if (pos >= 10) bit = (s[k][idx] - 'A' + 10);
          if ((bit >> (3 - pos)) & 1) {
            if (val != 1) return false;
          } else {
            if (val != 0) return false;
          }
        }
      }
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = n / 4; i >= 1; i--) {
    if (n % i == 0 && check(i)) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}