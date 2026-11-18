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
int in() {
  int a;
  scanf("%d", &a);
  return a;
}
int gcm(int a, int b) {
  if (b > a) return gcm(b, a);
  if (a % b == 0)
    return b;
  else
    return gcm(b, a % b);
}
int calc_rev(int x) {
  int ret = 0;
  while (x) {
    int a = x % 10;
    ret = ret * 10 + a;
    x /= 10;
  }
  return ret;
}
int rev[100010];
map<pair<int, int>, vector<int> > lucky;
pair<int, int> a_reva(int a) {
  int g = gcm(a, rev[a]);
  int b = a / g;
  int c = rev[a] / g;
  return make_pair(b, c);
}
pair<int, int> invert_pint(pair<int, int> t) {
  return make_pair(t.second, t.first);
}
int main() {
  for (int i = (1); i <= (100000); i++) {
    rev[i] = calc_rev(i);
  }
  for (int i = (1); i <= (100000); i++) {
    lucky[a_reva(i)].push_back(i);
  }
  pair<int, int> ans = make_pair(-1, -1);
  long long ans_fact = ((long long)(1001001001) * (1001001001));
  int maxx = in();
  int maxy = in();
  int w = in();
  int bar = maxy;
  int ltickets = 0;
  for (int x = (1); x <= (maxx); x++) {
    vector<int> hoge = lucky[invert_pint(a_reva(x))];
    int ind =
        distance(hoge.begin(), upper_bound(hoge.begin(), hoge.end(), bar));
    ltickets += ind;
    while (ltickets >= w) {
      if ((long long)x * bar < ans_fact) {
        ans = make_pair(x, bar);
        ans_fact = (long long)x * bar;
      }
      vector<int> fuga = lucky[invert_pint(a_reva(bar))];
      int ind2 =
          distance(fuga.begin(), upper_bound(fuga.begin(), fuga.end(), x));
      ltickets -= ind2;
      bar--;
    }
  }
  if (ans.first == -1) {
    puts("-1");
  } else {
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}