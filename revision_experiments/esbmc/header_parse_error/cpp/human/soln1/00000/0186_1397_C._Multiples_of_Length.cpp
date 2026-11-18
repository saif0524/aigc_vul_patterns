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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
const int BUBEN = 550;
const int MOD = 1e9 + 7;
const int BASE = 29;
const int MOD1 = 998244353;
const int BASE1 = 31;
char _getchar_nolock() { return getchar_unlocked(); }
char _putchar_nolock(char i) { return putchar_unlocked(i); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << "1 1\n" << -arr[0] << "\n1 1\n0\n1 1\n0";
  } else {
    cout << "1 " << n - 1 << '\n';
    for (int i = 0; i + 1 < n; i++) {
      cout << (n - 1) * (arr[i] % n) << ' ';
      arr[i] += (n - 1) * (arr[i] % n);
    }
    cout << '\n' << n << ' ' << n << '\n';
    cout << n - (arr[n - 1] % n) << '\n';
    arr[n - 1] += n - (arr[n - 1] % n);
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << -arr[i] << ' ';
    }
  }
}