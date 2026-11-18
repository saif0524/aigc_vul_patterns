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
const int N = 100100;
int m[N];
int a[N];
int level[N];
long long sums[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }
  sums[0] = 0;
  for (int i = 1; i < N; ++i) {
    sums[i] = i + sums[i - 1];
  }
  long long marks = 0;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    if (m[i] + 1 > marks) {
      marks = m[i] + 1;
    }
    level[i] = marks;
  }
  int currently_building = level[n - 1];
  for (int i = n - 1; i >= 0; --i) {
    currently_building = max(currently_building, level[i]);
    a[i] = currently_building;
    currently_building--;
    sum += a[i] - 1 - m[i];
  }
  cout << sum;
  return 0;
}