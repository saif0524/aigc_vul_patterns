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
vector<pair<int, int> > v;
int comparar(double i, double j) {
  if (j - i > 1e-07) return -1;
  if (i - j > 1e-07) return 1;
  return 0;
}
int main() {
  int n, V;
  scanf("%d %d", &n, &V);
  v.clear();
  v.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i].first);
  for (int i = 0; i < n; i++) scanf("%d", &v[i].second);
  double a, b, min;
  a = v[0].second;
  b = a / v[0].first;
  min = b;
  for (int i = 1; i < n; i++) {
    a = v[i].second;
    b = a / v[i].first;
    if (comparar(b, min) < 0) min = b;
  }
  double vRes = 0;
  double vMax = V;
  for (int i = 0; i < n; i++) vRes += (min * v[i].first);
  if (comparar(vRes, vMax) < 0)
    printf("%.5lf\n", vRes);
  else
    printf("%.5lf\n", vMax);
}