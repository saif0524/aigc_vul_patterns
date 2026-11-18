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
int p, n;
bool build(string& in, int i) {
  bool gg = 0;
  for (char v = in[i] + 1; v <= p; ++v) {
    if ((i - 1 < 0 || in[i - 1] != v) && (i - 2 < 0 || in[i - 2] != v)) {
      gg = true;
      in[i] = v;
      break;
    }
  }
  if (gg) {
    bool can = true;
    for (int j = i + 1; j < n; ++j) {
      can = false;
      for (char v = 'a'; v <= p; ++v) {
        if ((j - 1 < 0 || in[j - 1] != v) && (j - 2 < 0 || in[j - 2] != v)) {
          can = true;
          in[j] = v;
          break;
        }
      }
      if (!can) {
        break;
      }
      if (j + 1 == n) {
        cout << in << endl;
        return 0;
      }
    }
    if (can) {
      cout << in << endl;
      return 0;
    }
  }
  return 1;
}
int main() {
  ((void)0);
  cin >> n >> p;
  p += 'a' - 1;
  string in;
  cin >> in;
  for (int i = n; i-- > 0;) {
    if (!build(in, i)) {
      return 0;
    }
  }
  cout << "NO" << endl;
}