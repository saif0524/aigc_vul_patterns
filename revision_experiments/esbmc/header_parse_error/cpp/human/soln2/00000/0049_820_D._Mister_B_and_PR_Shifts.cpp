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
const int maxn = 1e6 + 5;
int cf[maxn];
int p[maxn];
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  int L = 0, R = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    if (p[i] <= i)
      R++;
    else
      L++;
    cf[(p[i] + n - i) % n]++;
    sum += abs(p[i] - i);
  }
  long long ans = sum;
  int op = 0;
  for (int i = 1; i < n; i++) {
    sum = sum - L;
    sum = sum + R - 1;
    sum = sum - abs(p[n - i + 1] - n) + abs(p[n - i + 1] - 1);
    L = L - (cf[i] - 1);
    R = R + (cf[i] - 1);
    if (ans > sum) {
      ans = sum;
      op = i;
    }
  }
  printf("%lld %d\n", ans, op);
  return 0;
}