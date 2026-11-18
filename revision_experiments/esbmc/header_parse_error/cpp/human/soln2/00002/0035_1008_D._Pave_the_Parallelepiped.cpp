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
const int N = 1e5 + 10;
int n;
int cnt[N];
int ans = 0;
inline int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
int main() {
  for (int i = 1; i <= 100000; i++) {
    for (int j = 1; j * j <= i; j++)
      if (i % j == 0) {
        cnt[i] += 2;
        if (j * j == i) cnt[i]--;
      }
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int ab = GCD(a, b);
    int bc = GCD(b, c);
    int ac = GCD(a, c);
    int abc = GCD(ab, bc);
    int ans = cnt[a] * cnt[b] * cnt[c];
    ans -= cnt[a] * (cnt[bc] - 1) * cnt[bc] / 2;
    ans -= cnt[b] * (cnt[ac] - 1) * cnt[ac] / 2;
    ans -= cnt[c] * (cnt[ab] - 1) * cnt[ab] / 2;
    ans += cnt[abc] * (cnt[abc] - 1);
    ans += cnt[abc] * (cnt[abc] - 1) * (cnt[abc] - 2) * 4 / 6;
    ans += (cnt[ab] - cnt[abc]) * (cnt[abc] - 1) * cnt[abc] / 2;
    ans += (cnt[bc] - cnt[abc]) * (cnt[abc] - 1) * cnt[abc] / 2;
    ans += (cnt[ac] - cnt[abc]) * (cnt[abc] - 1) * cnt[abc] / 2;
    ans -= (cnt[ab] - cnt[abc]) * (cnt[bc] - cnt[abc]) * (cnt[ac] - cnt[abc]);
    cout << ans << endl;
  }
}