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
const double eps = (1e-9);
using namespace std;
int dcmp(long double a, long double b) {
  return fabsl(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
int getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
int setBit1(int num, int idx) { return num | (1 << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
void M() {
  ((void)0);
  ((void)0);
  ((void)0);
}
int countNumBit1(int mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1);
    ++ret;
  }
  return ret;
}
long long arr[300009], even[300009], odd[300009];
vector<int> v, sum;
int fun(long long no) {
  int cnt = 0;
  while (no) {
    cnt += (no % 2);
    no /= 2;
  }
  return cnt;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    int cnt = fun(arr[i]);
    v.push_back(cnt);
  }
  sum.resize(n);
  sum[0] = v[0];
  for (int i = 1; i < ((int)(v).size()); i++) sum[i] = sum[i - 1] + v[i];
  even[0] = (sum[0] % 2 == 0);
  odd[0] = (sum[0] % 2 != 0);
  for (int i = 1; i < n; i++) {
    even[i] = even[i - 1] + (sum[i] % 2 == 0);
    odd[i] = odd[i - 1] + (sum[i] % 2 != 0);
  }
  long long add = 1;
  long long rem = 0, ans = 0, res = 0;
  for (int i = 0; i < n; i++) {
    if (rem % 2 == 0) {
      res += even[n - 1] - even[i + 1 - 1];
    } else {
      res += odd[n - 1] - odd[i + 1 - 1];
    }
    rem += v[i];
    int mx = v[i], s = v[i];
    for (int j = i + 1, k = 0; j < n && k < 65; j++, k++) {
      mx = max(mx, v[j]);
      s += v[j];
      if (s - mx < mx && s % 2 == 0) res--;
    }
  }
  cout << res << endl;
}