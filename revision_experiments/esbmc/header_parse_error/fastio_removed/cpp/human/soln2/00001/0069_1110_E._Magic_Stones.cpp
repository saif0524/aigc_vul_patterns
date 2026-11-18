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
int main(void) {
  ((void)0);
  ((void)0);
  ((void)0);
  int n;
  cin >> n;
  vector<int> c(n), t(n);
  for (auto &x : c) cin >> x;
  for (auto &x : t) cin >> x;
  vector<int> v1, v2;
  for (int i = 1; i < n; i++) {
    v1.emplace_back(c[i] - c[i - 1]);
  }
  for (int i = 1; i < n; i++) {
    v2.emplace_back(t[i] - t[i - 1]);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  bool check = true;
  if (c[0] != t[0]) check = false;
  if (c[n - 1] != t[n - 1]) check = false;
  for (int i = 0; i < v1.size(); i++) {
    if (v1[i] != v2[i]) check = false;
  }
  if (check)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}