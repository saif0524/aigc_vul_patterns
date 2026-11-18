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
long long int n, m, g, ara[100002], dp[100002][101], sum[100002], dist[100002];
long long int cost(int i, int j) {
  return (ara[j]) * (j - i + 1) - (sum[j] - sum[i - 1]);
}
void rec(int g, int l, int r, int kl, int kr) {
  if (l > r) return;
  int mid = (l + r) / 2;
  dp[mid][g] = 1111111111111111111ll;
  int bestk = -1;
  for (int i = kl; i <= kr; i++) {
    if (i > mid) break;
    long long int now = dp[i][g - 1] + cost(i + 1, mid);
    if (now < dp[mid][g]) {
      dp[mid][g] = now;
      bestk = i;
    }
  }
  rec(g, l, mid - 1, kl, bestk);
  rec(g, mid + 1, r, bestk, kr);
}
int main(int argc, char const *argv[]) {
  ((void)0);
  cin >> n >> m >> g;
  for (int i = 2; i <= n; i++) {
    cin >> dist[i];
    dist[i] = dist[i] + dist[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    long long int hi, ti;
    cin >> hi >> ti;
    ara[i] = ti - dist[hi];
  }
  sort(ara + 1, ara + m + 1);
  for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + ara[i];
  for (int i = 1; i <= m; i++) dp[i][1] = cost(1, i);
  for (int i = 2; i <= g; i++) {
    rec(i, 1, m, 1, m);
  }
  cout << dp[m][g] << endl;
  return 0;
}