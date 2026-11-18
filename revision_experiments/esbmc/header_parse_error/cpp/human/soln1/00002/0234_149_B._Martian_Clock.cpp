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
vector<int> a, b, v;
string s;
bool ok(int p) {
  bool f = true;
  for (int i = 0; i < a.size(); i++) {
    f &= a[i] < p;
  }
  for (int i = 0; i < b.size(); i++) {
    f &= b[i] < p;
  }
  long long h, m;
  h = m = 0;
  for (int i = 0; i < a.size(); i++) {
    h *= p;
    h += a[i];
  }
  for (int i = 0; i < b.size(); i++) {
    m *= p;
    m += b[i];
  }
  return f && (m < 60) && (h < 24);
}
int main() {
  cin >> s;
  int i = 0;
  while (s[i] != ':') {
    if (s[i] >= '0' && s[i] <= '9') {
      a.push_back(s[i] - '0');
    } else {
      a.push_back(s[i] - 'A' + 10);
    }
    i++;
  }
  s.erase(s.begin(), s.begin() + s.find(':') + 1);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      b.push_back(s[i] - '0');
    } else {
      b.push_back(s[i] - 'A' + 10);
    }
  }
  if (ok(60)) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 2; i < 60; i++) {
    if (ok(i)) {
      v.push_back(i);
    }
  }
  if (v.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  cout << v[0];
  for (int i = 1; i < v.size(); i++) {
    cout << ' ' << v[i];
  }
  cout << endl;
  return 0;
}