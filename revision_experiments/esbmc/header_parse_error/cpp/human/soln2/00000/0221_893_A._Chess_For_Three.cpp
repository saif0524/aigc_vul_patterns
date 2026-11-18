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
int ifa[4] = {0, 1, 1, 0};
int b[4] = {0, 0, 0, 0};
int main(void) {
  int n, flag = 1, spec = 3, lose = 2;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int winner;
    scanf("%d", &winner);
    memset(b, 0, sizeof(b));
    b[winner] = 1;
    b[spec] = 1;
    for (int i = 1; i <= 3; i++)
      if (b[i] == 0) lose = i;
    if (ifa[winner]) {
      ifa[spec] = 1;
      ifa[lose] = 0;
      int tem = lose;
      lose = spec;
      spec = tem;
    } else {
      flag = 0;
      break;
    }
  }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}