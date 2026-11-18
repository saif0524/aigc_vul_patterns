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
const int md = 1010;
int n, ar[md], m;
void oku() {
  scanf(" %d", &n);
  for (int i = 1; i <= n; i++) scanf(" %d", &ar[i]);
  scanf(" %d", &m);
  for (int a, b, i = 1; i <= m; i++) {
    scanf(" %d %d", &a, &b);
    ar[a - 1] += b - 1;
    ar[a + 1] += ar[a] - b;
    ar[a] = 0;
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ar[i]);
}
int main() { oku(); }