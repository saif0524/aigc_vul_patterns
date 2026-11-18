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
const int N = 50, M = 5e4 + 5;
int n, a[N], ans, sum;
bool dp[N][N * M];
char pos[N][N * M];
bool used[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  sum -= a[n - 2] + a[n - 1];
  n -= 2;
  dp[0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j - 1 >= 0; j--) {
      for (int s = a[i]; s <= sum; s++) {
        if (dp[j - 1][s - a[i]] == true && dp[j][s] == false) {
          dp[j][s] = true;
          pos[j][s] = i;
        }
      }
    }
  }
  int ans = sum / 2;
  while (dp[n / 2][ans] == false) {
    ans += 1;
  }
  for (int i = n / 2; i >= 1; i--) {
    used[pos[i][ans]] = true;
    ans -= a[pos[i][ans]];
  }
  cout << a[n] << " ";
  for (int i = n - 1; i >= 0; i--) {
    if (used[i] == true) {
      cout << a[i] << " ";
    }
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    if (used[i] == false) {
      cout << a[i] << " ";
    }
  }
  cout << a[n + 1];
}