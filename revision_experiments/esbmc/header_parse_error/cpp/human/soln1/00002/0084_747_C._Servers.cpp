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
int en[100 + 100];
int e[100 + 100];
int main() {
  int n, q;
  while (~scanf("%d%d", &n, &q)) {
    memset(en, -1, sizeof(en));
    memset(e, -1, sizeof(e));
    for (int i = 1; i <= q; i++) {
      int T, K, D;
      scanf("%d%d%d", &T, &K, &D);
      int ans = 0;
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (en[i] == -1 || en[i] < T) {
          cnt++;
          e[i] = T + D - 1;
          ans += i;
          if (cnt == K) break;
        }
      }
      if (cnt == K) {
        for (int i = 1; i <= n; i++) en[i] = e[i];
        printf("%d\n", ans);
      } else {
        for (int i = 1; i <= n; i++) e[i] = en[i];
        printf("-1\n");
      }
    }
  }
  return 0;
}