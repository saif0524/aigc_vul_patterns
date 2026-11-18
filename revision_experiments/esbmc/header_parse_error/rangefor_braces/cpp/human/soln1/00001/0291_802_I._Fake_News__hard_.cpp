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
const int N = 200500;
struct state {
  int len, link;
  map<char, int> next;
};
state st[N];
int sz, last;
void sa_init() {
  last = st[0].len = 0;
  sz = 1;
  st[0].link = -1;
}
void sa_extend(char c) {
  int k = sz++, p;
  st[k].len = st[last].len + 1;
  for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
    st[p].next[c] = k;
  if (p == -1)
    st[k].link = 0;
  else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len)
      st[k].link = q;
    else {
      int w = sz++;
      st[w].len = st[p].len + 1;
      st[w].next = st[q].next;
      st[w].link = st[q].link;
      for (; p != -1 && st[p].next[c] == q; p = st[p].link) st[p].next[c] = w;
      st[q].link = st[k].link = w;
    }
  }
  last = k;
}
string s;
long long dp[N];
bool t[N];
long long f(int i) {
  if (dp[i] != -1) return dp[i];
  long long &r = dp[i] = t[i];
  for (auto p : st[i].next) { r += f(p.second); }
  return r;
}
void solve() {
  sa_init();
  memset(dp, -1, sizeof dp);
  for (int i = 0, qwerty = ((int)(s).size()); i < qwerty; i++) sa_extend(s[i]);
  int x = last;
  while (x) {
    t[x] = 1;
    x = st[x].link;
  }
  f(0);
  long long r = 0;
  for (int i = 1, qwerty = sz; i < qwerty; i++)
    r += f(i) * f(i) * (st[i].len - st[st[i].link].len);
  while (last) {
    t[last] = 0;
    last = st[last].link;
  }
  for (int i = 0, qwerty = sz; i < qwerty; i++) st[i].next.clear();
  cout << r << "\n";
}
int main() {
  ((void)0);
  ((void)0);
  ((void)0);
  int tn;
  cin >> tn;
  for (int i = 0, qwerty = tn; i < qwerty; i++) {
    cin >> s;
    solve();
  }
}