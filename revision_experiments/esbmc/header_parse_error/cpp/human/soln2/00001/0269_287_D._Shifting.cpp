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
const int inf = 0x3fffffff;
const long long mod = 1000000007;
const int maxn = 20 + 10;
deque<int> dq;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) dq.push_back(i);
  for (int i = 2; i < n + 1; i++) {
    for (int j = (n - 1) / i; j > 0; j--) swap(dq[(j - 1) * i], dq[j * i]);
    dq.push_back(dq.front());
    dq.pop_front();
  }
  for (int i = 0; i < n; i++) printf("%d ", dq[i]);
  return 0;
}