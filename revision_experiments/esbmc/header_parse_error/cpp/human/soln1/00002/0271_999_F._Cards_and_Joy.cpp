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
int n, k;
int joy[15];
int dp[505][5005];
int solve(int play, int cards) {
  for (int i = 0; i <= play; i++)
    for (int j = 0; j <= cards; j++) dp[i][j] = 0;
  for (int i = 1; i <= play; i++)
    for (int j = 1; j <= cards; j++)
      for (int l = 1; l <= min(k, j); l++)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + joy[l]);
  return dp[play][cards];
}
int main() {
  int x;
  cin >> n >> k;
  unordered_map<int, int> c, f;
  for (int i = 0; i < n * k; i++) {
    cin >> x;
    c[x]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    f[x]++;
  }
  for (int i = 1; i <= k; i++) cin >> joy[i];
  joy[0] = 0;
  int ans = 0;
  for (auto it = f.begin(); it != f.end(); it++) {
    ans += solve(it->second, min(k * (it->second), c[it->first]));
  }
  cout << ans << endl;
  return 0;
}