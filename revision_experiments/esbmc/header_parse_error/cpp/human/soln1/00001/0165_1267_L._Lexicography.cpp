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
char S[1000002];
char D[1000002];
char R[1002][1002];
void mS(char s[], char d[], int o, int t) {
  int i, j, k;
  int c = o + t >> 1;
  if (o < c) {
    mS(d, s, o, c);
  }
  if (c + 1 < t) {
    mS(d, s, c + 1, t);
  }
  i = o;
  j = c + 1;
  k = o;
  while (i <= c && j <= t) {
    if (s[i] < s[j]) {
      d[k] = s[i];
      i++;
    } else {
      d[k] = s[j];
      j++;
    }
    k++;
  }
  while (i <= c) {
    d[k] = s[i];
    i++;
    k++;
  }
  while (j <= t) {
    d[k] = s[j];
    j++;
    k++;
  }
}
int main() {
  int i, j;
  int a;
  int t;
  int n, l, k;
  int temp;
  int C;
  scanf("%d %d %d", &n, &l, &k);
  scanf("%s", &S);
  for (i = 0; S[i]; i++) {
    D[i] = S[i];
  }
  mS(S, D, 0, i - 1);
  for (i = 1; i <= n; i++) {
    for (j = 0; j < l; j++) {
      R[i][j] = '*';
    }
  }
  t = k - 1;
  C = k;
  for (i = 0; i < l; i++) {
    for (a = 0; a < C; a++) {
      R[k - a][i] = D[t - a];
    }
    temp = 1;
    for (a = 1; a < C; a++) {
      if (D[t] == D[t - a]) {
        temp++;
      } else {
        break;
      }
    }
    for (a = 0; a < C; a++) {
      D[t - a] = '*';
    }
    C = temp;
    t += C;
  }
  t = 0;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < l; j++) {
      if (R[i][j] == '*') {
        while (D[t] == '*') {
          t++;
        }
        R[i][j] = D[t];
        t++;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    R[i][l] = '\0';
  }
  for (i = 1; i <= n; i++) {
    printf("%s\n", R[i]);
  }
  return 0;
}