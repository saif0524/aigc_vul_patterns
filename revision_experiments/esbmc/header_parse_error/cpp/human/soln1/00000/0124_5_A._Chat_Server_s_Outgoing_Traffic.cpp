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
  int m = 0, a = 0;
  for (int i = 0; i < 100; i++) {
    string s;
    getline(cin, s);
    if (s[0] == '+') {
      m++;
      continue;
    }
    if (s[0] == '-') {
      m--;
      continue;
    }
    int c = 1;
    int t = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == ':' && c == 1) {
        c = 0;
        continue;
      }
      if (c == 0) {
        a += (s.size() - j) * m;
        break;
      }
    }
  }
  cout << a;
  return 0;
}