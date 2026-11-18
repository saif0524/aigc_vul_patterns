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
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1000000007;
const int MAXN = 10010;
int ans[MAXN];
int c[MAXN];
int n, m, d;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> d;
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
    sum += c[i];
  }
  int i = 0, j = 1;
  int space = d - 1;
  int can = n - sum;
  while (i < n and (j <= m or (space > 0 and can > 0))) {
    if (space > 0 and can > 0) {
      ans[i++] = 0;
      space--;
      can--;
    } else if (c[j] > 0) {
      ans[i++] = j;
      c[j]--;
    } else {
      space = d - 1;
      j++;
    }
  }
  if (i < n) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << '\n';
  return 0;
}