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
  string s;
  cin >> s;
  int l = s.length();
  int i;
  int a = 0;
  int b = 0;
  int c = 0;
  for (i = 0; i < l; i += 2) {
    if (s[i] == '1') {
      a++;
    } else if (s[i] == '2') {
      b++;
    } else {
      c++;
    }
  }
  for (i = 0; i < a; i++) {
    if ((b != 0) || (c != 0)) {
      cout << "1+";
    } else {
      if (i == (a - 1)) {
        cout << "1";
      } else {
        cout << "1+";
      }
    }
  }
  for (i = 0; i < b; i++) {
    if (c != 0) {
      cout << "2+";
    } else {
      if (i == (b - 1)) {
        cout << "2";
      } else {
        cout << "2+";
      }
    }
  }
  for (i = 0; i < c; i++) {
    if (i == (c - 1)) {
      cout << "3";
    } else {
      cout << "3+";
    }
  }
}