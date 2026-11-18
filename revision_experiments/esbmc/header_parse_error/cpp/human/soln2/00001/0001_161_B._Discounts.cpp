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
  int k, n;
  scanf("%d%d", &n, &k);
  vector<int> a(n), b(n), distributed(n), p(n);
  vector<vector<int> > cart(k);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    distributed[i] = 0;
    p[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[p[i]] < a[p[j]]) {
        swap(p[i], p[j]);
      }
    }
  }
  int cart_ptr = 0;
  for (int i = 0; i < n && cart_ptr < k; ++i) {
    if (b[p[i]] == 1) {
      distributed[p[i]] = 1;
      cart[cart_ptr].push_back(p[i]);
      ++cart_ptr;
    }
  }
  deque<int> available;
  for (int i = 0; i < n; ++i) {
    if (!distributed[p[i]]) {
      available.push_back(p[i]);
    }
  }
  while (cart_ptr < k) {
    cart[cart_ptr].push_back(available.front());
    available.pop_front();
    ++cart_ptr;
  }
  while (!available.empty()) {
    cart[k - 1].push_back(available.front());
    available.pop_front();
  }
  long long ans = 0;
  for (int i = 0; i < k; ++i) {
    int min_cost = 2000000000;
    for (int j = 0; j < (int)cart[i].size(); ++j) {
      ans += a[cart[i][j]] * 2;
      min_cost = min(min_cost, a[cart[i][j]]);
    }
    if (b[cart[i][0]] == 1) {
      ans -= min_cost;
    }
  }
  cout << ans / 2;
  if (ans % 2 == 0) {
    cout << ".0" << endl;
  } else {
    cout << ".5" << endl;
  }
  for (int i = 0; i < k; ++i) {
    cout << cart[i].size();
    for (int j = 0; j < (int)cart[i].size(); ++j) {
      cout << ' ' << cart[i][j] + 1;
    }
    cout << endl;
  }
  return 0;
}