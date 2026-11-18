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
int s[50];
char a[55][55];
int main() {
  int n, i, j, c = 1, k, found;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", a[i]);
    int l = strlen(a[i]);
    for (j = 0; j < l; j++) {
      s[a[i][j] - 'a']++;
    }
  }
  for (i = 0; i < 26; i++) {
    if (s[i] == 0) {
      printf("%c", (char)(i + 'a'));
      c = 1;
      break;
    } else
      c = 2;
  }
  if (c == 2) {
    for (i = 0; i < 26; i++) {
      for (j = 0; j < 26; j++) {
        char str[4];
        found = 0;
        str[0] = (char)(i + 'a');
        str[1] = (char)(j + 'a');
        for (k = 0; k < n; k++) {
          int l = strlen(a[k]), x = 0;
          while (x < (l - 1)) {
            if (a[k][x] == str[0] && a[k][x + 1] == str[1]) {
              found = 1;
              break;
            } else
              x++;
          }
          if (found == 1) break;
        }
        if (found == 0) {
          printf("%c%c\n", str[0], str[1]);
          c = 3;
          break;
        }
      }
      if (c == 3) break;
    }
  }
  return 0;
}