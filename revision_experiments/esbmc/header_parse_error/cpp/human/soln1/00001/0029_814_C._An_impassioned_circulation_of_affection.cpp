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
const int N = 1500 + 10;
char s[N];
int n, q, a[N];
int memo[N][30];
int solve(int x, int c) {
  int j = 0, miss = 0, ret = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != c && j < i) miss++, j = i;
    while (j + 1 <= n && (a[j + 1] == c || miss + 1 <= x)) {
      j++;
      if (a[j] != c) miss++;
    }
    if (miss <= x) ret = max(ret, j - i + 1);
    if (a[i] != c) miss--;
  }
  return ret;
}
int main() {
  scanf("%d%s%d", &n, s, &q);
  for (int i = 0; i < n; i++) a[i + 1] = (int)(s[i] - 'a');
  memset(memo, -1, sizeof memo);
  while (q--) {
    int x, c;
    char ch[2];
    scanf("%d %s", &x, ch);
    c = (int)(ch[0] - 'a');
    if (memo[x][c] == -1) memo[x][c] = solve(x, c);
    printf("%d\n", memo[x][c]);
  }
  return 0;
}