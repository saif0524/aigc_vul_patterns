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

const int N = 5005;

int n;
char s[N];

int main() {
  scanf("%s", s);
  n = strlen(s);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int k = (j - i + n) % n;
      bool ok2 = true;
      for (int l = 0; l < n; l++) {
        if (s[l] != s[(l + k) % n]) {
          ok2 = false;
          break;
        }
      }
      if (ok2) {
        ok = false;
        break;
      }
    }
    if (ok) cnt++;
  }
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    int cnt2 = 0;
    for (int j = 0; j < n; j++) {
      bool ok = true;
      for (int k = 0; k < n; k++) {
        if (j == k) continue;
        int l = (k - j + n) % n;
        bool ok2 = true;
        for (int p = 0; p < n; p++) {
          if (s[p] != s[(p + l) % n]) {
            ok2 = false;
            break;
          }
        }
        if (ok2) {
          ok = false;
          break;
        }
      }
      if (ok) cnt2++;
    }
    ans += (double)cnt2 / n;
  }
  printf("%.12lf\n", ans / n);
  return 0;
}