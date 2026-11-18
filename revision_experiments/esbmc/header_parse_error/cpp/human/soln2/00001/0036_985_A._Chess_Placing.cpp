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
int a[110];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n / 2; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n / 2 + 1);
    for (int i = 1; i <= n / 2; i++) {
      ans1 += abs(i * 2 - 1 - a[i]);
      ans2 += abs(i * 2 - a[i]);
    }
    printf("%d\n", min(ans1, ans2));
  }
  return 0;
}