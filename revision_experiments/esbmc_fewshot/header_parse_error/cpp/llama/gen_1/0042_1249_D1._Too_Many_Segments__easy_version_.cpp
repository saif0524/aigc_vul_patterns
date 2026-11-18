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

const int MAXN = 205;
const int MAXM = 205;

int n, k;
int l[MAXN], r[MAXN];
int cnt[MAXN];
int dp[MAXN][MAXN];
bool used[MAXN];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = l[i]; j <= r[i]; j++) {
      cnt[j]++;
    }
  }
  for (int i = 1; i <= MAXM; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = n + 1;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= MAXM; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (cnt[i] > k) {
        for (int x = 1; x <= n; x++) {
          if (l[x] <= i && r[x] >= i && !used[x]) {
            used[x] = true;
            dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
            used[x] = false;
          }
        }
      }
    }
  }
  int ans = n + 1;
  for (int i = 0; i <= n; i++) {
    if (dp[MAXM][i] < ans) {
      ans = dp[MAXM][i];
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= MAXM; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = n + 1;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= MAXM; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (cnt[i] > k) {
        for (int x = 1; x <= n; x++) {
          if (l[x] <= i && r[x] >= i && !used[x]) {
            used[x] = true;
            dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
            used[x] = false;
          }
        }
      }
    }
  }
  vector<int> res;
  int x = MAXM, y = ans;
  while (x > 0 && y > 0) {
    if (dp[x][y] != dp[x - 1][y]) {
      for (int i = 1; i <= n; i++) {
        if (l[i] <= x && r[i] >= x && !used[i]) {
          used[i] = true;
          res.push_back(i);
          y--;
          break;
        }
      }
    }
    x--;
  }
  for (int i = 0; i < res.size(); i++) {
    if (i) cout << " ";
    cout << res[i];
  }
  cout << endl;
  return 0;
}