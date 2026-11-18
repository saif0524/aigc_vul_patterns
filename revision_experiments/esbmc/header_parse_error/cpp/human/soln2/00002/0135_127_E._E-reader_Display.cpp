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
const int oo = 0x7f7f7f7f;
const int Max = 2048;
char mp[Max][Max];
char F[Max];
int N;
int color() {
  int cnt = 0;
  memset(F, 0, sizeof(F[0]) * N);
  for (int i = 0; i < N; i++) {
    int c = 0;
    for (int j = N - 1; j > i; j--) {
      mp[i][j] ^= c ^ F[j];
      if (mp[i][j]) {
        ++cnt;
        mp[i][j] ^= 1;
        c ^= 1;
        F[j] ^= 1;
      }
    }
    mp[i][i] ^= c ^ F[i];
  }
  return cnt;
}
int main() {
  while (scanf("%d", &N) != EOF) {
    for (int i = 0; i < N; i++) {
      scanf("%s", mp[i]);
      for (int j = 0; j < N; j++) mp[i][j] -= '0';
    }
    int Res = color();
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++) swap(mp[i][j], mp[j][i]);
    Res += color();
    for (int i = 0; i < N; i++) Res += mp[i][i];
    printf("%d\n", Res);
  }
  return 0;
}