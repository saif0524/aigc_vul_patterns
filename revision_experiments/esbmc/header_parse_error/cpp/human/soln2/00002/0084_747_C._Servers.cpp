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
struct Server {
  bool is_free;
  int free_at;
  Server(int t, int d, bool isf) {
    is_free = isf;
    free_at = t + d;
  }
  Server() : Server(0, 0, true) {}
};
int n, q;
Server ss[105];
int read() {
  if (scanf("%d %d", &n, &q) < 2) {
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    ss[i] = Server();
  }
  return 1;
}
void solve() {
  int init_t, need_free, dur;
  for (int qq = 0; qq < q; qq++) {
    scanf("%d %d %d", &init_t, &need_free, &dur);
    int have_free = 0;
    for (int i = 1; i <= n; i++) {
      if (ss[i].is_free || ss[i].free_at <= init_t) have_free++;
    }
    if (need_free <= have_free) {
      int sum = 0;
      for (int i = 1; i <= n; i++) {
        if (need_free > 0 && (ss[i].is_free || ss[i].free_at <= init_t)) {
          ss[i] = Server(init_t, dur, false);
          sum += i;
          need_free--;
        }
      }
      printf("%d\n", sum);
    } else {
      printf("-1\n");
    }
  }
}
int main(int argc, char *argv[]) {
  while (read()) {
    solve();
  }
}