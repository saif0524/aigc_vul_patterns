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
int p;
int ask(int x, int y) {
  if (p > 0) swap(x, y);
  cout << "? " << x << " " << y << "\n";
  cin >> x;
  if (p > 0) x = -x;
  return x;
}
int main() {
  ((void)0);
  p = ask(0, 0);
  int X = 0, Y = 0;
  for (int i = 29; i >= 0; --i) {
    int x = ask(X ^ (1 << i), Y ^ (1 << i));
    if (x == 0) {
      if (p > 0) swap(X, Y), p = 0;
      for (; i >= 0; --i) {
        cout << "? " << (X ^ (1 << i)) << " " << Y << "\n";
        cin >> x;
        if (x < 0) X ^= (1 << i), Y ^= (1 << i);
      }
      break;
    }
    if (x > 0) {
      Y ^= (1 << i);
      if (ask(X, Y) > 0) {
        swap(X, Y);
        p *= (-1);
      }
      continue;
    }
    if (ask(X ^ (1 << i), Y) < 0) X ^= (1 << i), Y ^= (1 << i);
  }
  if (p > 0) swap(X, Y);
  cout << "! " << X << " " << Y;
}