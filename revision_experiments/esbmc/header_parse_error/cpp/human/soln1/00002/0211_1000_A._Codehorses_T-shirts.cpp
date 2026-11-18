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
const int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const double PI = acos(-1);
const double EPS = 10e-9;
const int e4 = 1e4 + 5;
const int e5 = 1e5 + 5;
const int e6 = 1e6 + 5;
map<string, int> m;
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    m[str]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (m[str] != 0) {
      m[str]--;
    } else {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}