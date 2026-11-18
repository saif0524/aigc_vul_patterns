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
const int MAXA = 5005;
const int MAXN = 2016;
int array[MAXN]{};
long long diffr[MAXA]{};
long long suffx[MAXA]{};
long double total;
long long Ans = 0;
int N;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d", &array[i]);
  total = N * (N - 1) >> 1;
  std::sort(array, array + N);
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j) ++diffr[array[j] - array[i]];
  for (int i = 5000; i >= 0; --i) suffx[i] = suffx[i + 1] + diffr[i];
  for (int i = 1; i <= 5000; ++i)
    for (int j = 1; i + j <= 5000; ++j)
      Ans += diffr[i] * diffr[j] * suffx[i + j + 1];
  std::cout << std::setprecision(9) << Ans / total / total / total << '\n';
  return 0;
}