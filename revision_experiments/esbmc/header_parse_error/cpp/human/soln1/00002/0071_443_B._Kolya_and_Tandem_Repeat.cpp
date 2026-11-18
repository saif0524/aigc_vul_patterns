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
inline int input() {
  int ret = 0;
  bool isN = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') isN = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return isN ? -ret : ret;
}
inline void output(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int len = 0, data[10];
  while (x) {
    data[len++] = x % 10;
    x /= 10;
  }
  if (!len) data[len++] = 0;
  while (len--) putchar(data[len] + 48);
  putchar('\n');
}
const int MAXN = 1010;
char s[MAXN];
int k;
inline void in() { scanf("%s%d", s, &k); }
inline bool ok(int st, int ans) {
  int nxt = st + ans;
  int j = nxt;
  while (st < j && nxt < strlen(s)) {
    if (s[st] != s[nxt]) return 0;
    st++, nxt++;
  }
  return 1;
}
inline void work() {
  int l = strlen(s);
  if (k >= l) {
    printf("%d\n", (k + l) / 2 * 2);
  } else {
    int ans, tag = 0;
    for (ans = (k + l) / 2; ans >= 1; ans--) {
      for (int i = 0; i + ans * 2 - 1 < (k + l); i++) {
        if (ok(i, ans)) {
          tag = 1;
          break;
        }
      }
      if (tag) break;
    }
    printf("%d\n", ans * 2);
  }
}
int main() {
  in();
  work();
  return 0;
}