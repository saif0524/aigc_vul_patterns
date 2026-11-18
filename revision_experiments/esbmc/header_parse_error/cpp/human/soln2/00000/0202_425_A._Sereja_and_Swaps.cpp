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
int num[210], a[205], b[205], c[205];
int main() {
  int n, k, i, j, ans, result;
  while (scanf("%d %d", &n, &k) != EOF) {
    result = -999999999;
    for (i = 0; i < n; i++) scanf("%d", &num[i]);
    for (i = 0; i < n; i++) {
      for (j = i; j < n; j++) {
        int tt = 0, ttt = 0;
        ans = 0;
        for (int m = 0; m < n; m++) {
          if (m <= j && m >= i)
            a[tt++] = num[m];
          else
            b[ttt++] = num[m];
        }
        sort(a, a + tt);
        sort(b, b + ttt);
        int Min = min(k, min(tt, ttt));
        int mm = 0;
        for (int m = 0; m < Min; m++) {
          c[mm++] = a[m];
          c[mm++] = b[ttt - 1 - m];
        }
        sort(c, c + mm);
        for (int m = mm - 1; m >= mm - Min; m--) ans += c[m];
        for (int m = Min; m < tt; m++) ans += a[m];
        result = max(result, ans);
      }
    }
    printf("%d\n", result);
  }
  return 0;
}