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
map<int, int> mp;
set<int> st;
int a[500005], mark[500005];
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int pos = n - 1;
  for (i = n / 2 - 1; i >= 0; i--) {
    if (a[i] * 2 <= a[pos]) {
      mark[i] = 1;
      pos--;
    }
    if (pos <= (n / 2 - 1)) {
      break;
    }
  }
  int cnt = 0;
  for (i = 0; i < n; i++) {
    if (mark[i] == 1) {
      cnt++;
    }
  }
  cnt = n - cnt;
  printf("%d\n", cnt);
  return 0;
}