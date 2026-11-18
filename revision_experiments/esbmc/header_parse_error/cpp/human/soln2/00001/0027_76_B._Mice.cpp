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
int ches[100010];
int mice[100010];
int n, m;
int main() {
  int i, x, y, j;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for (i = 0; i < n; i++) {
    scanf("%d", &mice[i]);
  }
  for (j = 0; j < m; j++) {
    scanf("%d", &ches[j]);
  }
  int last = -1, res = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    while (j < m && abs(mice[i] - ches[j]) > abs(mice[i] - ches[j + 1])) {
      j++;
    }
    if (j != last || abs(mice[i] - ches[j]) == abs(mice[i - 1] - ches[j])) {
      last = j;
      res++;
    } else if (j + 1 < m &&
               abs(mice[i] - ches[j]) == abs(mice[i] - ches[j + 1])) {
      res++;
      last = ++j;
    } else {
      last = j;
    }
  }
  printf("%d", n - res);
}