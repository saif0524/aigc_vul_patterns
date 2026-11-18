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
#pragma GCC optimize("O3")
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar((x % 10) + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int oo = 0x3f3f3f3f;
const int inf = oo;
bitset<100005> f[26], ans;
char s[100005], ch[100005];
int n, Q;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) s[i] -= 'a', f[s[i]][i] = 1;
  Q = read();
  while (Q--) {
    int op = read();
    if (op == 1) {
      int pos = read(), ch = getchar();
      f[s[pos]][pos] = 0;
      s[pos] = ch - 'a';
      f[s[pos]][pos] = 1;
    } else {
      int l = read(), r = read();
      scanf("%s", ch);
      int len = strlen(ch);
      if (r - l + 1 < len) {
        puts("0");
        continue;
      }
      ans.set();
      ans <<= (l - 1);
      ans ^= (ans << (r - l + 2 - len));
      for (int i = 0; i < len; i++) ans = (ans << 1) & f[ch[i] - 'a'];
      writeln(ans.count());
    }
  }
  return 0;
}