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
int n;
long long b[30];
string s;
int mod;
int memo[602222][76];
long long solve(int mask, int i) {
  if (i == n) {
    for (int j = 0; j < 30; j++) {
      if (mask == b[j]) {
        return 1;
      }
    }
    return 0;
  }
  int &ret = memo[mask][i];
  if (ret != -1) return ret;
  int sum = 0;
  for (int j = 0; j < 75; j++) {
    if (i + j <= n) {
      int num = 0;
      for (int k = 0; k < j; k++) {
        num = num * 2 + (s[i + k] - '0');
        if (num > 20) break;
      }
      num -= 1;
      if (num <= 18 && num >= 0) {
        sum += solve(mask | (1 << num), i + j);
        sum %= mod;
        if (i + j != n) sum += solve(mask | (1 << num), n);
      }
      sum = sum % mod;
    }
  }
  ret = sum;
  return sum;
}
int main() {
  memset(memo, -1, sizeof(memo));
  mod = 1e9 + 7;
  for (int j = 0; j < 30; j++) {
    b[j] = (1 << (j + 1)) - 1;
  }
  cin >> n >> s;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += solve(0, i);
    sum %= mod;
  }
  cout << sum << endl;
}