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
int main() {
  int n;
  char ar[200000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long int a;
    scanf("%I64d", &a);
    ar[i] = a > 0 ? 1 : -1;
  }
  long long pluses = 0;
  long long minuses = 0;
  long long prevP = -1;
  long long prevM = -1;
  for (int i = 0; i < n; i++) {
    if (prevP == -1) {
      prevP = ar[i] == -1 ? 0 : 1;
      prevM = 1 - prevP;
      minuses += prevM;
      pluses += prevP;
      continue;
    }
    if (ar[i] == -1) {
      minuses += prevP + 1;
      pluses += prevM;
      int temp = prevM;
      prevM = prevP + 1;
      prevP = temp;
    }
    if (ar[i] == 1) {
      minuses += prevM;
      pluses += prevP + 1;
      prevM = prevM;
      prevP = prevP + 1;
    }
  }
  printf("%I64d %I64d", minuses, pluses);
  return 0;
}