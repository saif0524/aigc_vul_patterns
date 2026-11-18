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
typedef long long int ll;
#define FOR(i, a, b) for (ll i = (signed)(a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define EREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define MOD 1000000007
#define pb push_back
#define INF 93193111451418101
#define MIN -93193111451418101
#define EPS 1e-11
#define lb(a, b) lower_bound((a).begin(), (a).end(), (b))
#define ub(a, b) upper_bound((a).begin(), (a).end(), (b))
#define bitcnt(a) (ll) __builtin_popcount((a))
using namespace std;
typedef pair<ll, ll> P;
typedef pair<ll, P> TP;
template <typename T> void fill_all(T &arr, const T &v) { arr = v; }
template <typename T, typename ARR> void fill_all(ARR &arr, const T &v) {
  for (auto &i : arr) {
    fill_all(i, v);
  }
}
//------------------変数-----------------------//

//-------------------関数----------------------//
ll h, w, grid[200][200], dp[500][200][200];
ll p[] = {1, 0, 0, 1, 1, 1, 0, 0};
int main() {
  cin >> h >> w;
  REP(i, h) {
    REP(j, w) { cin >> grid[i][j]; }
  }
  REP(i, h + w - 2) {
    REP(X, min(w, i + 1)) {
      REP(x, min(w, i + 1)) {
        if (h <= i - X || h <= i - x)
          continue;
        ll y = i - x, Y = i - X, cost = grid[Y][X] + grid[y][x];
        // cost -= (X == x && grid[y][x]);
        cost -= (X == x ? grid[y][x] : 0);
        REP(k, 4) {
          dp[i + 1][X + p[k * 2]][x + p[k * 2 + 1]] = max(
              dp[i + 1][X + p[k * 2]][x + p[k * 2 + 1]], cost + dp[i][X][x]);
        }
      }
    }
  }
  cout << dp[h + w - 2][w - 1][w - 1] + grid[h - 1][w - 1] << endl;
}