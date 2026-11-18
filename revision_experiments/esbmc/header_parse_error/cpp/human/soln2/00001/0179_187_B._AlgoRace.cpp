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
int dp[60][60][1001] = {{{0}}}, adj[60][60][60] = {{{0}}};
int n, m, r;
void input() {
  scanf(" %d %d %d", &n, &m, &r);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) dp[i][j][0] = 100000000;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        int temp;
        scanf(" %d", &temp);
        adj[i][j][k] = temp;
      }
    }
    for (int p = 0; p < n; p++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          adj[i][j][k] = min(adj[i][j][k], adj[i][j][p] + adj[i][p][k]);
        }
      }
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dp[j][k][0] = min(dp[j][k][0], adj[i][j][k]);
      }
    }
  }
  for (int k = 1; k <= 1000; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j][k] = dp[i][j][k - 1];
        for (int p = 0; p < n; p++)
          dp[i][j][k] = min(dp[i][j][k], dp[i][p][k - 1] + dp[p][j][0]);
      }
    }
  }
}
int main() {
  input();
  for (int i = 0; i < r; i++) {
    int s, t, k;
    scanf(" %d %d %d", &s, &t, &k);
    printf("%d\n", dp[s - 1][t - 1][k]);
  }
  return 0;
}