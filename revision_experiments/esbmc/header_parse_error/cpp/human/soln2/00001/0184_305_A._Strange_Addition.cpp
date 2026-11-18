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
int vis[111];
int a[111];
int main() {
  int i, j, n;
  int v;
  while (scanf("%d", &n) != EOF) {
    memset(vis, -1, sizeof(vis));
    int flag = 0;
    int tt = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &v);
      if (v == 100)
        vis[1] = 100;
      else if (v == 0)
        vis[4] = 0;
      else if (v < 10)
        vis[3] = v;
      else {
        if (!flag) {
          if (v % 10 == 0) {
            vis[2] = v;
            flag = 1;
          } else
            vis[2] = v;
        }
      }
    }
    int tot = 0;
    if (vis[1] != -1) {
      a[++tt] = 100;
    }
    if (vis[4] != -1) {
      a[++tt] = 0;
    }
    if (vis[3] != -1 && vis[2] != -1) {
      if (vis[2] % 10 == 0) {
        tot = 1;
        a[++tt] = vis[3];
        a[++tt] = vis[2];
      }
    }
    if (!tot) {
      if (vis[3] != -1)
        a[++tt] = vis[3];
      else if (vis[2] != -1)
        a[++tt] = vis[2];
    }
    printf("%d\n", tt);
    for (i = 1; i <= tt; i++) printf("%d ", a[i]);
    if (tt > 0) printf("\n");
  }
  return 0;
}