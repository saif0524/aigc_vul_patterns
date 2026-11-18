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
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T>
T maxm(T a, T b) {
  return a > b ? a : b;
}
template <class T>
T minm(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T abs(T a) {
  return a > 0 ? a : (-1) * a;
}
template <class T>
T sq(T a) {
  return a * a;
}
char s[200005];
int main() {
  int n, f = 0, in = 0, a = 0;
  char ch;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%c", &ch);
    if (ch == 'A')
      a++;
    else if (ch == 'F')
      f++;
    else
      in++;
  }
  if (in == 1)
    cout << 1;
  else if (in > 1)
    cout << 0;
  else if (in == 0)
    cout << a;
  return 0;
}