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
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
inline int nxt() {
  int wow;
  scanf("%d", &wow);
  return wow;
}
inline long long int lxt() {
  long long int wow;
  scanf("%lld", &wow);
  return wow;
}
inline double dxt() {
  double wow;
  scanf("%lf", &wow);
  return wow;
}
int main() {
  int n = nxt(), h = 0, ans = INT_MAX;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'H') h++;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = i; j < i + h; j++)
      if (s[j % n] == 'T') cnt++;
    ans = min(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}