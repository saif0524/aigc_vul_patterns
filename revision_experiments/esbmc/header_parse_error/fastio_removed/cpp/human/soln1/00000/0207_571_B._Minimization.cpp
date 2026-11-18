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
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll inf = 1E17;
const ll mod = 1;
ll a[300010];
int n, k, chnk;
ll dp[5001][5001];
ll solve(int pos, int xtra, int l) {
  if (pos == 0) {
    if (xtra == 0) return 0;
    return inf;
  }
  ll &ret = dp[pos][xtra];
  if (ret != -1) return ret;
  ret = a[l + chnk - 1] - a[l] + solve(pos - 1, xtra, l + chnk);
  if (xtra)
    ret = min(ret, a[l + chnk] - a[l] + solve(pos - 1, xtra - 1, l + chnk + 1));
  return ret;
}
int main() {
  ((void)0);
  while (cin >> n >> k) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof dp);
    chnk = n / k;
    cout << solve(k, n % k, 1) << endl;
  }
  return 0;
}