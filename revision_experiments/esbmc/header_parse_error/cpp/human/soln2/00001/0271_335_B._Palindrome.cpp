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
int n, t, a[35];
int dp[2605][2605];
char s[50005], res[2605];
int rec(int x, int y) {
  if (x > y) return 0;
  if (dp[x][y]) return dp[x][y];
  if (x == y) return dp[x][y] = 1;
  if (s[x] == s[y]) return dp[x][y] = rec(x + 1, y - 1) + 2;
  return dp[x][y] = max(rec(x + 1, y), rec(x, y - 1));
}
void trace(int x, int y) {
  if (x > y) return;
  if (x == y)
    res[t++] = s[x];
  else if (s[x] == s[y]) {
    res[t++] = s[x];
    trace(x + 1, y - 1);
    res[t++] = s[y];
  } else {
    if (dp[x + 1][y] < dp[x][y - 1])
      trace(x, y - 1);
    else
      trace(x + 1, y);
  }
}
int main() {
  scanf("%s", s), n = strlen(s);
  if (n >= 2600) {
    for (int i = (0); i < (n); i++) ++a[s[i] - 'a'];
    for (int i = (0); i < (26); i++)
      if (a[i] >= 100) {
        for (int j = (0); j < (100); j++) printf("%c", i + 'a');
        puts("");
        return 0;
      }
  } else {
    rec(0, n - 1);
    t = 0;
    trace(0, n - 1);
    if (t <= 100)
      printf("%s\n", res);
    else {
      for (int i = (0); i < (50); i++) printf("%c", res[i]);
      for (int i = (t - 50); i < (t); i++) printf("%c", res[i]);
      puts("");
    }
  }
  return 0;
}