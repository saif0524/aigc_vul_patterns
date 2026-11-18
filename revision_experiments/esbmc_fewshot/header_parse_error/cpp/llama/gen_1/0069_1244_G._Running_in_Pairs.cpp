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
  int n, k;
  cin >> n >> k;
  int sum = (n * (n + 1)) / 2;
  if (sum > k) {
    cout << -1 << endl;
    return 0;
  }
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
    b[i] = i + 1;
  }
  int l = 0, r = n - 1;
  while (l < r) {
    swap(b[l], b[r]);
    l++;
    r--;
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}