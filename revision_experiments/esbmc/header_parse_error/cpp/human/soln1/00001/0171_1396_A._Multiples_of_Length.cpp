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
long long ara[100005];
long long aa[100005], bb[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", ara + i);
  if (n == 1) {
    printf("1 1\n%lld\n", -ara[1]);
    printf("1 1\n0\n");
    printf("1 1\n0\n");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    long long x = ara[i];
    long long rem = (-x) % n;
    rem += n, rem %= n;
    rem = (n - rem) % n;
    long long b = rem;
    long long a = (b - x) / n - b;
    aa[i] = a * n, bb[i] = b * (n - 1);
  }
  printf("%d %d\n", 1, n);
  for (int i = 1; i <= n; i++) printf("%lld ", aa[i]);
  printf("\n");
  printf("%d %d\n", 1, n - 1);
  for (int i = 1; i < n; i++) printf("%lld ", bb[i]);
  printf("\n");
  printf("%d %d\n", n, n);
  printf("%lld\n", -ara[n]);
  return 0;
}