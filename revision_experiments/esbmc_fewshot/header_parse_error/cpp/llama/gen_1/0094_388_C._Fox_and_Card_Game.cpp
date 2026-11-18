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
  int n;
  cin >> n;
  int a = 0, b = 0;
  vector<vector<int>> v(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    v[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> v[i][j];
    }
  }
  vector<int> mid;
  for (int i = 0; i < n; i++) {
    int k = v[i].size();
    if (k % 2 == 1) {
      mid.push_back(v[i][k / 2]);
    }
  }
  sort(mid.begin(), mid.end(), greater<int>());
  for (int i = 0; i < mid.size(); i += 2) {
    a += mid[i];
  }
  for (int i = 1; i < mid.size(); i += 2) {
    b += mid[i];
  }
  for (int i = 0; i < n; i++) {
    int k = v[i].size();
    for (int j = 0; j < k / 2; j++) {
      a += v[i][j];
    }
    for (int j = k / 2 + (k % 2); j < k; j++) {
      b += v[i][j];
    }
  }
  cout << a << " " << b << endl;
  return 0;
}