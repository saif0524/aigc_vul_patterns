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
int n, all;
int t[2100], c[2100];
long long f[5000], answer = 1e18 + 1;
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%d%d", &t[i], &c[i]);
    ++t[i];
    all = max(all, t[i]);
  }
  all += n;
  for (register int i = 1; i <= all; i++) f[i] = 1e18 + 1;
  for (register int i = 1; i <= n; i++)
    for (register int j = all; j >= t[i]; j--)
      f[j] = min(f[j], f[j - t[i]] + c[i]);
  for (register int i = n; i <= all; i++) answer = min(answer, f[i]);
  cout << answer;
  return 0;
}