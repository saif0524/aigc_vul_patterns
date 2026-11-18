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
const int MAXN = 100005;
const int MAXM = 2005;
int N, M;
int mon[MAXN];
int cell[MAXM];
int start[MAXN];
int use[MAXN];
int dp[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> mon[i];
  for (int i = 0; i < M; i++) cin >> cell[i];
  sort(mon, mon + N);
  sort(cell, cell + M);
  for (int i = 0; i < N; i++) {
    if (i == 0 || mon[i] != mon[i - 1] + 1)
      start[i] = i;
    else
      start[i] = start[i - 1];
  }
  for (int i = 0; i < N; i++) {
    int next = upper_bound(cell, cell + M, mon[i]) - cell;
    if (start[i] > 0) use[i] = max(use[i], dp[start[i] - 1]);
    if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    for (int j = next - 1; j >= 0; j--) {
      int left = i - (mon[i] - cell[j]);
      if (left < 0) break;
      use[i] = max(use[i], dp[start[left] - 1] + next - j);
    }
    for (int j = next; j < M; j++) {
      int right = i + (cell[j] - mon[i]);
      if (right >= N) break;
      dp[right] = max(dp[right], use[i] + j - next + 1);
    }
    dp[i] = max(dp[i], use[i]);
  }
  cout << dp[N - 1] << "\n";
  return 0;
}