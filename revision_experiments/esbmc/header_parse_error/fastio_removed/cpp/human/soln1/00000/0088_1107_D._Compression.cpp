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
const int maxn = 5205;
int n;
int sum[maxn][maxn];
char a;
char cs[] = "0123456789ABCDEF";
map<char, int> cidic;
void init() {
  for (int i = 0; i < 16; i++) {
    cidic[cs[i]] = i;
  }
}
void update(int i, int j) {
  sum[i][j] += (i > 0 ? sum[i - 1][j] : 0) + (j > 0 ? sum[i][j - 1] : 0) -
               (i > 0 && j > 0 ? sum[i - 1][j - 1] : 0);
}
bool check(int k) {
  for (int i = 0; i < n; i += k) {
    for (int j = 0; j < n; j += k) {
      int c_sum = sum[i + k - 1][j + k - 1] -
                  (j > 0 ? sum[i + k - 1][j - 1] : 0) -
                  (i > 0 ? sum[i - 1][j + k - 1] : 0) +
                  (i > 0 && j > 0 ? sum[i - 1][j - 1] : 0);
      if (c_sum != 0 && c_sum != k * k) return false;
    }
  }
  return true;
}
int main() {
  ((void)0);
  ((void)0);
  cin >> n;
  init();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 4; j++) {
      cin >> a;
      int ms = cidic[a];
      sum[i][j * 4] = (ms >> 3) & 1;
      update(i, j * 4);
      sum[i][j * 4 + 1] = (ms >> 2) & 1;
      update(i, j * 4 + 1);
      sum[i][j * 4 + 2] = (ms >> 1) & 1;
      update(i, j * 4 + 2);
      sum[i][j * 4 + 3] = ms & 1;
      update(i, j * 4 + 3);
    }
  }
  int k = 1;
  while (k != n && !check(n / k)) {
    k++;
    while (n % k != 0) {
      k++;
    }
  }
  cout << n / k << endl;
  return 0;
}