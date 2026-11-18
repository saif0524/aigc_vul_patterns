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
const int maxs = 200000;
const char dbuf[] = "DWAS";
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
char s[maxs + 1];
int xv[maxs + 1];
int yv[maxs + 1];
int lprv[maxs + 1];
int bprv[maxs + 1];
int rprv[maxs + 1];
int tprv[maxs + 1];
int lnxt[maxs + 1];
int bnxt[maxs + 1];
int rnxt[maxs + 1];
int tnxt[maxs + 1];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int TN = 0; TN < T; TN++) {
    cin >> s;
    int n = strlen(s);
    xv[0] = 0;
    yv[0] = 0;
    for (int i = 0; i < n; i++) {
      int d = find(dbuf, dbuf + 4, s[i]) - dbuf;
      xv[i + 1] = xv[i] + dx[d];
      yv[i + 1] = yv[i] + dy[d];
    }
    lprv[0] = rprv[0] = xv[0];
    bprv[0] = tprv[0] = yv[0];
    for (int i = 1; i <= n; i++) {
      lprv[i] = min(lprv[i - 1], xv[i]);
      bprv[i] = min(bprv[i - 1], yv[i]);
      rprv[i] = max(rprv[i - 1], xv[i]);
      tprv[i] = max(tprv[i - 1], yv[i]);
    }
    lnxt[n] = rnxt[n] = xv[n];
    bnxt[n] = tnxt[n] = yv[n];
    for (int i = n - 1; i >= 0; i--) {
      lnxt[i] = min(lnxt[i + 1], xv[i]);
      bnxt[i] = min(bnxt[i + 1], yv[i]);
      rnxt[i] = max(rnxt[i + 1], xv[i]);
      tnxt[i] = max(tnxt[i + 1], yv[i]);
    }
    long long ans = 0x7f7f7f7f7f7f7f7fll;
    for (int i = 0; i <= n; i++) {
      for (int d = 0; d < 4; d++) {
        int w =
            max(rprv[i], rnxt[i] + dx[d]) - min(lprv[i], lnxt[i] + dx[d]) + 1;
        int h =
            max(tprv[i], tnxt[i] + dy[d]) - min(bprv[i], bnxt[i] + dy[d]) + 1;
        ans = min(ans, (long long)w * h);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}